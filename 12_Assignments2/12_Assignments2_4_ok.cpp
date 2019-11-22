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
    // 依照due來sort
    sort(v.begin(), v.end(), comp);
    // print_vec(v);
    
    priority_queue<ll> pq;

    // int j = 1;
    ll tmp = 0;

    for (int i = 0; i < n; ++i){
        pq.push(v[i].ss);
        tmp += v[i].ss;
        // cout << "tmp: " << tmp << ", due: " << v[i].ff << ", t: " << v[i].ss << '\n';
        if (tmp > v[i].ff) {
            tmp -= pq.top();
            pq.pop();
            // pq.push(v[i].ss);
            // cout << "No" << endl;
            // cout << j << '\n';
            // return 0;
        }
        // j++;
    }

    cout << pq.size() << '\n';

    // print_arr(s, n);
    // print_arr(f, n);
    // cout << "yes" << '\n';
    // cout << j << '\n';

    return 0;
}