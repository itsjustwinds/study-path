#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,k,deg[maxn],trace[maxn],res,dd[maxn];
vector<int> w[maxn];
void try1(int u)
{
    for (int i=0;i<deg[u];i++)
    if (dd[w[u][i]]==0)
    {
        dd[w[u][i]]=1;
        res++;
        try1(w[u][i]);
    }
}
int main()
{
    freopen("ebola.inp","r",stdin);
    freopen("ebola.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for (int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            deg[i]++;
            w[i].push_back(x);
        }
    }
    res=1;
    dd[k]=1;
    try1(k);
    cout<<res<<"\n";
    for (int i=1;i<=n;i++)
        if (dd[i]==1)
        cout<<i<<" ";
    return 0;
}
