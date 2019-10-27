#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;


template<class T> void print_vec(T & vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    // cout << "here" << endl;
    cout << endl;
}


template<class T> void print_arr(T* arr, ll n) {
    for (ll i = 0; i < n; ++i){
        cout << arr[i] << " ";
        // cout << "arr[" << i << "]:" << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    ll n;

    while (cin >> n){

        ll arr[n+1];
        arr[0] = 0;

        bool all_zero = true;
        for (int i = 1 ; i < n+1; i++){
            ll a;
            cin >> a;

            if (a != 0 && all_zero == true){
                all_zero = false;
            }

            arr[i] = a;

        }

        if (all_zero){
            cout << "0" << endl;
            return 0;
        }
        
        if (n == 1){
            cout << arr[1] << endl;
            return 0;
        } else if (n == 2) {
            cout << max(arr[1], arr[2]) << endl;
            return 0;
        } else if (n == 3) {
            ll tmp = max(arr[1], arr[2]);
            cout << max(tmp, arr[3]) << endl;
            return 0;
        }

        // 有兩種case 
        // Case 1
        // Gn-1 with total weight W 包含最後一點
        // 若為Case 1且 input sequence 是 odd 個
        // 則要刪掉最大的頭或尾

        // Case 2
        // Gn-2 with total weight W - vn 不包含最後一點


        // 頭尾相連！！ 變形題
        // even: x&1=0 false
        // odd:  x&1=1 true

        int isodd = n&1;


        // 之前計算過的存入 A array (bottom-up computation)
        // A[i] 為 MWIS of Graph i
        ll A[n+1];
        // ll B[n+1];

        // Base case 1
        A[0] = 0;
        // B[0] = 0;

        // Base case 2
        A[1] = arr[1];
        // B[1] = arr[1];
        

        // for (ll i = 2; i <= n; ++i) {
        //     if (i&1){
        //         // odd
        //         cout << "i is odd, i=" << i << endl;
        //         // case 1 包含最後一點and奇數 須處理

        //         A[i-1] -= min(A[1], A[i-1]);
        //         A[i-2] -= min(A[1], arr[i]);

        //         cout << "A[i-1] = " << A[i-1] << " / A[i-2] = " << A[i-2] << " / arr[i] = " << arr[i] << " / A[i-2] + arr[i] = " << A[i-2] + arr[i] << endl;
        //         // case 2 奇數 不須處理
        //         A[i] = max(A[i-1], A[i-2] + arr[i]);
        //     } else {
        //         cout << "i is even, i=" << i << endl;
        //         // even
        //         // case 1 偶數 包含最後一點 不須處理
        //         // case 2 偶數 不包含最後一點 不須處理
        //         cout << "A[i-1] = " << A[i-1] << " / A[i-2] = " << A[i-2] << " / arr[i] = " << arr[i] << " / A[i-2] + arr[i] = " << A[i-2] + arr[i] << endl;
        //         A[i] = max(A[i-1], A[i-2] + arr[i]);
        //     }
        //     cout << "i: " << i << " / A[i]: " << A[i] << endl << endl;
        // }
                // A[i-2] -= min(A[1], A[i-2]);

        for (ll i = 2; i <= n; ++i) {
            A[i] = max(A[i-1], A[i-2] + arr[i]);
        }


        // cout << "--- print_arr ---" << endl;
        // print_arr(A, n+1);


        // vector<ll> S;
        // vector<ll> Y;
        ll sum = 0;
        int i = n;

        while (i >= 2){
            // if (i&1){
            //     cout << "i is odd, i=" << i << endl;
            //     // odd
            //     // A[i-1] -= min(A[1], A[i-1]);
            //     A[i-1] -= min(A[1], A[i-1]);
            //     A[i-2] -= min(A[1], arr[i]);
            // }
            // Case 1 is bigger
            if (A[i-1] >= A[i-2] + arr[i]){
                // Y.push_back(arr[i]);
                i -= 1;

            // Case 2 is bigger
            } else {
                // S.push_back(arr[i]);
                sum += arr[i];
                i -= 2;
            }
        }
        if (i == 1) {
            sum += arr[i];
            // S.push_back(arr[1]);
            // Y.push_back(arr[1]);
        }
        // if (isodd){
        //     cout << "origin sum: " << sum << endl;
        //     sum -= min(arr[1], arr[n+1]);

        //     int i = n-1;
        //     ll sum2 = 0;
        //     while (i >= 2){
        //         // Case 1 is bigger
        //         // cout << "arr[i]: " << arr[i] << endl;
        //         sum2 += arr[i];
        //         i -= 2;
        //     }
        //     cout << "sum: " << sum << endl;
        //     cout << "sum2: " << sum2 << endl;

        //     cout << max(sum, sum2) << endl;
        //     return 0;
        // }
        cout << sum << endl;
        // cout << "--- print_vec(S) ---" << endl;
        // print_vec(S);

        // cout << "--- print_vec(Y) ---" << endl;
        // print_vec(Y);

        // cout << "sum: " << sum << endl;

    }
    return 0;
}