// #include <stdio.h>
// #include <vector>
// #include <queue>
// #include <memory.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int const N = 2*1e3 + 2;
int const M = 5*1e5 + 2;
int const K = 1e9 + 2;
int n, m, cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g; // pair 為 neighbor and weight
priority_queue<pair<int, int> > q; // pair 為 weight 和 node
// g, q, cost, vis 都需要初始化

void Dijkstra(int src, int * cost, bool is_back) {
    int v, c;
    
    cost[src] = 0; // src 起始距離為0
    q.push(make_pair(0, src));
    
    while(!q.empty()) {
        v = q.top().second;
        if (v == 0 && is_back){
            // cout << "reach 0" << '\n';
            return;
        };
        c = -q.top().first; // 重要，cost越負代表cost越大
        q.pop();
        
        if(vis[v]) continue;
        vis[v] = true;
        
        for(int i = 0; i < (int)g[v].size(); i++)
        {
            // cout << "Loop Neighbor - g[v][i].first=" << g[v][i].first  << ", g[v][i].second=" << g[v][i].second << ", cost[g[v][i].first]=" << cost[g[v][i].first] << '\n';
            // g[v][i].second + c: 鄰居的weight加上目前node的weight，比較小的話就更新
            if(g[v][i].second + c < cost[g[v][i].first]) {
                cost[g[v][i].first] = g[v][i].second + c;
                // cout << "Update cost - cost[g[v][i].first]=" << cost[g[v][i].first] << '\n';
                q.push(make_pair(-(g[v][i].second + c), g[v][i].first));
            }
        }
    }
}

void init(int * cost){
    
    while(!q.empty()) q.pop(); // 清空queue
    for(int i = 0; i <= n; i++) cost[i] = K; // cost 初始化到最大
    memset(vis, false, sizeof vis); // 初始化visited table to false
    
}

int main() {
    scanf("%d%d", &n, &m);

    // init
    init(cost);
    // g.clear();
    // g.resize(n); // vector<vector<pair<int, int>>>的初始化
    // while(!q.empty()) q.pop(); // 清空queue
    // for(int i = 0; i < n; i++) cost[i] = M; // cost 初始化到最大
    // memset(vis, false, sizeof vis); // 初始化visited table to false
    
    // init
    g.clear();
    g.resize(n+1); // vector<vector<pair<int, int>>>的初始化

    int v, u, c;
    
    while(m--) {
        scanf("%d%d%d", &v, &u, &c);
        // v--; u--;
        // cout << "v=" << v << ", u=" << u << ", c=" << c << '\n';
        g[v].push_back(make_pair(u, c));
    }
    
    ll total = 0;
    // init(cost);
    // cout << " ---------- First Dijkstra(0) ---------- " << "\n";
    Dijkstra(0, cost, false);
    for (int i = 1 ; i<=n; ++i){
        total += cost[i];
    }

    for (int i = 1 ; i<=n; ++i){
        
        // total += o_cost[i];
        // cout << "cost[" << i << "]=" << cost[i] << '\n';

        // cout << " ---------- Second Dijkstra(0) ---------- " << "\n";
        init(cost);
        Dijkstra(i, cost, true);
        total += cost[0];
        // cout << "cost[0]=" << cost[0] << '\n';
    }

    printf("%lld\n", total);

    return 0;
}