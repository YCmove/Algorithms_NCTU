#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 301
#define MAXM 90001

// Dinic
int n, m, s, t, ans;

struct Edge{
    int next, v, cap, flow;
};


vector<Edge> g;
vector<int> start, level, used; 
int cost[MAXN];


void add_edge(int from, int to, int cap) {
    // cout << "[add_edge] from=" << from << ", to=" << to << ", g.size()=" << g.size() << '\n';
    g.push_back((Edge){start[from], to, cap, 0});
    g.push_back((Edge){start[to], from, 0, 0});
    start[from] = g.size()-2; // u=0, start[u]=0
    // cout << "start[from]=" << start[from] << ", start[to]=" << start[to] << '\n';
    start[to] = g.size()-1; // v=1, start[v]=1
}

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    // cout << "init bfs" << '\n';
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        // cout << "bfs - cur=" << cur << '\n';
        // for (int next: g[cur]){
        for(int i = start[cur]; i != -1; i=g[i].next){ // 往下一點移動
            // cout << "bfs for loop, i=" << i << '\n';
            if (level[g[i].v] == -1 && g[i].flow < g[i].cap){
                level[g[i].v] = level[cur] + 1;
                q.push(g[i].v);
                // cout << "bfs push g[i].v=" << g[i].v << '\n';
            }
        }

    }
    // cout << "bfs final - level[t]=" << level[t] << ", t=" << t << '\n';
    return level[t] != -1;
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = used[v]; i != -1; i=g[i].next){
        int cur = g[i].v;
        if (level[cur] == level[v]+1 && g[i].flow < g[i].cap){
            int z=0;
            if((z = dfs(cur, t, min(f, g[i].cap - g[i].flow))) > 0){
                g[i].flow += z;
                g[i^1].flow -= z;
                return z;
            }
        }
    }

    return 0;
}

int max_flow(int s, int t) {
    int f = 0;
    // cout << "max_flow init" << '\n';
    while(bfs(s, t)){
        // cout << "here" << '\n';
        used = start;
        while(1){
            // cout << "while(1)" << '\n';
            int aug = dfs(s, t, INF);
            f += aug;
            if (!aug) break;
        }
    }
    return f;
}


int main(){
    cin >> n >> m;
    int x, y;
    s = 0;
    t = n-1;
    start.resize(t+1);
    level.resize(t+1);
    used.resize(t+1);
    fill(start.begin(), start.end(), -1);
    fill(level.begin(), level.end(), -1);
    fill(used.begin(), used.end(), -1);

    for (int i=0; i < m; ++i){
        cin >> x >> y;
        // cout << "Reading x=" << x << ", y=" << y << '\n';
        add_edge(x, y, 1);
        add_edge(y, x, 1);
        // if (y == n-1){
        //     add_edge(y, t, 1);
        // } else if(x == n-1){
        //     add_edge(x, t, 1);
        // }
    }


    cout << max_flow(s, t) << '\n';

    return 0;
}