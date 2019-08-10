#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int deg[maxn],n,m,max1,max2,res,dd[maxn];
vector<int> w[maxn];
void try1(int u)
{
    for (int i=0;i<deg[u];i++)
    if (dd[w[u][i]]==0)
    {
        int v=w[u][i];
        dd[v]=1;
        res++;
        try1(v);
    }
}
int main()
{
    freopen("invest.inp","r",stdin);
    freopen("invest.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        w[x].push_back(y);
        w[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
        if (dd[i]==0)
    {
        res=1;
        dd[i]=1;
        try1(i);
        if (res>max1) max1=res;
        else if (res>max2) max2=res;
    }
    cout<<max1+max2;
    return 0;
}
