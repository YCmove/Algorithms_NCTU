#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
typedef long long ll;

int n, m;



int main(){
    cin >> n >> m;

    int tabl[n+1] = {0};

    int a, b;
    rep(i, m){
        cin >> a >> b;
        tabl[a] += 1;
        tabl[b] += 1;
    }

    rep(i, m){
        cout << tabl[i+1] << '\n';
    }
}