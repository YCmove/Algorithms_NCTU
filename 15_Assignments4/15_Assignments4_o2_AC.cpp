#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

const long long maxn = 300015;

struct dqs {
    long long jz, nl;
} hh[maxn];

bool comp(dqs a, dqs b) {
    return a.jz > b.jz;
}

priority_queue<dqs> q;

bool operator<(dqs a, dqs b) {
    return a.nl < b.nl;
}


int main() {
    long long n, ans = 0, maxx = -1, now = 1;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        scanf("%d%d", &hh[i].nl, &hh[i].jz);
        maxx = max(maxx, hh[i].jz);
    }

    sort(hh + 1, hh + n + 1, comp);

    for (long long i = maxx; i >= 1; i--) {
        while (hh[now].jz == i) {
            q.push(hh[now]);
            now++;
        }
        if (!q.empty()) {
            ans += q.top().nl;
            q.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}