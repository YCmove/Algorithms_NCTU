#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// set root as global
ll a, b;


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
            cout << "---------------" << endl;
            cout << "START c: " << c << ", d: " << d << endl;

            if(c < a || d < b) {
                // cout << "Legel - " << "l: " << l << ", r: " << r << endl;
                cout << -1 << endl;
                continue;
            }

            if (c == a && d == b){
                cout << 1 << endl;
                continue;
            }

            // when d == b, end of this row
            if (c == a){
                ll n_row = (c - b)/a + 1;
                cout << "n_row: " << n_row << endl;
                ll ans = ((1-pow(2, n_row)) / (1-2));
                cout << "origin ans: " << ans << endl;
            } else if (d == b){
                ll n_row = (c - a)/b + 1;
                cout << "n_row: " << n_row << endl;
                ll ans = ((1-pow(2, n_row)) / (1-2));
                cout << "origin ans: " << ans << endl;
            }

            // ll c_next, d_next;
            ll count = 0;
            ll c_prev, d_prev;
            do {
                c_prev = c;
                d_prev = d;
                c = d;
                d = c_prev + d_prev - (2 * (c_prev % d_prev));
                count ++;
                cout << "c_prev: " << c_prev << ", d_prev: " << d_prev << endl;
                cout << "c: " << c << ", d: " << d << endl;
            } while ((d != b && d >= 0) || (d == c_prev && d != b));

            if (d == c_prev){
                cout << -1 << endl;
                continue;
            }

            // when d == b, end of this row
            ll n_row = (c - a)/b + 1;
            cout << "n_row: " << n_row << endl;
            ll ans = ((1-pow(2, n_row)) / (1-2)) - count;
            cout << "origin ans: " << ans << endl;


            // ll ans = recur(c, d);
            // if (ans <= 0) ans = -1;

            // cout << ans % 524287 << endl;
        }

    }

    return 0;
}
