#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int deg[maxn],n,m,f,s,dd[maxn],dem,trace[maxn],res[maxn];
int q[maxn];
vector<int> w[maxn];
void bfs(int f,int s)
{
    int l=1,r=1;
    q[1]=f;
    dd[f]=1;
    while (l<=r)
    {
        int u=q[l];
        l++;
        for (int i=0;i<deg[u];i++)
        if (dd[w[u][i]]==0)
        {
            dd[w[u][i]]=1;
            r++;
            q[r]=w[u][i];
            trace[w[u][i]]=u;
            if (w[u][i]==s) return;
        }
    }
}
int main()
{
    freopen("bfs.inp","r",stdin);
    freopen("bfs.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>f>>s;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++;
        w[x].push_back(y);
    }
    bfs(f,s);
    int x=s;
    while (x!=0)
    {
        dem++;
        res[dem]=x;
        x=trace[x];
    }
    for (int i=dem;i>=1;i--)
        cout<<res[i]<<" ";
    return 0;
}
