#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;



template<class T> void print_vec(T & vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


template<class T> void print_arr(T* arr, ll n) {
    for (int i = 0; i < n; ++i){
        cout << "arr[" << i << "]:" << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    ll n;

    while (cin >> n){

        // if (n < 4){
        //     cout << "0" << endl;
        //     return 0;
        // }
        ll arr[n];

        bool all_zero = true;
        for (int i = 0 ; i < n; i++){
            ll a;
            cin >> a;

            if (a != 0 && all_zero == true){
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

        // positive array and negtive array
        // vector<ll> pos;
        // vector<ll> neg;

        // int i = 0;
        // while (arr[i] < 0 && i < n - 1) {
        //     neg.push_back(arr[i]);
        //     i++;
        // }

        // int positive_idx;
        // positive_idx = i;

        // while (arr[i] >= 0 && i < n) {
        //     pos.push_back(arr[i]);
        //     i++;
        // }

        // print_vec(neg);
        // print_vec(pos);
        // cout << "positive_idx: " << positive_idx << endl;


        unordered_map<ll, pair<ll, ll> > hash_sum;

        // sum of negative sequence
        // for (int i = 0; i < n - positive_idx - 1; ++i) {
        //     for (int j = i + 1; j < positive_idx; ++j) {
        //         hash_sum[pos[i] + pos[j]] = {i, j}; // pair of index
        //     }
        // }

        // sum of positive sequence
        // for (int i = 0; i < n - positive_idx; ++i) {
        //     for (int j = i + 1; j <= n - positive_idx; ++j) {
        //         hash_sum[pos[i] + pos[j]] = {i, j}; // pair of index
        //         cout << "pos[i]: " << pos[i] << ", pos[j]: " << pos[j] << endl;
        //     }
        // }
        // cout << "===== hash_sum =====" << endl;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                hash_sum[arr[i] + arr[j]] = {i, j}; // pair of index
                // cout << "arr[i]: " << arr[i] << ", arr[j]: " << arr[j] << endl;
            }
        }
        // sum of negative sequence
        // for (int i = 0; i < n - positive_idx - 1; ++i) {
        //     for (int j = i + 1; j < positive_idx; ++j) {
        //         cout << "neg[i]: " << neg[i] << ", neg[j]: " << neg[j] << endl;
        //         auto h = hash_sum.find(abs(neg[i] + neg[j]));
        //         if (h != hash_sum.end()){
        //             cout << "1" << endl;
        //         } else {
        //             cout << "0" << endl;

        //         };
        //     }
        // }
        // cout << "===== hash_sum.find =====" << endl;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // cout << "arr[i]: " << arr[i] << ", arr[j]: " << arr[j] << endl;
                ll sum = arr[i] + arr[j];

                unordered_map<ll, pair<ll, ll> >::iterator h;
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