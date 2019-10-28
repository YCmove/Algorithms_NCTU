#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

ll min_sum(ll arr[], ll n)
{
        ll cout_a, cout_b, min_sum;
        cout_a = arr[n-1];
        cout_b = arr[n-2];

        int i = n - 3;

        while(i >= 0){
            if(cout_a > cout_b){ 
                cout_b = cout_b + arr[i];
            } else {
                cout_a = cout_a + arr[i];
            }
            i--;
        }

        if(cout_a > cout_b){
            min_sum = cout_a - cout_b;
        } else {
            min_sum = cout_b - cout_a;
        }
        // cout << "min_sum: " << min_sum << endl;

        return min_sum ;
}

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
            cout << 0 << endl;
            return 0;
        }
        
        // if (n == 1){
        //     cout << arr[0] << endl;
        //     return 0;
        // } 

        sort(arr, arr + n);


        ll res = min_sum(arr, n);
        cout << res << endl;

    }

}