#include <bits/stdc++.h>
#define oo 1000000000
#define fs first
#define sc second
#define maxn 1005
using namespace std;
int deg[maxn],m,n,d[maxn],xp;
typedef pair<int,int> II;
vector<II> w[maxn];
void dijkstra(int i)
{
    priority_queue<II> q;
    d[i]=0;
    q.push(II(d[i],i));
    while(!q.empty())
    {
        int u=q.top().sc,du=-q.top().fs;
        q.pop();
        if (d[u]!=du) continue;
        for (int j=0; j<deg[u]; j++)
        {
            int v=w[u][j].sc;
            int uv=w[u][j].fs;
            if (d[v]>d[u]+uv)
            {
                d[v]=d[u]+uv;
                q.push(II(d[v],v));
            }
        }
    }
}
int main()
{
    freopen("shortest.inp","r",stdin);
    freopen("shortest.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int h=1; h<=t; h++)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++) d[i]=oo;
        for (int i=1; i<=n; i++) deg[i]=0;
        for (int i=1; i<=n; i++) w[i].clear();
        for (int i=1; i<=m; i++)
        {
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            w[u].push_back(II(6,v));
            w[v].push_back(II(6,u));
        }
        cin>>xp;
        dijkstra(xp);
        for (int i=1; i<=n; i++)
            if (i!=xp)
            {
                if (d[i]!=oo) cout<<d[i]<<" ";
                else cout<<-1<<" ";
            }
        cout<<"\n";
    }
    return 0;
}
