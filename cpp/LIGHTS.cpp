#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int> m;
typedef pair<ll,int> II;
II f[10000007];
int n,m;
vector<int> e[maxn];
int getbit(int n,int k)
{
    return (n>>(k-1))&1;
}
int change(int n,int k,int t)
{
    if (t==0)
    {
        int tmp=getbit(n,k)<<(k-1);
        return n^tmp;
    }
        int tmp=((1-getbit(n,k))<<(k-1));
        return n^tmp;
}
void dfs1(ll mask,int dem,int i)
{
    if (i==m+1)
    {
        m[mask]=min(m[mask],dem);
        return 0;
    }
    dfs1(mask,dem,i+1);
    int tmp=mask;
    for (int j=0;j<(int)e[i].size();j++)
    {
        int u=e[i][j];
        mask=change(mask,u,1-getbit(mask,u));
    }
    dfs1(mask,dem+1,i+1);
}
int main()
{
    freopen("LIGHTS.inp","r",stdin);
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
    m=n/2;
    dfs1(0,0,1);
}
