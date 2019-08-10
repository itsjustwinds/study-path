#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
int d[2][maxn],n,m,g[2][maxn];
struct data
{
        int v,c;
};
vector<data >e[maxn];
vector<int >res;
struct cmp
{
        bool operator()(data a,data b)
        {
                return a.c>b.c;
        }
};
void dijkstra(int st)
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        if (st==0)
        {
                d[st][1]=0;
                q.push({1,0});
                g[st][1]=1;
        }
        else
        {
                d[st][n]=0;
                q.push({n,0});
                g[st][n]=1;
        }
        while(!q.empty())
        {
                int u=q.top().v;
                int c=q.top().c;
                q.pop();
                if (c!=d[st][u]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        int l=e[u][i].c;
                        if (d[st][u]+l<d[st][v])
                        {
                                d[st][v]=d[st][u]+l;
                                g[st][v]=1;
                                q.push({v,d[st][v]});
                        }
                        else if (d[st][u]+l==d[st][v]) g[st][v]+=g[st][u];
                }
        }
}
int main()
{
        freopen("CENTRE28.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                e[u].push_back({v,c});
                e[v].push_back({u,c});
        }
        for (int i=1;i<=n;++i)
                for (int j=0;j<=1;++j)
                d[j][i]=1e9;
        dijkstra(0);
        dijkstra(1);
        for (int i=1;i<=n;++i)
                if (d[0][i]+d[1][i]!=d[0][n]||g[0][i]*g[1][i]<g[0][n])
                {
                        res.push_back(i);
                }
        cout<<res.size()<<"\n";
        for (int i=0;i<res.size();++i)
                cout<<res[i]<<"\n";
}
