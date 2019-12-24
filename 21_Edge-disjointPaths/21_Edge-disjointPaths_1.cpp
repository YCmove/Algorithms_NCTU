#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300+1;
const int MAXm = 90001;

int n, m;
vector<vector<int> > g;

int main(){
    cin >> n >> m;
    g.clear();
    g.resize(n);

    int a, b;
    while (--m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    return 0;
}