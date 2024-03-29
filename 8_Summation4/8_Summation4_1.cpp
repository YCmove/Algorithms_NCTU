#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;



// template<class T> void print_arr(T* arr, ll n) {
//     for (int i = 0; i < n; ++i){
//         cout << "arr[" << i << "]:" << arr[i] << " ";
//     }
//     cout << endl;
// }


int main(){
    ll n;

    while (cin >> n){

        ll arr[n];

        bool all_zero = true;
        for (int i = 0 ; i < n; i++){
            ll a;
            cin >> a;

            if (a != 0){
                all_zero = false;
            }

            arr[i] = a;

        }

        if (all_zero){
            cout << "1" << endl;
            return 0;
        }
        // cout << "----- before sort -----\n";
        // print_arr(arr, n);
        sort(arr, arr + n);
        // cout << "----- after sort -----\n";
        // print_arr(arr, n);

        // invalid sequence
        if ((arr[0] >= 0) || (arr[n-1] <= 0)){
            cout << "0" << endl;
            return 0;
        }
            // cout << "here !!" << endl;

        unordered_map<ll, pair<ll, ll> > hash_sum;

        // cout << "===== hash_sum =====" << endl;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                hash_sum[arr[i] + arr[j]] = {i, j}; // pair of index
                // cout << "arr[i]: " << arr[i] << ", arr[j]: " << arr[j] << endl;
            }
        }

        // cout << "===== hash_sum.find =====" << endl;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // cout << "arr[i]: " << arr[i] << ", arr[j]: " << arr[j] << endl;
                ll sum = arr[i] + arr[j];

                unordered_map<ll, pair<ll, ll> >::iterator h;
                // h = hash_sum.find(sum);
                if (sum == 0){
                    h = hash_sum.find(sum);
                } else {
                    h = hash_sum.find(-sum);
                }
                // hash_sum != sum 兩個不能同為 正號 或負號
                if (h != hash_sum.end()){
                    pair<ll, ll> idx_pair = hash_sum[-sum];
                    if (idx_pair.first != i && idx_pair.first != j && idx_pair.second != i && idx_pair.second != j){
                        cout << "1" << endl;
                        // cout << arr[i] << ", " << arr[j] << ", " << arr[idx_pair.first] << ", " << arr[idx_pair.second] << endl; 
                        return 0;
                    }
                } 
            }
        }
        cout << "0" << endl;
        return 0;
    }
    return 0;
}