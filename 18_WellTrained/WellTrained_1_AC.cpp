#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;
typedef pair<ll, int> pi; // {weight, start node}

const int MAXN = 1e5+5;
bool isvisited[MAXN] = {false};
vector<pi> weight_graph[MAXN];

int n, m, w;

int prim(int node){
    // cout << "Enter Prim node=" << node << '\n';
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    ll min_weight = 0;
    // int cnt = 0;

    pq.push(make_pair(0, node));
    while(!pq.empty()){
        // cout << "========== Start pq ==========" << '\n';
        pi cur = pq.top();
        pq.pop();
        // cnt += w;

        if(isvisited[cur.second]){
        // cout << "Skip cur.second=" << cur.second << ", cur.first=" << cur.first << '\n';
            continue;
        }

        // cout << "mark visited cur.second=" << cur.second << ", cur.first=" << cur.first << '\n';
        isvisited[cur.second] = true;
        // min_weight += cur.first;
        min_weight += (w < cur.first)? w : cur.first;
        // cout << "min_weight=" << min_weight << '\n';

        int n = weight_graph[cur.second].size();

        // cout << "-------- cur.second=" << cur.second << ", weight_graph[cur.second].size()=" << n << " -------" << '\n';
        rep(i, n){
            pi neighbor = weight_graph[cur.second][i];
            // cout << "cur.second=" << cur.second << ", push neighbor.first=" << neighbor.first << ", push neighbor.second=" << neighbor.second << ", isvisited[neighbor.second]=" << isvisited[neighbor.second] << '\n';
            if(!isvisited[neighbor.second]){
                // cout << "[pushed in] ";
                pq.push(weight_graph[cur.second][i]);
                // cout << "current pq.top().second=" << pq.top().second << ", pq.top().first=" << pq.top().first <<  '\n';
            }
        }
        // cout << "---------------" << '\n';

        // cout << "min_weight=" << min_weight << '\n';
    }
    // cout << "Final min_weight=" << min_weight << ", cnt=" << cnt << '\n';
    // return (cnt < min_weight)? cnt : min_weight;
    return min_weight;
}




int main(){
    cin >> n >> m >> w;

    int a;
    int b;
    ll k;
    rep(i, m){
        cin >> a >> b >> k;
        // cout << "a=" << a << ", b=" << b << '\n';
        // k 放在 pair.first 為了priority_queue的排序
        weight_graph[a].push_back(make_pair(k, b));
        weight_graph[b].push_back(make_pair(k, a));
    }

    int counter = 0;

    // rep(i, n){
    //     if(weight_graph[i].size() == 0){
    //         // cout << "new i=" << i << '\n';
    //         counter +=1;
    //         weight_graph[i].push_back(make_pair(9*1e10, i));
    //     }
    // }

    // cout << "0: ";
    // // for(auto itr = weight_graph[0].begin(); itr < weight_graph[0].end(); ++itr){
    // for (auto itr : weight_graph[0]){
    //     cout << "(" <<itr.first << ", " <<  itr.second << ") / ";
    // }

    // cout << "\n1: ";
    // // for(auto itr = weight_graph[0].begin(); itr < weight_graph[0].end(); ++itr){
    // for (auto itr : weight_graph[1]){
    //     cout << "(" <<itr.first << ", " <<  itr.second << ") / ";
    // }

    // cout << "\n2: ";
    // // for(auto itr = weight_graph[0].begin(); itr < weight_graph[0].end(); ++itr){
    // for (auto itr : weight_graph[2]){
    //     cout << "(" <<itr.first << ", " <<  itr.second << ") / ";
    // }
    // return 0;

    int prim_res = 0;
    rep(i, n){
        if (!isvisited[i]){
            counter += 1;
            // cout << "Start new i=" << i << '\n';
            prim_res += prim(i);
        }
    }
    // cout << "prim_res=" << prim_res << ", counter=" << counter << '\n';
    if (counter > 1){
        int res = ((w*(n-1)) < (prim_res + w*(counter-1))) ? w*(n-1) : prim_res + w*(counter-1);
        // cout << "[w*(counter-1)] " << w*(counter-1) << '\n';
        // cout << "[prim_res + w*(counter-1)] " << prim_res + w*(counter-1) << '\n';
        cout << res << '\n';
    }else{
        // int res = (prim_res < w) ? prim_res : w;
        int res = (w*(n-1) < prim_res) ? w*(n-1) : prim_res;
        cout << res << '\n';
    }



    return 0;
}