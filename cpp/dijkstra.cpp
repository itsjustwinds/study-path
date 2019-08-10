#include <bits/stdc++.h>
#define fs first
#define sc second
#define oo 1000000000
#define maxn 100005
using namespace std;
int n,m,f,s,deg[maxn],dd[maxn],d[maxn],pre[maxn],k;
typedef pair<int,int> II;
vector<II> w[maxn];
set<II> q;
void dijkstra(int f,int s)
{
    dd[f]=1;
    d[f]=0;
    k=1;
    q.insert(II(d[f],f));
    while (!q.empty())
    {
        II t=*q.begin();
        q.erase(t);
        int u=t.sc;
        if (u==s) return;
        for (int i=0; i<deg[u]; i++)
        {
            int l=w[u][i].sc;
            int v=w[u][i].fs;
            if (dd[v]==0&&d[v]>d[u]+l)
            {
                dd[v]=1;
                d[v]=d[u]+l;
                pre[v]=u;
                q.insert(II(d[v],v));
            }
        }
    }
}
int main()
{
    freopen("dijkstra.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>f>>s;
    for (int i=1; i<=m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        deg[x]++;
        w[x].push_back(II(y,c));
    }
    for (int i=1; i<=n; i++)
        d[i]=oo;
    dijkstra(f,s);
    cout<<d[s]<<"\n";
    int h=s;
    while (pre[h])
    {
        cout<<h<<" ";
        h=pre[h];
    }
    cout<<f;
    return 0;
}
