#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int deg[maxn],n,m,res,dd[maxn];
vector<int> w[maxn];
void try1(int u)
{
    for (int i=0;i<deg[u];i++)
    if (dd[w[u][i]]==0)
    {
        dd[w[u][i]]=1;
        cout<<w[u][i]<<" ";
        try1(w[u][i]);
    }
}
int main()
{
    freopen("connect.inp","r",stdin);
    freopen("connect.out","w",stdout);
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
        res++;
        dd[i]=1;
        cout<<i<<" ";
        try1(i);
        cout<<"\n";
    }
    return 0;
}
