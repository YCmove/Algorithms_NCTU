#include<bits/stdc++.h>
#include<bitset>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;



template<class T> void prll_vec(T & vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


template<class T> void prll_arr(T* arr, ll n) {
    for (ll i = 0; i < n; ++i){
        cout << "arr[" << i << "]:" << arr[i] << " ";
    }
    cout << endl;
}

ll four_subset_zero(bitset<2500> & bs, ll arr[], ll n, ll target_sum, ll upper_bound, ll lower_bound){


    return 0;
}


int main(){
    ll n;

    while (cin >> n){

        // if (n < 4){
        //     cout << "0" << endl;
        //     return 0;
        // }
        ll arr[n];
        ll upper_bound = 0;
        ll lower_bound = 0;

        bool all_zero = true;
        for (ll i = 0 ; i < n; i++){
            ll a;
            cin >> a;

            if (a != 0 && all_zero == true){
                all_zero = false;
            }

            if (a > 0){
                upper_bound += a;
            } else {
                lower_bound += a;
            }

            arr[i] = a;

        }

        if (all_zero){
            cout << "1" << endl;
            return 0;
        }
        // cout << "----- before sort -----\n";
        // prll_arr(arr, n);
        sort(arr, arr + n);
        // cout << "----- after sort -----\n";
        // prll_arr(arr, n);

        // invalid sequence
        if ((arr[0] >= 0) || (arr[n-1] <= 0)){
            cout << "0" << endl;
            return 0;
        }

        ll target_sum = 0;

        // solve(arr, n, 0);

        // a vector of MAXN number of bits
        bitset<2500> bs;
        ll res = four_subset_zero(bs, arr, n, target_sum, upper_bound, lower_bound);

        if (res == 4) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }

    }

    return 0;
}