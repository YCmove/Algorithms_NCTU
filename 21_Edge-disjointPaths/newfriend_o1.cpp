#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int MAXN = 300+1;
const int MAXM = 90001;

vector<int> V[MAXN];
long long cap[MAXN][MAXN];
int padre[MAXN];
int n;

long long bfs(int s, int t) {
    fill(padre, padre + n + 1, -1); ///n
    padre[s] = s;
    queue<pair<int, long long>> cola; ///nodo, flujo
    cola.push({s, INF});       ///infinito
    while (!cola.empty()) {
        int nodo = cola.front().first;
        long long f = cola.front().second;
        cola.pop();
        for (auto v : V[nodo]) {
            // cout << v << "," << padre[v] << "," << cap[nodo][v] << " ";
            if (padre[v] == -1 && cap[nodo][v]) {
                padre[v] = nodo;
                f = min(f, cap[nodo][v]);
                if (v == t) return f;
                cola.push({v, f});
            }
        }
    }
    return 0;
}

long long edmond(int s, int t) {
    long long f = 0, aug = bfs(s, t);
    while (aug) {
        f += aug;
        int nodo = t;
        while (nodo != s) {
            int ant = padre[nodo];
            cap[ant][nodo] -= aug;
            cap[nodo][ant] += aug;
            nodo = ant;
        }
        aug = bfs(s, t);
    }
    return f;
}

int main() {
    int e, a, b;

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        a++;
        b++;
        V[a].push_back(b);
        V[b].push_back(a);
        cap[a][b] = 1;
        cap[b][a] = 1;
    }
    // cin >> p >> q;

    // cout << edmond(0, n-1) << '\n';
    cout << edmond(1, n) << '\n';
    return 0;
}