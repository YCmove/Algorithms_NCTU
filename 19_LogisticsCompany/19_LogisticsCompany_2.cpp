#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long ll;

int n, m, q;
const int MAXN = 500+1;
const int MAXK = 1e8;
// n: number of intersections
// m: the number of roads
// q: the number of the Demon Slayers 
#define PI pair<ll, int>
vector<PI> digraph[MAXN];
bool visited[MAXN];
ll dist[MAXN];
ll back_dist[MAXN];

bool comp(PI a, PI b){
    return a.ff < b.ff;
}


void dijkstra(int node, bool is_back, ll * dist){
    priority_queue<PI, vector<PI>, greater<PI> > pq;
    pq.push(mp(0, node)); // 第一個vertex, 還不用考慮任何weight
    visited[node] = true;

    if (is_back && node == 0){
        return;
    }

    while(!pq.empty()){
        PI p = pq.top();
        pq.pop();
        // cost += p.ff;
        visited[p.ss] = true;
        if (is_back && p.ss == 0){
            // cout << "Reach 0 - return" << '\n';
            return;
        }
        // cout << " ## Marked new vertex ## : " << dist[p.ss] << ", " << p.ss << '\n';
        if (p.ff > dist[p.ss]) continue;

        for (int j = 0; j < (int)digraph[p.ss].size(); ++j){
            PI neighbor = digraph[p.ss][j];
            // cout << "Loop over neighbors: (" << neighbor.ff << ", " << neighbor.ss << ")\n";
            // cout << "origin dist[neighbor.ss]=" << dist[neighbor.ss] << ", p.ff=" << p.ff << ", neighbor.ff=" << neighbor.ff << '\n';
            if (dist[neighbor.ss] < p.ff + neighbor.ff){
                // cout << "Don't update" << '\n';
                continue;
            } else {
                // update the dist to smallar one
                dist[neighbor.ss] = dist[p.ss] + neighbor.ff;
                // cout << "Update distance, dist[neighbor.ss]=" << dist[neighbor.ss] << ", p.ff=" << p.ff << ", neighbor.ff=" << neighbor.ff << '\n';
                
                if (!visited[neighbor.ss]){
                    // Relax Operation
                    // cout << "Update distance - push to queue" << '\n';
                    pq.push(mp(neighbor.ff, neighbor.ss));
                }
            }
            
        }
    }

    
}


void init(int start_node, ll * dist){
    for (int i=0; i <= n;++i){
        visited[i] = false;
        dist[i] = MAXK;
    }
    dist[start_node] = 0;
}


int main(){
    cin >> n >> m;

    int a, b, k;
    for(int i=0; i< m; ++i){
        cin >> a >> b >> k;
        digraph[a].pb(mp(k, b));
    }

    // cout << "here" << '\n';
    // position of Demon Slayers
    // 找 a, b 兩點間的shortest path
    ll min_cost = 0;
    for(int i = 1; i <= n; ++i){
        init(0, dist);
        // cout << "****** dijkstra(a) ******" << '\n';
        dijkstra(0, false, dist);
    }

    for(int i = 1; i <= n; ++i){
        // init(0, dist);
        // // cout << "****** dijkstra(a) ******" << '\n';
        // dijkstra(0, false);
        // ll costb = dist[i];
        // // cout << "**** dist[0]=" << dist[0] << ", dist[i]=" << dist[i] << " ****" << '\n';
        init(i, back_dist);
        // cout << "****** dijkstra(b) ******" << '\n';
        dijkstra(i, true, back_dist);
        ll costa = back_dist[0];
        // cout << "**** dist[0]=" << dist[0] << ", dist[i]=" << dist[i] << " ****" << '\n';
        min_cost += (costa + dist[i]);
        // cout << "i=" << i << ", cost=" << costa + costb << "\n\n";
        
    }
    if (min_cost >= MAXK){
        cout << "-1" << '\n';
    } else {
        cout << min_cost << "\n";
    }


    return 0;
}