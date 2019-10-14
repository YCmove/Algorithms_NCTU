// #include<bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

// x從最低位數數來的第一個非零位
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

// 最多 3 * 10^5 個 input point
// const int max_n = 3*100000 + 10;

// 2^31 - 1是 帶正負號的 long int 的上限
// const ll max_n = pow(2, 31);

// INT_MAX	類型為 int 之變數的最大值。	2147483647
// UINT_MAX	類型為 unsigned int 之變數的最大值。4294967295 (0xffffffff)
const ll max_n = UINT8_MAX;
// store array in the stack

// 建立Binary Indexed Tree的陣列
// ll BIT[max_n];
// ll NBIT[max_n];
ll* PBIT = new ll[max_n]; // 遇到pow(2, 31)照樣炸裂... std::bad_alloc
ll* NBIT = new ll[max_n]; // 遇到pow(2, 31)照樣炸裂... std::bad_alloc

struct Point {
    ll x;
    ll y;
    ll origin_idx;
};

 
void insert(ll t, ll d, ll* BIT)
{
    // 從root開始走, d為1, 代表traverse down經過的區間都 +1, 因為本題是紀錄出現次數
    // cout << "insert t: " << t << ", d: " << d << endl;

    // t 不超過 max_n, t要一路走到leaf
    while (t <= max_n)
    {
        // cout << "insert while BIT[t]: " << BIT[t] << ", t: " << t << endl;

        // t 在 BIT 上的位置的值 + 1
        // BIT[t]為陣列中相對應範圍的元素合
        BIT[t] += d;

        // lowbit 為 t 的下界, 一路走到底(leaf)
        
        t += lowbit(t);

        // cout << "insert while end t: " << t << endl;
        // cout << "===" << endl;
    }
}

// ll getNBIT(){
//     return NBIT[0];
// }
 
ll getsum(ll t, ll* BIT)
{
    // cout << "\n\ngetsum t: " << t << endl;
    ll zs=0;
    while (t > 0)
    {
        // cout << "getsum while BIT[t]: " << BIT[t] << ", t: " << t << ", zs: " << zs << endl;
        zs+=BIT[t];
        t-=lowbit(t);
        // cout << "getsum while end t: " << t << ", zs: " << zs << endl;
        // cout << "===" << endl;
    }
    // cout << "getsum end zs: " << zs << endl;
    return zs;
}
 


template<class T> void print_arr(T& arr, ll n) {
    for (int i = 0; i < n; ++i){
        cout << "arr[" << i << "] - x:" << arr[i].x << ", y: " << arr[i].y << endl;
    }
    cout << endl;
}

bool compare_y(Point p, Point b){
    // 點點間排序的方法，y軸優先，然後才是x軸
	if(p.y != b.y){
        // 只要a, b y軸位置不一樣，就以y軸大小來比較
        return p.y < b.y;
    }
    // p, b 兩點y軸位置一樣，比較x軸大小
	return p.x < b.x;
}



int main(){
    ll n;
    while (cin >> n){

        if (n == 0){
            return 0;
        }

        Point p[max_n];
        ll q;

        unordered_map<ll, ll> umap;

        for (ll i = 0 ; i < n; ++i){
            ll x, y;
            cin >> x >> y;
            p[i].x = x;
            p[i].y = y;
            p[i].origin_idx = i;
            // cout << "Input (" << p[i].x << ", " << p[i].y << ")"  << endl;
        }

        // cout << "- before sort -" << endl;
        // print_arr(p, n);

	    sort(p, p+n, compare_y);
        
        // cout << "- after sort -" << endl;
        // print_arr(p, n);
        // cout << "-- -- --" << endl;


        for(ll i = 0; i < n; i++){
            // cout << "-- start insert --" << endl;
            if (p[i].x >= 0){
                insert(p[i].x + 1, 1, PBIT);
                q = getsum(p[i].x + 1, PBIT) - 1;
                // cout << "positive NBIT[1]: " << NBIT[1] << endl;
                // cout << "p[0].x: " << p[0].x << endl;
                // cout << "positive sum of NBIT: " << getsum(p[i].x + 1 + INT8_MAX, NBIT) - 1 << endl;
                q += getsum(p[i].x + 1 + INT8_MAX, NBIT);
            } else {
                insert(p[i].x + 1 + INT8_MAX, 1, NBIT);
                q = getsum(p[i].x + 1 + INT8_MAX, NBIT) - 1;
                // cout << "negtive sum of NBIT: " << getsum(p[i].x + 1 + INT8_MAX, NBIT) - 1 << endl;
                // cout << "negtive NBIT[1]: " << NBIT[1] << endl;

            }
            // insert(p[i].x + 1, 1);
            // cout << "-- start getsum --" << endl;
            // q = getsum(p[i].x + 1) - 1;
            // cout << "-- finish getsum --" << endl;
            // cout << "(" << p[i].x << ", " << p[i].y << ") - " << "q:" << q << endl;


            umap[p[i].origin_idx] = q;
            // cout << "(" << p[i].x << ", " << p[i].y << "): " << now << endl;
        }

        for(ll i = 0; i < n; i++){
            cout << umap[i] << endl;
        }


    }

    return 0;
}
