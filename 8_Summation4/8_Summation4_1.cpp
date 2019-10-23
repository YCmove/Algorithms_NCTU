#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;


template<class T> void print_arr(T* arr, ll n) {
    for (int i = 0; i < n; ++i){
        cout << "arr[" << i << "]:" << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    ll n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        ll arr[n];

        for (int i = 0 ; i < n; i++){
            ll a;
            cin >> a;
            arr[i] = a;

        }
        cout << "----- before sort -----\n";
        print_arr(arr, n);
        sort(arr, arr + n);
        cout << "----- after sort -----\n";
        print_arr(arr, n);


    }
    return 0;
}