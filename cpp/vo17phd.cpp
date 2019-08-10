#include <bits/stdc++.h>
#define maxn 100005
#define long long long
#define oo 100000000000005LL;
#define fs first
#define sc second
using namespace std;
typedef pair<long,int> II;
long d[maxn],dd[maxn],x[maxn],b[maxn],m;
int n,deg[maxn];
vector <II> s[maxn];
void dijks()
{
    priority_queue<II,vector<II>,greater<II> > q;
    for (int i=2;i<=n;i++)
        d[i]=oo;
    d[1]=0;
    x[1]=b[1];
    q.push(II(d[1],1));
    while(!q.empty())
    {
        II tmp=q.top();
        q.pop();
        int u=tmp.sc;
        dd[u]=1;
        if (u==n)
        {
            cout<<d[u]<<" "<<x[u];
            return;
        }
        for (int j=0;j<deg[u];j++)
        {
            long l=s[u][j].fs;
            int v=s[u][j].sc;
            if (dd[v]==0&&d[u]+l<=d[v])
            {
                if (d[u]+l<d[v])
                {
                    d[v]=d[u]+l;
                    x[v]=x[u]+b[v];
                    q.push(II(d[v],v));
                }
                else x[v]=max(x[v],x[u]+b[v]);
            }
        }
    }
    cout<<"impossible";
    return ;
}
int main()
{
    //freopen("vo17phd.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>b[i];
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        deg[u]++;
        deg[v]++;
        s[u].push_back(II(c,v));
        s[v].push_back(II(c,u));
    }
    dijks();
    return 0;
}

