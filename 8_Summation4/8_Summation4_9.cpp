#include<bits/stdc++.h>
#include<bitset>
#include <string>
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

void check(ll target_sum, ll n, bitset<100> bit, ll arr[])
{
    bit[0] = 0;
    int result = bit[target_sum];
    cout << "print bit: " << bit.to_string() << endl;
    int count = 0;
    for (ll i = 0; i < n; ++i){

        bit &= ~arr[i];
        bit >> arr[i];
    
        // cout << "** bit[i]: "<< bit[i] << endl;
        // bit |= (bit << arr[i]);
    }
    cout << "-----" << endl;
    cout << "print bit: " << bit.to_string() << endl;

    for (ll i = 0; i < n; ++i){
        cout << "** bit[i]: "<< bit[i] << endl;
        if(bit[i]){
            count += 1;
        }
    }

    if (result && count >= 3){
        cout << "1" << endl;
        cout << "subset sum of " << target_sum << " exists\n";
    } else {
        // cout << "0" << endl;
        cout << "subset sum of " << target_sum << " does not exists\n";
    }
}
 
// function to store all the subset sums in bit vector
void subsetSum(bitset<100> &bit, ll arr[], ll n){
    // set all the bits to 0
    bit.reset();
    // set the 0th bit because subset sum of 0 exists
    bit[0] = 1;
    
    // apply the same technique as explained above
    for (ll i = 0; i < n; ++i){
        cout << "arr[i]: " << arr[i] << endl;
        bit |= (bit << arr[i]);
        cout << "bit: " << bit.to_string() << endl;
    }
}

int main(){
    ll n;

    while (cin >> n){
        // cout << "n: " << n << endl;
        // if (n < 4){
        //     cout << "0" << endl;
        //     return 0;
        // }
        ll arr[n];
        ll shift_arr[n];
        ll upper_bound = 0;
        ll lower_bound = 0;
        // vector<ll> vec;

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
            // vec.push_back(a);

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

        for (int i = 0; i < n; ++i){
            shift_arr[i] = arr[i] - lower_bound;
        }
        

        // ll target_sum = 0;

        bitset<100> bit;
 
        subsetSum(bit, shift_arr, n);
        // if (bit[n]){
        //     cout << "1" << endl;
        // } else {
        //     cout << "0" << endl;
        // }
        check(-lower_bound, n, bit, arr);
        // if (solve(arr, n, target_sum, upper_bound, lower_bound)) {
        //     cout << "1" << endl;
        // } else {
        //     cout << "0" << endl;
        // }

    }

    return 0;
}