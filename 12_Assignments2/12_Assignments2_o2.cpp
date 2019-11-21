// https://www.hackerrank.com/challenges/task-scheduling/leaderboard
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define NMAX 300000
#define NN 100000
#define INF 1000000000LL
using namespace std;

typedef long long LL;

struct N {           //data to store in tree
    LL each, maxsub; //operation load.log update.,subtree statistic(calculate sub tree status in every update)
    N() {
        each = 0;
        maxsub = -INF;
    }
};

N st[NMAX];

void update2(int ni, int s, int e, int ps, int pe, LL v) {
    if (ps > pe) return;
    if (pe < s || ps > e)
        return;
    else if (ps <= s && pe >= e) { //update all
        st[ni].each += v; // time
    } else {
        int mid = (s + e) / 2;
        update2(ni * 2 + 1, s, mid, ps, min(mid, pe), v);
        update2(ni * 2 + 2, mid + 1, e, max(mid + 1, ps), pe, v);
        LL sub1 = st[ni * 2 + 1].each;
        LL sub2 = st[ni * 2 + 2].each;

        if (mid > s) {
            // all in right tree
            sub1 += st[ni * 2 + 1].maxsub;
        };

        if (mid + 1 < e) {
            // all in left tree
            sub2 += st[ni * 2 + 2].maxsub;
        };
        st[ni].maxsub = max(sub1, sub2);
    }
}

LL query2(int ni, int s, int e, int ps, int pe) {
    if (ps > pe) return -INF;
    if (pe < s || ps > e)
        return -INF;
    else if (ps <= s && pe >= e) { //get all segment
        if (s == e)
            return st[ni].each;
        else
            return st[ni].maxsub + st[ni].each;
    } else {
        int mid = (s + e) / 2;
        return max(query2(2 * ni + 1, s, mid, ps, min(pe, mid)), query2(2 * ni + 2, mid + 1, e, max(ps, mid + 1), pe)) + st[ni].each;
    }
}

int main() {
    for (LL i = 0; i <= NN; i++) {
        // void update2(int ni, int s, int e, int ps, int pe, LL v)
        update2(0, 0, NN, i, i, -i);
    }
    int nn;
    scanf("%d", &nn);
    for (int i = 0; i < nn; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        // void update2(int ni, int s, int e, int ps, int pe, LL v)
        update2(0, 0, NN, a, NN, b);
        LL ret = max(0LL, query2(0, 0, NN, 0, NN));
        printf("%lld\n", ret);
    }
    return 0;
}