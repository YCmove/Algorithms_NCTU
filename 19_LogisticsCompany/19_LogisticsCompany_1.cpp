#include <bits/stdc++.h>
#define rep(i, n) for(int i =0; i<n;++i)
using namespace std;
typedef long long ll;

const int MAXN = 2 *1e3 +5;
int n, m;
vector<int> digraph[MAXN];
int weight[MAXN];
ll minimum = INT_MAX;
ll cost = 0;


void init(int n){
    rep(i, n+1){
        weight[i] = INT_MAX;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a, b;
    ll k;
    rep(i, m){
        cin >> a >>b >> k;
        digraph[a].push_back(b);
    }
    init(n);
    



    return 0;
}