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

int has_four_subset_sum(ll arr[], ll n, ll target_sum, ll upper_bound, ll lower_bound){

    // [row][column] == [before arr's index][sum]
    ll dp_matrix[n+1][upper_bound - lower_bound + 1]; // 1 is for zero
    // cout << "here: " << upper_bound - lower_bound + 1 << endl;

    // init all table to zero
    for (int i = 0; i <= n+1; ++i){
        // cout << "i: " << i << endl;
        for (int j = 0; j < upper_bound - lower_bound + 1; ++j){
            // cout << "j: " << j << endl;
            dp_matrix[i][j] = 0;
        }
    }

    // for (int i = 1; i <= n+1; ++i){
    //     for (int j = 0; j < upper_bound - lower_bound + 1; ++j){
    //         dp_matrix[i][j] = dp_matrix[i-1][j];
            
    //         if () {
    //             dp_matrix[i][j] = ;
    //         } else {
    //             dp_matrix[i][j] = ;

    //         }
    //     }
    // }

    // return dp_matrix[i][j];
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
        for (int i = 0 ; i < n; i++){
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
        // print_arr(arr, n);
        sort(arr, arr + n);
        // cout << "----- after sort -----\n";
        // print_arr(arr, n);

        // invalid sequence
        if ((arr[0] >= 0) || (arr[n-1] <= 0)){
            cout << "0" << endl;
            return 0;
        }

        ll target_sum = 0;

        if (has_four_subset_sum(arr, n, target_sum, upper_bound, lower_bound)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }

    }

    return 0;
}