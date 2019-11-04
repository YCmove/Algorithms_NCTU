// #include<bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

// x從最低位數數來的第一個非零位
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

// 最多 3 * 10^5 個 input point
const int max_n = 3*100000 + 10;

// 2^31 - 1是 帶正負號的 long int 的上限
// const ll max_n = pow(2, 31);

// INT_MAX	類型為 int 之變數的最大值。	2147483647
// UINT_MAX	類型為 unsigned int 之變數的最大值。4294967295 (0xffffffff)
// const ll max_n = INT_MAX; // 錯誤訊息 std::bad_alloc
// store array in the stack

// 建立Binary Indexed Tree的陣列
// ll PBIT[max_n];
// ll NBIT[max_n];
// 遇到pow(2, 31)照樣炸裂... std::bad_alloc


struct Point {
    ll x;
    ll y;
    ll x_rank;
    ll y_rank;
    ll origin_idx;
    ll counts;
};
// idx 為 poi 在 BIT array的 index
void insert(ll idx, ll d, ll n, Point* BIT){
    // 從root開始走, d為1, 代表traverse down經過的區間都 +1, 因為本題是紀錄出現次數
    // t 不超過 BIT array長度, t要一路走到leaf
    while (idx <= n){
        // t 在 BIT 上的位置的值 + 1, BIT[t]為陣列中相對應範圍的元素合
        BIT[idx].counts += d;
        // lowbit 為 t 的下界, 一路走到底(leaf)
        // 是一路往Left Tree 走（树状数组的思路是保留线段树所有最左边的区间而形成的）
        idx += lowbit(idx);
    }
}
ll getsum(ll idx, Point* BIT)
{
    ll fsum=0;
    while (idx > 0){
        fsum += BIT[idx].counts;
        // 求 sum 時 BIT 的 index t 從大減到小
        idx -= lowbit(idx);
    }
    return fsum;
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
bool compare_x(Point a, Point b){
	if(a.x != b.x){
        return a.x < b.x;
    }
	return a.y < b.y;
}
int main(){
    ll n;
    while (cin >> n){

        if (n == 0){
            return 0;
        }
        Point p[n];
        ll sums; 
        Point* PBIT = new Point[2*n]; 
        Point* NBIT = new Point[2*n];
        unordered_map<ll, ll> umap;
        // 注意p是紀錄從 0 to n-1
        for (ll i = 0 ; i < n; ++i){
            ll x, y;
            cin >> x >> y;
            p[i].x = x;
            p[i].y = y;
            p[i].origin_idx = i;
        }
        sort(p, p+n, compare_x);
        // 紀錄x_rank的位置
        for (ll i = 0 ; i < n; ++i){
            p[i].x_rank = i;
        }
	    sort(p, p+n, compare_y);
        // 紀錄y_rank的位置
        for (ll i = 0 ; i < n; ++i){
            p[i].y_rank = i;
        }
        for(ll i = 0; i < n; i++){
            if (p[i].x >= 0){
                // insert此處不能傳入 i+1 (value as index), 因為index無法表示x軸的大小關係
                insert(p[i].x_rank + 1, 1, 2*n, PBIT);
                sums = getsum(p[i].x_rank + 1, PBIT) - 1;
                sums += getsum(p[i].x_rank+1, NBIT);
            } else {
                insert(p[i].x_rank+1, 1, 2*n, NBIT);
                sums = getsum(p[i].x_rank+1, NBIT) - 1;
            }
            umap[p[i].origin_idx] = sums;
        }
        for(ll i = 0; i < n; i++){
            cout << umap[i] << endl;
        }

        delete[] PBIT;
        delete[] NBIT;
        PBIT = NULL;
        NBIT = NULL;

    }

    return 0;
}
