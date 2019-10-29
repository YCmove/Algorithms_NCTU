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
        // cout << arr[i] << " ";
        cout << "arr[" << i << "]:" << arr[i] << " ";
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

        // int isodd = n&1;


        // 之前計算過的存入 A array (bottom-up computation)
        // A[i] 為 MWIS of Graph i
        ll A[n]; // 沒有最後一個
        ll B[n]; // 沒有第一個

        // Base case 1
        A[0] = 0;
        B[0] = 0;

        // Base case 2
        A[1] = arr[1]; // 沒有最後一個
        B[1] = arr[2]; // 沒有第一個
   

        // 沒有最後一個
        for (ll i = 2; i < n; ++i) {
            A[i] = max(A[i-1], A[i-2] + arr[i]);
        }

        // 沒有第一個
        for (ll i = 2; i <= n; ++i) {
            B[i] = max(B[i-1], B[i-2] + arr[i+1]);
        }

        // cout << "--- print_arr A---" << endl;
        // print_arr(A, n);
        // cout << "--- print_arr B---" << endl;
        // print_arr(B, n);
        
        if (A[n-1] > B[n-1]){
            cout << A[n-1] << endl;
        }else{
            cout << B[n-1] << endl;
        }

        return 0;

    }
    return 0;
}