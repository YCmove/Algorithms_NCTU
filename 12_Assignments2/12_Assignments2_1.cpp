#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

int n;

template<class T> void print_arr(T* arr, ll n) {
    for (ll i = 0; i < n; ++i){
        // cout << arr[i] << " ";
        cout << "arr[" << i << "]:" << arr[i] << ",   ";
    }
    cout << '\n';
}

void print_vec(vector<pair<ll, ll> > & v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << it->ff << " ";
    }
    cout << '\n';
}

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    if (a.ff == b.ff) {
        return a.ss < b.ss;
    }
    return a.ff < b.ff; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    ll due, t;
    vector<pair<ll, ll> > v;



    for (int i = 0; i < n;++i) {
        cin >> due >> t;
        v.push_back(make_pair(due, t));
    }

    sort(v.begin(), v.end(), comp);
    // print_vec(v);
    ll max_due = v[n-1].ff;
    ll max_t = v[n-1].ss;

    ll s[n] = {0};
    ll f[n] = {0}; // init all elems to 0
    ll ft = 0;
    int i = 1;

    for (auto it = v.begin(); it != v.end(); it++){
        cout << it->ff << ", " << it->ss << '\n';
        s[i] = ft;
        f[i] = ft + it->ss;
        ft += it->ss;
        cout << "s[i]: " << s[i] << ", f[i]: " << f[i] << '\n';

        if (f[i] > it->ff || ft >= max_due || (ft < max_due && max_due - ft < max_t)){
            cout << "BREAK!" << '\n';
            break;
        }
        i++;
    }
    

    print_arr(s, n);
    print_arr(f, n);
    cout << i << '\n';

    return 0;
}