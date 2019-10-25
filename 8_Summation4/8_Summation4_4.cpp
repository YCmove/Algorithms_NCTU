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



int recur_sum(ll arr[], ll n, ll sum)
{
    print_arr(arr, n);
	if (sum == 0)return 1;

	if (n < 0) return 0;

	int in = recur_sum(arr, n - 1, sum - arr[n]);
	int ex = recur_sum(arr, n - 1, sum);

	return in || ex;
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
        print_arr(arr, n);



        // invalid sequence
        if ((arr[0] >= 0) || (arr[n-1] <= 0)){
            cout << "0" << endl;
            return 0;
        }



        if (recur_sum(arr, n, 0)){
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }

        return 0;

        }
    return 0;
}