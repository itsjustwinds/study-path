#include <bits/stdc++.h>
#define maxn 5005
#define fs first
#define sc second
#define oo 1000000000
using namespace std;
int deg[maxn],n,m,c[maxn];
typedef pair<int,int> II;
vector<II> w[maxn];
int dd[maxn],d[maxn];
set<II> q;
void dijkstra(int f,int s)
{
    for (int i = 1; i <= n; ++i)
        d[i] = oo;
    d[f] = 0;
    q.insert(II(0, f));
    while (!q.empty())
    {
        II t=*q.begin();
        int u = t.sc, du = t.fs;
        q.erase(q.begin());
        if (du != d[u]) continue;
        for (int i = 0; i < deg[u]; ++i)
        {
            int v = w[u][i].sc, dv = w[u][i].fs;
            if (d[v] > d[u] + dv)
            {
                d[v] = d[u] + dv;
                c[v] = c[u];
                q.insert(II(d[v], v));
            }
            else if (d[v] == d[u] + dv)
            {
                c[v] += c[u];
            }
        }
    }
}
int main()
{
    freopen("qbschool.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int k,x,y,l;
        cin>>k>>x>>y>>l;
        if (k==1)
        {
            deg[x]++;
            w[x].push_back(II(l,y));
        }
        else
        {
            deg[x]++;
            deg[y]++;
            w[x].push_back(II(l,y));
            w[y].push_back(II(l,x));
        }
    }
    c[1]=1;
    for (int i=1; i<=n; i++) d[i]=oo;

    dijkstra(1,n);
    cout<<d[n]<<" "<<c[n];
}
