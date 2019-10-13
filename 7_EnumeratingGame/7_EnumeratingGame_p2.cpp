#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// set root as global
ll a, b;

int solve(int l, int r) {
    if((l == 0 && r == 0) || (l == 1 && r == 1)) {
        return 1;
    }

    if(l > r) {
        // right child 2x+1
        // return 2 * solve(3-2, 2) + 1; 2*2+1
        return 2 * solve(l-r, r) + 1;
    }

    if(l < r) {
        // left child 2x
        // return 2 * solve(1, 2-1); 2*1
        // return 2 * solve(3, 5-3); 2*5
        // return 2 * solve(3, 8-3); 10*2



        return 2 * solve(l, r-l);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cout << temp << " ";

        int l, r;
        cin >> l;
        cin.ignore();
        cin >> r;
        cout << "(" << l << ", " << r << ")" << endl;
        cout << solve(l, r) << endl;
    }
}