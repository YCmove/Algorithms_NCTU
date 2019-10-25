#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;


int main(){
    ll n;

    while (cin >> n){

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
            cout << "0" << endl;
            return 0;
        }
        
        if (n == 1){
            cout << arr[0] << endl;
        } else if (n == 2) {
            cout << max(arr[0], arr[1]) << endl;
        } 
        // else if (n == 3) {
        //     cout << max(arr[0], arr[1], arr[2]) << endl;
        // }

    }
    return 0;
}