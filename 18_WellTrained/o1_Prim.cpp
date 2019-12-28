// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII; // weight and node, weight放前面是因為priority_queue用第一個來比大小
bool marked[MAX];
vector<PII> adj[MAX];

long long prim(int x) {
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x)); // 起點 weight 0 (還沒有跟別人相接)

    while (!Q.empty()) {
        // Select the edge with minimum weight
        p = Q.top(); // 每次都拿出weight最小的pop掉！
        // cout << "pop p=" << p.second << '\n';
        Q.pop();
        x = p.second; // 一開始是起點

        // Checking for cycle
        if (marked[x] == true)
            continue;
        marked[x] = true;

        minimumCost += p.first; // 一開始是起點, weight = 0
        cout << "minimumCost = " << minimumCost << ", p = " << p.first << '\n';

        // for loop 結束完才會回到while loop
        // Prim 會去 loop 當前點的鄰居
        for (int i = 0; i < (int)adj[x].size(); ++i) {
            y = adj[x][i].second; // x的第i個鄰居
            if (marked[y] == false)
                Q.push(adj[x][i]); // adj[x][i]是一個PI
                cout << "push y=" << y << '\n';
        }
    }
    return minimumCost;
}

int main() {
    int nodes, edges, existed, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges >> existed;

    for (int i = 0; i < edges; ++i) {
        cin >> x >> y >> weight;
        // 一個adj[]就可以用來紀錄相鄰點以及weight
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node

    // 初始化marked

    int counter = 0;
    // 把所有node開始for loop (等於隨機選擇起點找component)
    for (int i = 0; i < nodes; ++i) {
        if (!marked[i]){
            counter ++; // ssp個數
            minimumCost += prim(i);
        }
    }
    // minimumCost = prim(1);
    // int result = (minimumCost < existed) ? minimumCost : existed;
    cout << "minimumCost=" << minimumCost << endl;
    if (counter > 1){
        cout << minimumCost + existed*(counter-1) << '\n';
    }else{
        int res = (minimumCost < existed) ? minimumCost : existed;
        cout << res << '\n';
    }
    return 0;
}