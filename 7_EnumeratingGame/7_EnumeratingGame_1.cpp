#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// set root as global
ll a, b;


struct fraction
{
    ll n;
    ll d;
};

ll recur(ll d, ll n)
{

    int path = 0; // array of bits
    int path_index = 0;

    // Backtrack
    while (d != n)
    {
        if (d > n)
        {
            d -= n;
        }
        else
        {
            n -= d;
            path |= (1 << path_index);
        }
        path_index++;
    }

    ll i, result = 1;
    for (i = path_index - 1; i >= 0; i--)
    {
        if (path & (1 << i)) result = (result << 1) + 1;
        else result <<= 1;
    }
    // printf("%d\n", result);
    return result;
}


ll bak_recur(ll l, ll r) {
    // ll x,k,temp;

    // 重要的中止條件！
    if((l ==  a && r == b) || (l == 0 && r == 0)) {
        // cout << "Legel - " << "l: " << l << ", r: " << r << endl;
        return 1;
        // return 1ll;
    }

    if (l < a || r < b || (l == 0 && r > 0) || (l > 0 && r == 0)){
        // cout << "Illegel - " << "l: " << l << ", r: " << r << endl;
        return 0;
    }


    if(l > r) {
        // right child 2x+1
        // return 2 * recur(3-2, 2) + 1; 2*2+1
        // cout << "l > r - " << "l: " << l << ", r: " << r << endl;
        // return 2 * recur(l-r, r) + 1;
        // k=l/r;
		// if(l%r==0)//到达根节点时，特判，下同
		// k--;
		// x=recur(l%r,r);
		// temp=pow(2,k)*x+pow(2,k)-1;//找规律
		// return temp;
    } else if(l < r) {
        // left child 2x
        // cout << "l < r - " << "l: " << l << ", r: " << r << endl;
        // return 2 * recur(l, r-l);
        // k=r/l;
		// if(r%l==0)
		// k--;
		// x=recur(l,r%l);
		// temp=pow(2,k)*x;//找规律
		// return temp;
    }
    return 0;
}


int main(){
    ll n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        // struct fraction frac;

 
        for (ll i = 0 ; i < n; i++){
            ll c, d;
            // Root Node: (a,b)
            cin >> a >> b >> c >> d;
            // cout << "---------------" << endl;
            ll ans = recur(c, d);
            if (ans <= 0) ans = -1;

            // cout << "origin ans: " << ans << endl;
            cout << ans % 524287 << endl;
        }

    }

    return 0;
}
