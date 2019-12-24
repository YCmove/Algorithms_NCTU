#include <iostream>
#include <queue>
using namespace std;

int ans[501][501];
int dist[501][501];

void bfs(int node, int n) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int visited[n + 2] = {0};

    pq.push({0, node});

    while (!pq.empty()) {

        pair<int, int> x = pq.top();
        pq.pop();

        int c = x.first;
        int u = x.second;

        if (visited[u]) continue;

        visited[u] = 1;
        ans[node][u] = c;

        for (int v = 0; v < n; v++) {
            if (dist[u][v] != 1e9 && !visited[v]) {
                pq.push({max(c, dist[u][v]), v});
            }
        }
    }
}
int main() {

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 1e9;
            ans[i][j] = -1;
        }
        dist[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], c);
    }

    for (int i = 0; i < n; i++) {
        bfs(i, n);
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;

        if (ans[x][y] == -1 || ans[y][x] == -1) {
            cout << -1 << "\n";
        } else {
            cout << max(ans[x][y], ans[y][x]) << "\n";
        }
    }

    // your code goes here
    return 0;
}