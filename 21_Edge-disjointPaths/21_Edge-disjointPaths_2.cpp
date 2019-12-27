#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int MAXN = 300+1;
const int MAXm = 90001;

int n, m;
int s, t;
vector<vector<int> > g;
bool vis[MAXN]; // for spfa
int d[MAXN];// for spfa
// int lev[MAXN];


void spfa(int s){
    // init dist
    for (int i = 0; i < n; ++i){
        d[i] = INF;
        vis[i] = false;
    }
    d[s] = 0;

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = true;
        // cout << "SPFA while - g[u].size()=" << g[u].size() << ", u=" << u << '\n';
        for (int i = 0; i < (int)g[u].size();++i){
            int nei = g[u][i];
            // cout << "nei=" << nei << ", d[nei]=" << d[nei] << ", d[u]=" << d[u] << '\n';
            if (d[nei] > d[u] + 1){
                // cout << "Update d" << '\n';
                d[nei] = d[u] + 1;
            }

            if (!vis[nei]){
                // cout << "Push to q" << '\n';
                q.push(nei);
                // vis[u] = false;
            }
        }
    }
}

void print_d(){
    for(int i=0; i < n; ++i){
        cout << d[i] << ' ';
    }
    cout << '\n';
}

struct Edge{
    int u, v, c, f;
};

struct Dinic{
    vector<Edge> e;
    vector<int> g[MAXN];
    bool vis[MAXN];
    int lev[MAXN];
    int cur[MAXN];

    void init(){
        e.clear();
        for (int i=0; i<n; ++i){
            g[i].clear();
        }
    }

    void addedge(int u, int v, int cap){
        e.push_back((Edge){u, v, cap, 0});
        e.push_back((Edge){v, u, 0, 0});
        g[u].push_back(e.size()-2);
        g[v].push_back(e.size()-1);
    }

    bool bfs(){
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        vis[s] = true;
        lev[s] = 0;
        q.push(s);
        cout << "Strat bfs" << '\n';
        while(!q.empty()){
            int now = q.front();
            q.pop();
            // vis[now] = true;
            cout << "bfs - now=" << now << ", g[now].size()=" << g[now].size() << '\n';
            for (int i =0; i < (int)g[now].size();++i){
                Edge edge = e[g[now][i]];
                int next = edge.v;
                cout << "(" << edge.u << ", " << edge.v << ")"<< " vis[next]=" << vis[next] << ", edge.c=" << edge.c << ", edge.f=" << edge.f << '\n';
                if(!vis[next] && edge.c > edge.f){
                    cout << "add to queue next=" << next << '\n';
                    lev[next] = lev[now] + 1;
                    // if (next == t) return true;
                    q.push(next);
                    vis[next] = true;
                    
                }
            }
        }
        cout << "bfs final t=" << t << ", vis[t]=" << vis[t] << '\n';
        return vis[t];
    }

    int dfs(int now, int aug){
        cout << "Start dfs - now=" << now << ", aug=" << aug << '\n';
        if(now == t || aug == 0){
            cout << "dfs - return aug" << '\n';
            return aug;
        };

        int flow = 0;
        int f;

        for (int & i = cur[now]; i < (int)g[now].size();++i){
            Edge & edge = e[g[now][i]];
            int next = edge.v;
            if(lev[now]+1==lev[next] && (f=dfs(next, min(aug, edge.c - edge.f)))>0){
                e[now].f += f;
                e[g[now][i]^1].f -= f;
                flow += f;
                aug -= f;
                if(!aug)break;
            }

        }
        return flow;
    }

    int maxflow(){
        int flow = 0;
        
        while(bfs()){
            cout << "=======================" << '\n';
            cout << "maxflow while loop" << '\n';
            for (int i =0; i<n; ++i){
                cur[i] = 0;
            }
            flow += dfs(s, INF);
            cout << "flow=" << flow << '\n';
            cout << "=======================" << '\n';
        }
        cout << "Ans MaxFlow=" << flow << '\n';
        return flow;
    }

} dinic;

int main(){
    cin >> n >> m;
    g.clear();
    g.resize(n);
    vector<pair<int, int> > vec;

    int a, b;
    // cout << "a=" << a << ", b=" << b << '\n';
    while (m--){
        cin >> a >> b;

        cout << "a=" << a << ", b=" << b << '\n';
        g[a].push_back(b);
        g[b].push_back(a);
        vec.push_back(make_pair(a, b));
        vec.push_back(make_pair(b, a));
    }
    s=0;
    t=n-1;
    spfa(s);
    // print_d();
    dinic.init();
    for(int i =0; i<(int)vec.size();++i){
        int u = vec[i].first;
        int v = vec[i].second;
        if(d[u] != INF && d[v] != INF && d[u]+1==d[v]){
            cout << "addedge - u=" << u << ", v=" << v << '\n';
            dinic.addedge(u, v, 1);
            dinic.addedge(v, u, 1);
        }
    }
    
    cout << dinic.maxflow() << '\n';

    return 0;
}