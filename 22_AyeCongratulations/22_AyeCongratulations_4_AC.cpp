#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int MAXN = 500;
// const int MAXN = 2 * 130 + 2;
int n, m, s, t, ans;

struct Edge{
    int next, v, cap, flow;
};


vector<Edge> g;
// 使用vector<int>的話要用fill begin, end來初始化
// 用level取代visited
vector<int> start, level, used; 
int cost[MAXN];
// cost: prop的cost
// int cost[MAXN], level[MAXN], iter[MAXN];
// bool vis[MAXN];


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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // n: number of ideas
    // m: number of props
    cin >> n >> m;
    s = 0;
    t = n + m + 1;
    // cout << "n=" << n << ", m=" << m << '\n';
    int p;
    // g.resize(2*n+1);
    // start.resize(2*n+1);
    // level.resize(2*n+1);
    // used.resize(2*n+1);
    start.resize(t+1);
    level.resize(t+1);
    used.resize(t+1);
    fill(start.begin(), start.end(), -1);
    fill(level.begin(), level.end(), -1);
    fill(used.begin(), used.end(), -1);
    // cout << "start[9]=" << start[9] << ", start[10]=" << start[10] << '\n';
    // for(int i = 0; i <= n; ++i){
    //     vis[i] = false;
    // }
    for(int i = 1; i <= n; ++i){
        // number of ideas, the number of props
        cin >> p;
        add_edge(m+i, t, p);// ideal 的profit
        ans += p;
        // cout << "p=" << p << '\n';
        // add_edge(i+n, t, p); 
    }

    // return 0;
    int c;
    for(int i = 1; i<=m; ++i){
        cin >> c;
        cost[i] = c;
        add_edge(s, i, c);
        // add_edge(i, t, c);
        // ans += c;
    }

    int k;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        // cout << "k=" << k << '\n';
        int prop;
        while (k--){
            cin >> prop;
            prop++;
            // cout << "prop=" << prop << ", i+n=" << i+n << '\n';
            add_edge(prop, m+i, INF);
            // add_edge(i+m, prop, INF);
            // add_edge(s, i+m, cost[i]);
        }
    }
    int mflow = max_flow(s, t);

    // cout << "ans=" << ans << ", max_flow=" << mflow << '\n';
    cout << ans - mflow << '\n';

    return 0;
}