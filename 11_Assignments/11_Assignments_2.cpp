#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n;++i)

const int MAXN = 5e4 + 1;
int n, m;

struct Point{
    int points, t;
    // float ratio;
};

// bool comp (const Point a, const Point b){
//     if (a.ratio == b.ratio){
//         return a.points > b.points;
//     }
//     return a.ratio > b.ratio;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int points, t;
    Point arr[n];
    for (int i = 0; i < n;++i) {
        cin >> points >> t;
        arr[i].points = points;
        arr[i].t = t;
        // arr[i].ratio = (float)points / t;
        // cout << "points=" << points << ", t=" << t << ", ratio=" << arr[i].ratio << '\n';
    }

    // sort(arr, arr+n, comp);
    int knapsack[MAXN] = {0};

    rep(i, n){
    // for(int i = 0; i < n; ++i){
        // j > n 至少會大於總jobs數
        for (int j = m; j >= arr[i].t; --j) {
            // cout << "knapsack[j-arr[i].t] = " << knapsack[j-arr[i].t] << ", knapsack[j] = " <<knapsack[j] << '\n';
            if (knapsack[j-arr[i].t] + arr[i].points > knapsack[j]){
                knapsack[j] = knapsack[j-arr[i].t] + arr[i].points;
            }
        }
        // for (int j = arr[i].t; j <= m; ++j) {
        //     if (knapsack[j-arr[i].t] + arr[i].points > knapsack[j]){
        //         knapsack[j] = knapsack[j-arr[i].t] + arr[i].points;
        //     }
        // }

    }
    cout << knapsack[m] << endl;

    return 0;
}
