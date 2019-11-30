#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < n; ++i)
#define REP(i, n) for(int i=0; i <= n; ++i)
typedef long long ll;


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

 
int main() {
 
    int n;
    ll x ;
    cin >> n;
   
    vector<int> nums;
    rep(i, n){
        cin >> x;
        nums.push_back(x);
    }
    priority_queue<ll , vector<ll>, greater<ll> > huff(nums.begin() , nums.end());
   
    // print_queue(huff);
    // return 0;

    while(huff.size( ) > 1){
        ll num1 = huff.top() ;
        huff.pop();
        ll num2 = huff.top() ;
        huff.pop();

        // cout << "num1=" << num1 << " / num2=" << num2 << '\n';
        huff.push(2 * (num1 + num2));
    }
    cout << huff.top();
}