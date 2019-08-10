#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
ll f[maxn][maxn];
vector<int > e[maxn];
int dd[maxn],c[maxn][maxn],n,m,test;
struct data
{
        int u;
        ll c;
};
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.c>b.c;
        }
};
void dijks(int x)
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        f[x][x]=0;
        q.push({x,0});
        while(!q.empty())
        {
                int u=q.top().u;
                q.pop();
                for (int i=0; i<e[u].size(); ++i)
                {
                        int v=e[u][i];
                        if (f[x][u]+c[u][v]<f[x][v])
                        {
                                f[x][v]=f[x][u]+c[u][v];
                                if (dd[v]) q.push({v,f[x][v]});
                        }
                }
        }
}
int main()
{
        freopen("DHSERV.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>test;
        for (int i=1; i<=m; ++i)
        {
                int u,v,val;
                cin>>u>>v>>val;
                c[u][v]=val;
                e[u].push_back(v);
        }
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                        f[i][j]=1e18;
        for (int i=1; i<=n; ++i)
                dijks(i);
        while(test--)
        {
                int x,u,v;
                cin>>x;
                if (x==1)
                {
                        cin>>u;
                        dd[u]=1;
                        for (int i=1; i<=n; ++i)
                                for (int j=1; j<=n; ++j)
                                        f[i][j]=1e18;
                        for (int i=1; i<=n; ++i)
                                dijks(i);
                        continue;
                }
                cin>>u>>v;
                if (f[u][v]!=1e18) cout<<f[u][v]<<"\n";
                else cout<<"-1\n";
        }
}
