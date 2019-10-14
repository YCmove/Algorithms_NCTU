// #include<bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

// x從最低位數數來的第一個非零位
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

// 最多 3 * 10^5 個 input point
const int max_n = 3*100000 + 10;
// const ll max_n = 600020;
// store array in the stack
ll c_count[max_n], test[max_n];

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

struct Point {
    ll x;
    ll y;
    ll origin_idx;
};

template<class T> void print_arr(T& arr, ll n) {
    // cout << (sizeof(arr)/sizeof(*arr)) << endl;
    // for (auto it = arr.begin(); it != arr.end(); ++it){
    for (int i = 0; i < n; ++i){
        cout << "arr[" << i << "] - x:" << arr[i].x << ", y: " << arr[i].y << endl;
    }
    cout << endl;
}

bool compare(Point p, Point b){
    // 點點間排序的方法，x軸優先，然後才是y軸
	if(p.x != b.x){
        // 只要a, b x軸位置不一樣，就以x軸大小來比較
        return p.x < b.x;
    }
    // p, b 兩點x軸位置一樣，比較y軸大小
	return p.y < b.y;
}

void add(ll x, ll y){
	for(; x < max_n; x += lowbit(x)){
        c_count[x] += y;
    }; 
}

int sum(ll x){
	ll ans = 0;
	for(; x; x -= lowbit(x)) {
        ans += c_count[x];
    };
	return ans;
}


int main(){
    ll n;
    // cout << "here" << endl;
    while (cin >> n){

        if (n == 0){
            return 0;
        }

        // Point origin[max_n];
        // origin[0].x = 11;
        // origin[0].y = 22;
        // cout << "(" << origin[0].x << ", " << origin[0].y << ")"  << endl;
        // return 0;
        Point p[max_n];

        unordered_map<ll, ll> umap;

        // vector<ll, ll> idxvec;
        // idxvec.resize(max_n);
        // vector<vector<ll> > pvec;
 
        for (ll i = 0 ; i < n; ++i){
            ll x, y;
            cin >> x >> y;
            // origin[i].x = x;
            // origin[i].y = y;
            p[i].x = x;
            p[i].y = y;
            p[i].origin_idx = i;
            cout << "Input (" << p[i].x << ", " << p[i].y << ")"  << endl;
        }


        // for (ll i = 0 ; i < n; ++i){
        //     cout << "(" << p[i].x << ", " << p[i].y << ")"  << endl;
        //     origin[i].x = p[i].x;
        //     origin[i].y = p[i].y;
        // }
        // origin = p;
        // copy(p.begin(), p.end(), origin.begin());

        // return 0;
        cout << "- before sort -" << endl;
        print_arr(p, n);

	    sort(p, p+n, compare);
        
        cout << "- after sort -" << endl;
        print_arr(p, n);
        cout << "-- -- --" << endl;

        ll now;
        for(ll i = 0; i < n; i++){
            now = sum(p[i].y + 1);
            // test[now]++;
            umap[p[i].origin_idx] = now;
            // cout << "(" << p[i].x << ", " << p[i].y << "): " << now << endl;
            cout << "now: " << now << endl;
            cout << "- start add -" << endl;
            add(p[i].y + 1, 1);
            cout << "- after add -" << endl;
        }

        for(ll i = 0; i < n; i++){
            cout << umap[i] << endl;
            // cout << test[i] << endl;
            // cout << "(" << origin[i].x << ", " << origin[i].y << "): " ;
        }


    }

    return 0;
}
