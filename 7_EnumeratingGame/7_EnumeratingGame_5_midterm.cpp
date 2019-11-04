#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// 2019.10.13 21:45 前5個AC


// set root as global
ll a, b;

void clear(stack<int>& sta) {
    stack<int> empty;
    swap(empty, sta);
};
ll binarystack_to_decimal(stack<int> &sta){
    ll decimalNumber = 1; 
    int n = 0;
    while (!sta.empty()){
        if (sta.top() == 1){
            decimalNumber = 2 * decimalNumber + 1; // 往右走
        } else {
            decimalNumber = 2 * decimalNumber; // 往左走
        }
        n++;
        sta.pop();
        decimalNumber = decimalNumber % 524287;
    }
    clear(sta);
    return decimalNumber;
}
int main(){
    int m;
    while (cin >> m){
        if (m == 0){
            return 0;
        }
        for (int i = 0 ; i < m; i++){
            ll l, r;
            stack<int> binarystack;
            // Root Node: (a,b)
            cin >> a >> b >> l >> r;
            if(l < a || r < b) {
                cout << -1 << endl;
                continue;
            }
            if (l == a && r == b){
                cout << 1 << endl;
                continue;
            }
            bool flag = false;
            while (!((l == a && r == b) || (l == 1 && r == 1) || l == r || flag == true)){
                if(l > r) {
                    // right child 2x+1
                    l = l-r;
                    binarystack.push(1);

                } else if(l < r) {
                    // left child 2x
                    r = r-l;
                    binarystack.push(0);
                } else {
                    clear(binarystack);
                    flag = true;
                }
            }
            if (binarystack.empty()){
                cout << -1 << endl;
                continue;
            }
            if(l < a || r < b || (l == r && (l != 1 && l!= a))) {
                cout << -1 << endl;
                continue;
            }
            ll ans = binarystack_to_decimal(binarystack);
            cout << ans % 524287 << endl;
        }

    }

    return 0;
}
