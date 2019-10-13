#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// 2019.10.13 21:45 前5個AC


// set root as global
ll a, b;

void clear(queue<int>& q) {
    queue<int> empty;
    swap(empty, q);
};


ll binaryqueue_to_decimal(queue<int> &q){
    ll decimalNumber = 0; 
    ll base = 2; 
    int n = 0;
    // cout << "q.front: " << q.front() << endl;
    // cout << "q.size: " << q.size() << endl;

    while (!q.empty()){
        // cout << "q.front: " << q.front() << endl;
        if (q.front() == 1){
            decimalNumber += pow(base, n);
        }
        n++;
        q.pop();
    }
    clear(q);
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
            queue<int> binaryqueue;
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
                    binaryqueue.push(1);

                } else if(l < r) {
                    // left child 2x
                    // cout << "l < r - " << "l: " << l << ", r: " << r << endl;
                    r = r-l;
                    binaryqueue.push(0);
                } else {
                    // cout << "never reach here. " << "l: " << l << ", r: " << r << endl;
                    clear(binaryqueue);
                    flag = true;
                    // break;
                }
            }

            if (binaryqueue.empty()){
                // cout << "binaryqueue.empty(): " << -1 << endl;
                cout << -1 << endl;
                continue;
            }

            if(l < a || r < b || (l == r && (l != 1 && l!= a))) {
                // cout << "2. ilegel - " << "l: " << l << ", r: " << r << endl;
                cout << -1 << endl;
                continue;
            }

            binaryqueue.push(1);
            ll ans = binaryqueue_to_decimal(binaryqueue);
            // cout << "origin ans: " << ans << endl;
            cout << ans % 524287 << endl;

        }

    }

    return 0;
}
