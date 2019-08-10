#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,s,t,trc[maxn],sau[maxn];
long long d[maxn],D[maxn];
struct data
{
        int v;
        long long c;
};
vector<data > e[maxn],E[maxn];
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.c>b.c;
        }
};
void dijks2()
{
        priority_queue<data,vector<data>,cmp > q;
        for (int i=1;i<=n;++i)
                D[i]=1e18;
        D[t]=0;
        q.push({t,0});
        while(!q.empty())
        {
                int u=q.top().v;
                long long val=q.top().c;
                q.pop();
                if (val!=D[u]) continue;
                for (int i=0;i<E[u].size();++i)
                {
                        int v=E[u][i].v;
                        long long l=E[u][i].c;
                        if (D[u]+l<D[v])
                        {
                                D[v]=D[u]+l;
                                q.push({v,D[v]});
                        }
                }
        }
}
void dijks()
{
        priority_queue<data,vector<data>,cmp > q;
        for (int i=1;i<=n;++i)
                d[i]=1e18;
        d[s]=0;
        q.push({s,0});
        while(!q.empty())
        {
                int u=q.top().v;
                long long val=q.top().c;
                q.pop();
                if (val!=d[u]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        long long l=e[u][i].c;
                        if (d[u]+l<d[v])
                        {
                                d[v]=d[u]+l;
                                q.push({v,d[v]});
                        }
                }
        }
}
int main()
{
        freopen("MINPATH.inp","r",stdin);
        freopen("MINPATH.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                long long c;
                cin>>u>>v>>c;
                e[u].push_back({v,c});
                E[v].push_back({u,c});
        }
        cin>>s>>t;
        dijks();
        dijks2();
        cout<<d[t]<<"\n";
        cout<<s<<" ";
        int trc=-1;
        while(s!=t)
        {
                int u=1e9;
                for (int i=0;i<e[s].size();++i)
                {
                        int v=e[s][i].v;
                        if (v==trc) continue;
                        long long c=e[s][i].c;
                        if (d[s]+c+D[v]==d[t]&&v<u) u=v;
                }
                cout<<u<<" ";
                trc=s;
                s=u;
        }
        return 0;
}
