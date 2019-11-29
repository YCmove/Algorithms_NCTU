#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < n; ++i)
#define REP(i, n) for(int i=0; i <= n; ++i)
typedef long long ll;

int n;
int low = 0, high = 0;
// ll sum, maxSum = -10e13;


template<class T> void print_arr(T* arr, int n) {
    for (int i = 0; i < n; ++i){
        // cout << arr[i] << " ";
        cout << arr[i] << " ";
    }
    cout << '\n';
}




int main(){
    cin >> n;
    int a;
    int arr[n];

    rep(i, n){
        cin >> a;
        arr[i] = a;
    }

    ll max_f = INT_MIN, max_e = 0,
        start = 0, end = 0, s = 0;

    rep(i, n){
        max_e += arr[i];
        if (max_f < max_e) {
            max_f = max_e;
            start = s;
            end = i;
        }
        if (max_e < 0) {
            max_e = 0;
            s = i + 1;
        }
    }

    cout << start << " " << end+1 << '\n';

    


    // int dp[n];//dp[i] means the maximum subarray ending with A[i];
    // dp[0] = arr[0];
    // int max_n = dp[0];

    // for(int i = 1; i < n; i++){
    //     dp[i] = arr[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    //     max_n = max(max_n, dp[i]);
    //     // cout << "low=" << low << ", high=" << high << ", max_n=" << max_n << '\n';
    //     if (max_n == dp[i] && arr[i] == dp[i]){
    //         low = i;
    //         high = i;
    //     } else if(max_n == dp[i]){
    //         high = i;
    //     }
    // }

    // print_arr(arr, n);
    // print_arr(dp, n);

    // cout << "low=" << low << ", high=" << high+1 << ", max_n=" << max_n << '\n';
    // cout << low << " " << high+1 << '\n';
    // cout << max_n << '\n';

    // if (low == high) {
    //     cout << low << " " << high+1 << '\n';
    // } else {
    //     cout << low << " " << high << '\n';
    // }

    // ll m = -1e12-10;
    // ll mr = 0;
    // int low_m = 0, high_m = 0;
    // int low_r = 0;

    // print_arr(arr, n);

    // int low = 0, high = 0;

    return 0;
}