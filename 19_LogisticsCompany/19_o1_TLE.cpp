#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2004;

int N, M, Q;
int adj[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int a = 0; a < MAXN; a++) {
        std::fill(adj[a], adj[a] + MAXN, 1000000000);
    }

    scanf("%i%i", &N, &M);
    int x, y, r;
    // cout << "N=" << N << ", M=" << M << '\n';
    while (M--) {
        scanf("%i%i%i", &x, &y, &r);
        --x;
        --y;
        adj[x+1][y+1] = r;
    }
    for (int a = 0; a < N; a++) {
        adj[a][a] = 0;
    }
    // return 0;
    for (int k = 0; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    // scanf("%i", &Q);
    int a, b;
    ll cost = 0;
    // bool flag = false;
    // while (Q--) {
    for (int i = 1; i <= N; ++i){
        // scanf("%i%i", &a, &b);
        a = 0;
        b = i;
        --a;
        --b;
        cost += adj[a+1][b+1] + adj[b+1][a+1];
        // cout << "a+1=" << a+1 << ", b+1=" << b+1 << ", adj[a+1][b+1]=" << adj[a+1][b+1] << ", adj[b+1][a+1]=" << adj[b+1][a+1] << '\n';

        // if (adj[a+1][b+1] == 1000000000 || adj[b+1][a+1] == 1000000000) {
        //     // printf("-1\n");
        //     flag = true;
        //     printf("-1\n");
        //     return 0;
        // } 
        
        // else {
        //     // printf("%i\n", cost);
        //     cout << cost << '\n';
        // }
    }

    cout << cost << '\n';
    // if (flag) {
    //     cout << "-1" << '\n';
    // }else{
    //     cout << cost << '\n';
    // }
}