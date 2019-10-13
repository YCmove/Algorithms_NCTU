#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// set root as global
ll a, b;


ll recur(ll l, ll r) {
    ll ans;
    // 重要的中止條件！
    if((l ==  a && r == b)) {
        // cout << "Legel - " << "l: " << l << ", r: " << r << endl;
        return 1;
        // return 1ll;
    }

    if (l < a || r < b || (l == 0 && r > 0) || (l > 0 && r == 0) || l == r){
        // cout << "Illegel - " << "l: " << l << ", r: " << r << endl;
        return -1;
    }

    if(l > r) {
        // right child 2x+1
        // return 2 * recur(3-2, 2) + 1; 2*2+1
        // cout << "l > r - " << "l: " << l << ", r: " << r << endl;
        ans = recur(l-r, r);
        if (ans == -1) return -1;
        return 2 * recur(l-r, r) + 1;
    } else if(l < r) {
        // left child 2x
        // cout << "l < r - " << "l: " << l << ", r: " << r << endl;
        ans = recur(l, r-l);
        if (ans == -1) return -1;
        return 2 * recur(l, r-l);
    }
    cout << "never!" << endl;
    return 0;
}


int main(){
    int m;

    while (cin >> m){

        if (m == 0){
            return 0;
        }


 
        for (int i = 0 ; i < m; i++){
            ll c, d;
            // Root Node: (a,b)
            cin >> a >> b >> c >> d;
            // cout << "---------------" << endl;
            ll ans = recur(c, d);
            if (ans <= 0) ans = -1;

            cout << "origin ans: " << ans << endl;
            // cout << ans % 524287 << endl;
        }

    }

    return 0;
}
