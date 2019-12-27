#include<cstdio>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#define INF 0x3f3f3f3f
#define MAXN 2*(30011+1000)
using namespace std; 
int n,m;
struct Edge{
    int u,v,c,f;
};
struct Dinic
{
    int s,t;
    vector<Edge> E;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int lev[MAXN];
    int cur[MAXN];
    void init(int n) 
    {
        E.clear();
        for(int i=0;i<=n;i++) G[i].clear();
    }
    void addedge(int from,int to,int cap)
    {
        cout << "[addedge] from=" << from << ", to=" << to << ", cap=" << cap << '\n';
        E.push_back((Edge){from,to,cap,0});
        E.push_back((Edge){to,from,0,0});
        G[from].push_back(E.size()-2);
        G[to].push_back(E.size()-1);
    }
    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        lev[s]=0;
        vis[s]=1;
        // cout << "bfs - q.empty()=" << q.empty() << '\n';
        while(!q.empty())
        {
            int now=q.front(); q.pop();
            cout << "Inside bfs() while , now=" << now << ", G[now].size()=" << G[now].size() << '\n';

            for(int i=0;i<(int)G[now].size();i++)
            {
                Edge edge=E[G[now][i]];
                int nex=edge.v;
                cout << "nex=" << nex << ", edge.c=" << edge.c << ", edge.f=" << edge.f << '\n';
                if(!vis[nex] && edge.c>=edge.f)
                {
                    lev[nex]=lev[now]+1;
                    q.push(nex);
                    vis[nex]=1;
                }
            }
        }
        cout << "return bfs() vis[t]=" << vis[t] << '\n';
        return vis[t];
    }
    int dfs(int now,int aug)
    {
        if(now==t || aug==0) return aug;
        int flow=0,f;
        for(int& i=cur[now];i<(int)G[now].size();i++)
        {
            Edge& edge=E[G[now][i]];
            int nex=edge.v;
            if(lev[now]+1 == lev[nex] && (f=dfs(nex,min(aug,edge.c-edge.f)))>0)
            {
                edge.f+=f;
                E[G[now][i]^1].f-=f;
                flow+=f;
                aug-=f;
                if(!aug) break;
            }
        }
        return flow;
    }
    int maxflow()
    {
        cout << "run maxflow" << '\n';
        int flow=0;
        while(bfs())
        {
            cout << "run maxflow bfs()" << '\n';
            memset(cur,0,sizeof(cur));
            cout << "flow=" << flow << '\n';
            flow+=dfs(s,INF);
        }
        return flow;
    }
}dinic;
int in(int x){return x;}
int out(int x){return x+n;}
int main()
{
    // int t;
    // scanf("%d",&t);
    // while(t--)
    // {
    scanf("%d%d",&n,&m);
    // dinic.init(2*n+2);
    dinic.init(n);
    for(int i=1;i<=m;i++)
    {
        int from,to;
        scanf("%d%d",&from,&to);
        // from++;
        // to++;
        cout << "from=" << from << ", to=" << to << '\n';
        // if(1<=from && from<=n && 1<=to && to<=n)
        // {
        dinic.addedge(out(from),in(to),1);
        dinic.addedge(out(to),in(from),1);
        // }
    }
    // dinic.s=0, dinic.t=2*n+2;
    dinic.s=0, dinic.t=n-1;
    // dinic.addedge(dinic.s,dinic.t,1);
    // dinic.addedge(dinic.t,dinic.s,1);

    cout << "Add s and t edges" << '\n';
    // dinic.addedge(dinic.s,in(1),1);
    // dinic.addedge(out(n),dinic.t,1);

    // for(int i=1;i<=n;i++) dinic.addedge(in(i),out(i),i==2?2:1);

    // if(dinic.maxflow()==2) printf("YES\n");
    // else printf("NO\n");
    cout << "maxflow=" << dinic.maxflow() << '\n';
    // }
} 