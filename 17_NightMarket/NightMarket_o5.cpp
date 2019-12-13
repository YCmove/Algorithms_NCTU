#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define MAX         100000
typedef long long ll;

vector<ll> edge[MAX+11], cost[MAX+11];
ll d[MAX+11], n;
queue<ll> q;
bool dil[MAX+11];
bool ign[MAX+11];
ll res = 0;

ll bfs(ll s, ll &dm)
{
    memset(d, -1, sizeof(d));
    d[s] = 0;
    ll u, v;

    q.push(s);
    while(!q.empty())
    {
        u = q.front(); q.pop();

        for(ll i = 0; i < (ll)edge[u].size(); i++)
        {
            v = edge[u][i];
            if(ign[v]) continue;

            if(d[v] == -1)
            {
                d[v] = cost[u][i] + d[u];
                q.push(v);
            }
        }
    }

    ll mx = 1;
    for(ll i = 1; i <= n; i++)
    {
        if(d[i] > d[mx])
            mx = i;
    }

    dm = d[mx];
    return mx;
}

bool dfs(ll idx, ll p = -1)
{
    ll i, v;
    bool ret = dil[idx];

    for(i = 0; i < (ll)edge[idx].size(); i++)
    {
        v = edge[idx][i];
        if(v == p) continue;
        ret |= dfs(v, idx);
    }

    ign[idx] = ret;
    return ret;
}

void go(ll idx, ll p = -1)
{
    ll i, v;

    for(i = 0; i < (ll) edge[idx].size(); i++)
    {
        v = edge[idx][i];
        if(v == p) continue;
        if(ign[v]) continue;

        res += 2 * cost[idx][i];
        go(v, idx);
    }
}

int main()
{

    ll i, g;
    ll u, v, w, idx;

    cin >> n;
    for(i = 1; i <= n; i++)
    {
        dil[i] = true; // 每個點的table
        idx = i;
    }
    // for(ll i = 1; i < n; i++)
    while (cin >> u >> v >> w)
    {
        // cin >> u >> v >> w;
        // cout << u << ' ' << v << ' ' << w << '\n';
        edge[u].pb(v);
        edge[v].pb(u);

        cost[u].pb(w);
        cost[v].pb(w);
    }

    dfs(idx);
    for(i = 1; i <= n; i++){
        ign[i] = 1 - ign[i];
    }

    go(idx);
    idx = bfs(idx, g);
    bfs(idx, g);

    cout << res - g << endl;

    return 0;
}



