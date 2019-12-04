#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

const int maxn = 1e5+5;
int n, m;
vector<int> graph[maxn];
vector<pair<int, int> > root_nodes; // {1~n, root_node}
bool visited[maxn] = {false};
int root_nodes_counts[maxn];
int parent[maxn];
// int counts[maxn] = {1}; 行不通
// int counts[maxn];

int root_node;

void dfs(int node){
    visited[node] = true;
    root_nodes.push_back(make_pair(node, root_node));
    // cout << "1. root_nodes_counts[root_node] = " << root_nodes_counts[root_node] << '\n';
    root_nodes_counts[root_node] += 1;
    // cout << "2. root_nodes_counts[root_node] = " << root_nodes_counts[root_node] << '\n';
    // counts[node] += 1;
    // cout << "counts[node] = " << counts[node] << '\n';

    for (auto itr : graph[node]){
        if (itr == parent[node]){
            continue;
        }
        if (!visited[itr]) {
            parent[itr] = node;
            dfs(itr);
            // counts[node] += 1;
        }
    }


}


int main(){
    cin >> n >> m;


    int a, b;
    rep(i, m){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // cout << "counts[1] = " << counts[1] << '\n';

    // for (int i = 1; i <= n; ++i){
    //     counts[i] = 1;
    // }

    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            root_node = i;
            // cout << "root_node: " << root_node << '\n'; 
            root_nodes_counts[root_node] = 0;
            dfs(i);
        }
    }

    sort(root_nodes.begin(), root_nodes.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    
    for (auto itr : root_nodes){
        cout << root_nodes_counts[itr.second] - 1 << '\n';
        // cout << counts[i] << ' ';
    }

    return 0;
}