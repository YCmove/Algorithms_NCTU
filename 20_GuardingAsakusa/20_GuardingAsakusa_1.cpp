#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long ll;

int n, m, q;
const int MAXN = 500+1;
// n: number of intersections
// m: the number of roads
// q: the number of the Demon Slayers 
#define PI pair<ll, int>
vector<PI> digraph[MAXN];
bool visited[MAXN];
ll dist[MAXN];

bool comp(PI a, PI b){
    return a.ff < b.ff;
}


void dijkstra(int node){
    priority_queue<PI, vector<PI>, greater<PI> > pq;
    pq.push(mp(0, node)); // 第一個vertex, 還不用考慮任何weight
    visited[node] = true;

    while(!pq.empty()){
        PI p = pq.top();
        pq.pop();
        // cost += p.ff;
        visited[p.ss] = true;
        cout << "Marked new vertex: " << p.ff << ", " << p.ss << '\n';
        if (p.ff > dist[p.ss]) continue;

        for (int j = 0; j < (int)digraph[p.ss].size(); ++j){
            PI neighbor = digraph[p.ss][j];
            cout << "Loop over neighbors: (" << neighbor.ff << ", " << neighbor.ss << ")\n";
            cout << "dist[neighbor.ss]=" << dist[neighbor.ss] << ", p.ff=" << p.ff << ", neighbor.ff=" << neighbor.ff << '\n';
            if (dist[neighbor.ss] < p.ff + neighbor.ff){
                cout << "Nothing here" << '\n';
                continue;
            } else {
                cout << "Update distance" << '\n';
                // update the dist to smallar one
                dist[neighbor.ff] = p.ff + neighbor.ff;
                if (!visited[neighbor.ss]){
                    // Relax Operation
                    pq.push(mp(neighbor.ff, neighbor.ss));
                }
            }
        }
    }

    
}


void init(int start_node){
    for (int i=0; i <= n;++i){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[start_node] = 0;
}


int main(){
    cin >> n >> m >> q;

    int a, b, k;
    for(int i=0; i< m; ++i){
        cin >> a >> b >> k;
        digraph[a].pb(mp(k, b));
    }

    // cout << "here" << '\n';
    // position of Demon Slayers
    // 找 a, b 兩點間的shortest path
    for(int i=0; i< q; ++i){
        cin >> a >> b;
        init(a);
        dijkstra(a);
        cout << "****** dijkstra(a) ******" << '\n';
        cout << "dist[a]=" << dist[a] << ", dist[b]=" << dist[b] << '\n';
        cout << "************" << '\n';
        init(b);
        dijkstra(b);
        cout << "****** dijkstra(b) ******" << '\n';
        cout << "dist[a]=" << dist[a] << ", dist[b]=" << dist[b] << '\n';
        cout << "************" << '\n';
        ll min_cost = (dist[a] < dist[b] ? dist[a] : dist[b]);

        if (min_cost < INT_MAX){
            cout << min_cost << '\n';
        } else {
            cout << "-1" << '\n';
        }
        
    }


    return 0;
}