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
    // ll base = 2; 
    int n = 0;
    // cout << "sta.back: " << sta.back() << endl;
    // cout << "sta.size: " << sta.size() << endl;

    while (!sta.empty()){
        // cout << "sta.top: " << sta.top() << endl;
        if (sta.top() == 1){
            // 往右走
            // decimalNumber += pow(base, n);
            decimalNumber = 2 * decimalNumber + 1;

        } else {
            // 往左走
            decimalNumber = 2 * decimalNumber;

        }
        n++;
        sta.pop();
        decimalNumber = decimalNumber % 524287;
    }
    clear(sta);
    // cout << "decimalNumber: " << decimalNumber << endl;
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
            // cout << "--------a: " << a << ", b: " << b <<"-------" << endl;

            if(l < a || r < b) {
                // cout << "1. ilegel - " << "l: " << l << ", r: " << r << endl;
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
                    // return 2 * recur(3-2, 2) + 1; 2*2+1
                    // cout << "l > r - " << "l: " << l << ", r: " << r << endl;
                    l = l-r;
                    binarystack.push(1);

                } else if(l < r) {
                    // left child 2x
                    // cout << "l < r - " << "l: " << l << ", r: " << r << endl;
                    r = r-l;
                    binarystack.push(0);
                } else {
                    // cout << "never reach here. " << "l: " << l << ", r: " << r << endl;
                    clear(binarystack);
                    flag = true;
                    // break;
                }
            }

            if (binarystack.empty()){
                // cout << "binarystack.empty(): " << -1 << endl;
                cout << -1 << endl;
                continue;
            }

            if(l < a || r < b || (l == r && (l != 1 && l!= a))) {
                // cout << "2. ilegel - " << "l: " << l << ", r: " << r << endl;
                cout << -1 << endl;
                continue;
            }

            // binarystack.push(1); // 第一個root不重要
            ll ans = binarystack_to_decimal(binarystack);
            // cout << "origin ans: " << ans << endl;
            cout << ans % 524287 << endl;

        }

    }

    return 0;
}
