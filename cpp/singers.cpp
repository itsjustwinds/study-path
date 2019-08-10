#include<bits/stdc++.h>
#define pb push_back
#define maxn 100005
using namespace std;
int f[maxn],n,m,dd[maxn],dem;
vector<int> e[maxn];
void dfs(int u)
{
    if (dd[u]) return;
    dd[u]=1;
    f[dem]++;
    for (int i=0;i<int(e[u].size());i++)
    {
        int v=e[u][i];
        dfs(v);
    }
}
int main()
{
    freopen("singers.inp","r",stdin);
    freopen("singers.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if (!dd[i])
    {
        dem++;
        dfs(i);
    }
    if (dem==1)
    {
        cout<<0;
        return 0;
    }
    long long res=0,sum=f[1];
    for (int i=2;i<=dem;i++)
    {
        res+=f[i]*sum;
        sum+=f[i];
    }
    cout<<res;
    return 0;
}
