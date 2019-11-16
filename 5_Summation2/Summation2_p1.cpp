// #include <functional>
// #include <queue>
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> void print_q(T & q){
    while (!q.empty()){
        cout << q.top() << ' ';
        q.pop();
    }
    cout << '\n';
}


int main(){
    ll n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }
        ll num;

        priority_queue<ll, vector<ll>, greater<ll> > q;

        while (n--){
            cin >> num;
            q.push(num);
        }
        // print_q(q);
        if (n == 1){
            cout << q.top() << endl;
            return 0;
        }

        ll sum, cost = 0;
        while(q.size()>1){
            sum = 0;
            sum += q.top();
            q.pop();
            sum += q.top();
            q.pop();

            // 記得
            q.push(sum);
            cost += sum;
        }

        cout  << cost % 524287 << endl;


    }

    return 0;
}
