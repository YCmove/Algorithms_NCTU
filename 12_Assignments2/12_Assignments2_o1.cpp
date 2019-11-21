// https://atcoder.jp/contests/abc131/submissions/8536624

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n) for (int i = 0; i <= n; i++)
#define repr(i, n) for (int i = n; i > 0; i--)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9 + 7;
template <class T>
void puts(T x) { std::cout << x << std::endl; }
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int n;
vector<pair<ll, ll>> v;

void print_vec(vector<pair<ll, ll>> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->ff << " ";
    }
    cout << '\n';
}

int main() {
    cin >> n;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(make_pair(b, a)); // due, t
    }
    // 依照due來sort
    sort(v.begin(), v.end());
    print_vec(v);
    ll tmp = 0;
    int j = 0;
    rep(i, n) {
        tmp += v[i].ss;
        cout << "tmp: " << tmp << ", due: " << v[i].ff << ", t: " << v[i].ss << '\n';
        if (tmp > v[i].ff) {
            cout << "No" << endl;
            cout << j << endl;
            return 0;
        }
        j++;
    }
    cout << "Yes" << endl;
    cout << j << endl;
}