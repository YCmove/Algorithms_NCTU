#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<n; ++i)
using namespace std;
typedef long long ll;


class job {
  public:
    ll deadline;
    ll profit;
};


void mergesort(job a[], ll low, ll mid, ll high) {
    job temp[15000005];
    ll i = low, k = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i].profit >= a[j].profit)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}


void partition(job a[], ll low, ll high) {
    ll mid;
    if (low < high) {
        mid = (low + high) / 2;
        partition(a, low, mid);
        partition(a, mid + 1, high);
        mergesort(a, low, mid, high);
    }
}


int main() {
    ll n;
    cin >> n;
    // scanf("%d", &n);
    // ll i = -1;
    // ll i, max = -1, k;
    bool p[15000005] = {0};
    job j[n + 9];

    ll s, d;
    rep(i, n){
        cin >> s >> d;
        j[i].profit = s;
        j[i].deadline = d;
        // scanf("%d", &j[i].profit);
        // scanf("%d", &j[i].deadline);
    }

    partition(j, 0, n - 1);
    ll total = 0, temp;


    rep(i, n){
        temp = j[i].deadline;
        while (temp) {
            if (!p[temp]) {
                p[temp] = 1;
                total += j[i].profit;
                break;
            } else
                temp--;
        }
    }

    cout << total << '\n';
    return 0;
}