#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

int main(){
    int n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        for (int i = 0 ; i < n; i++){
            ll a;
            cin >> a;
            cout << a << " ";
        }


    }
    return 0;
}