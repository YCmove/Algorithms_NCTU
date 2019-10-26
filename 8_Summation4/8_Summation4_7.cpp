#include<bits/stdc++.h>
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

void solve(ll a[], ll n, ll sum)
{
    ll i,j;
    
    ll dp[n+1][sum+1];
    
    for(i=0;i<=n;i++){
        dp[i][0]=1;
    }
      
    for(j=0;j<=n;j++){
        dp[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(j<a[i]){
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
            }
        }
    }
        
    if(dp[n][sum]==1) {
        cout<<"Possible"<<endl;
    } else {
        cout<<"Not Possible"<<endl;
    }
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

        solve(arr, n, 0);
        // if (solve(arr, n, target_sum, upper_bound, lower_bound)) {
        //     cout << "1" << endl;
        // } else {
        //     cout << "0" << endl;
        // }

    }

    return 0;
}