#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int MAXN = 500;
// const int MAXN = 2 * 130 + 2;
int n, m, s, t, ans;

struct edge {
    int to, cap, rev;
};


vector<edge> G[MAXN];
// cost: prop的cost
int cost[MAXN], level[MAXN], iter[MAXN], vis[MAXN];

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int) G[to].size()});
    G[to].push_back((edge){from, 0, (int) G[from].size() - 1});
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : G[u]) {
            if (!vis[e.to] && e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
                vis[e.to] = true;
            }
        }
    }
    // return vis[t];
}

int dfs(int u, int t, int f) {
    if (u == t || f == 0) {
        return f;
    }
    int d = 0;
    for (int i = iter[u]; i < (int) G[u].size(); i++) {
        edge &e = G[u][i];
        if (e.cap > 0 && level[u] < level[e.to] && (d = dfs(e.to, t, min(f, e.cap))) > 0) {
            // int d = dfs(e.to, t, min(f, e.cap));
            // if (d > 0) {
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            if(!e.cap) return d;
            return d;
            // }
        }
        // if (e.cap > 0 && level[u] < level[e.to]) {
        //     int d = dfs(e.to, t, min(f, e.cap));
        //     if (d > 0) {
        //         e.cap -= d;
        //         G[e.to][e.rev].cap += d;
        //         return d;
        //     }
        // }
    }
    // return 0;
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    // while (true) {
    while (true) {
        bfs(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    // int flow=0;
    // while(bfs())
    // {
    //     memset(iter, 0, sizeof(iter));
    //     flow += dfs(s, t,INF);
    // }
    return flow;
}


int main(){
    // n: number of ideas
    // m: number of props
    cin >> n >> m;
    s = 0;
    t = 2*(n + m + 1);
    for (int i = 0; i <=n; ++i){
        vis[i] = false;
    }
    // cout << "n=" << n << ", m=" << m << '\n';
    int p;
    for(int i = 1; i <= n; ++i){
        // number of ideas, the number of props
        cin >> p;
        add_edge(i+m, t, p);// ideal 的profit
        ans += p;
        // cout << "p=" << p << '\n';
        // add_edge(i+n, t, p); 
    }
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
            add_edge(prop, i+m, INF);
            // add_edge(i+m, prop, INF);
            // add_edge(s, i+m, cost[i]);
        }
    }

    // cout << "ans=" << ans << ", max_flow=" << max_flow(s, t) << '\n';
    cout << ans - max_flow(s, t) << '\n';

    return 0;
}