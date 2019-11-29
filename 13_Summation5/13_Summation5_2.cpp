#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < n; ++i)
#define REP(i, n) for(int i=0; i <= n; ++i)
typedef long long ll;

int n;

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

    ll m = -1e12-10;
    ll mr = 0;
    int low_m = 0, high_m = 0;
    int low_r = 0;

    print_arr(arr, n);

    REP(i, n){
        mr += arr[i];
        if (mr > m){
            cout << "--- mr > m ---" << '\n';
            low_m = low_r;
            high_m = i;
            m = mr;
        }else if(mr < 0){
            cout << "--- mr < 0 ---" << '\n';
            mr = 0;
            low_r = i + 1;
        }
        cout << "m=" << m << ", mr=" << mr << ", low_r=" << low_r << ", low_m=" << low_m << 
        ", high_m=" << high_m << '\n';
    }

    cout << low_m << " " << high_m << ", max="<< m << endl;












    // int sum = 0;
    // int best = 0;
    // int x = 0;
    // int y = 0;
    // rep(i, n){
    //     cout << "i=" << i << " / arr[i]=" << arr[i] << " / sum+arr[i]=" << sum+arr[i]<< " / best=" << best << endl;
    //     sum = max(arr[i], sum+arr[i]);
    //     if (sum == arr[i]){
    //         x = i;
    //     }
    //     cout << "x=" << x << " / ";
    //     best = max(best, sum);
    //     if (best == sum){
    //         y = i;
    //     }
    //     cout << "y=" << y << endl;
    // }
    // cout << x << " " << y+1 << endl;
    // cout << best << endl;


    return 0;
}