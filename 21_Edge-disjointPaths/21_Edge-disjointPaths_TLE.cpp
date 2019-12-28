#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 301
#define MAXM 90001
int n, m;
vector<int> adj[MAXN];    // 相鄰矩陣
vector<int> cap[MAXN];    // Capacity
vector<int> parent(MAXN); // Visited

// Edmonds-Karp algorithm
int bfs(int &s, int t) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    parent[s] = -2;
    q.push(make_pair(s, INF));

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            // cout << "next=" << next << '\n';
            if (parent[next] == -1 && cap[cur][next] > 0) {
                parent[next] = cur;
                int f = min(flow, cap[cur][next]);
                if (next == t) return f;
                q.push(make_pair(next, f));
            }
        }
    }
    // return 0;
    return parent[t] > 0;
}

int edmonds_maxflow(int s, int t) {
    int flow = 0;
    int f = 0; // augment
    while ((f = bfs(s, t)) > 0) {
        flow += f;
        int cur = t;
        // 往回走！
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= f;
            cap[cur][prev] += f;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    cin >> n >> m;
    int x, y;
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        adj[i].resize(n);
        cap[i].resize(m);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] = 1;
        cap[y][x] = 1;
    }
    int s = 0;
    int t = n - 1;
    cout << edmonds_maxflow(s, t) << '\n';

    return 0;
}