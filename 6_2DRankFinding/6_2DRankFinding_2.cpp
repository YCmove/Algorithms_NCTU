// #include<bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;
const int max_n = 3*100000;
ll c_count[max_n], test[max_n];


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

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        // Point origin[max_n];
        // origin[0].x = 11;
        // origin[0].y = 22;
        // cout << "(" << origin[0].x << ", " << origin[0].y << ")"  << endl;

        Point p[max_n];

        unordered_map<ll, ll> umap;

        for (ll i = 0 ; i < n; ++i){
            ll x, y;
            cin >> x >> y;
            // origin[i].x = x;
            // origin[i].y = y;
            p[i].x = x;
            p[i].y = y;
            p[i].origin_idx = i;
            cout << "(" << p[i].x << ", " << p[i].y << ")"  << endl;
        }


        // for (ll i = 0 ; i < n; ++i){
        //     cout << "(" << p[i].x << ", " << p[i].y << ")"  << endl;
        //     origin[i].x = p[i].x;
        //     origin[i].y = p[i].y;
        // }
        // origin = p;
        // copy(p.begin(), p.end(), origin.begin());

        // return 0;
        // print_arr(p, n+1);
        // cout << "---------" << endl;

	    sort(p, p+n, compare);
        // cout << "print_arr after sort" << endl;
        // print_arr(p, n);

        ll now;
        for(ll i = 0; i < n; i++){
            now = sum(p[i].y + 1);
            test[now]++;
            // pvec[p[i].x][p[i].y] = now;
            umap[p[i].origin_idx] = now;
            // cout << "(" << p[i].x << ", " << p[i].y << "): " << now << endl;
            // cout << now << endl;
            // printf("(%d, %d) - ", p[i].x, p[i].y);
            // printf("%d\n", now);
            add(p[i].y + 1, 1);
        }

        for(ll i = 0; i < n; i++){
            // cout << umap[i] << endl;
            cout << test[i] << endl;
            // cout << "(" << origin[i].x << ", " << origin[i].y << "): " ;
            // cout << pvec[origin[i].x][origin[i].y] << endl;
        }


    }

    return 0;
}
