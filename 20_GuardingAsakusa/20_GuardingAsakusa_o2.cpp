#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;


ll ans[501][501];
ll dist[501][501];

vector<ll> adj[501];

void bfs(ll node, ll n){
    
    priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> >> pq;
    
    ll visited[n+2] = {0};
    
    pq.push({0,node});
    
    while(!pq.empty()){
        
        pair<ll,ll> x = pq.top();
        pq.pop();
        
        ll c = x.first;
        ll u = x.second;
        
        if(visited[u])continue;
        
        visited[u] = 1;
        ans[node][u] = c;
        
        for(ll i=0;i<(ll)adj[u].size();i++){
            ll v = adj[u][i];
            if(dist[u][v]!=1e9&&!visited[v]){
                pq.push({max(c, dist[u][v]), v});
            }
        }
    }
}






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,m,q;
    scanf("%lld %lld %lld", &n, &m, &q);
    // cin>>n>>m>>q;
    // cout << "n=" << n << ", m=" << m << ", q=" << q << '\n';
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            dist[i][j]=1e9;
            ans[i][j]=-1;
        }
        dist[i][i]=0; // 對角線
    }
    
    for(ll i=1;i<=m;i++){
        ll x,y,c;
        scanf("%lld %lld %lld", &x, &y, &c);
        // cin>>x>>y>>c;
        dist[x][y] = min(dist[x][y], c);
        adj[x].push_back(y);
    }
    
    for(ll i=0;i<n;i++){
        bfs(i,n);
    }
    
    for(ll i=1;i<=q;i++){
        ll x,y;
        scanf("%lld %lld", &x, &y);
        // cin>>x>>y;
        // cout << "x=" << x << ", y=" << y << '\n';
        
        if(ans[x][y]==-1 || ans[y][x] ==-1){
            cout<<-1<<"\n";
        }else{
            cout<<max(ans[x][y],ans[y][x])<<"\n";
        }
    }
    
	// your code goes here
	return 0;
}