# Knapsack 背包問題
- *Greedy didn't work for 0-1 Knapsack (only sorted by value/weight)*

# Notes
- 若不看時間限制，有 n!個不同的排法
- 對於一個排法t, 第j個job的完成時間是 Cj(t)= 第1到j-1個job的總時間 + jth job 自己的時間

# Related Problem
- [Task Scheduling - HackerRank](https://www.hackerrank.com/challenges/task-scheduling/problem)
- [Leo and Maximum Pay](https://www.hackerearth.com/challenges/college/nita-bitfreak-3/algorithm/leo-and-maximum-pay-4/)
- [Lecture #3 — Exchange arguments (sorting with dp)](https://codeforces.com/blog/entry/63533)
- [D - Zabuton](https://atcoder.jp/contests/cf17-final-open/tasks/cf17_final_d)

# C++ Notes
```
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
```