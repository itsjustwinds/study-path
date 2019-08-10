#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,a[505][505],win[maxn],ok,res,ans[505];
vector<int> e[maxn];
void dfs(int u)
{
    if (win[u]) return;
    win[u]=1;
    for (int i=0;i<(int)e[u].size();i++)
    dfs(e[u][i]);
}
int main()
{
    freopen("2008k.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j])
            {
                e[i].push_back(j);
                e[i].push_back(n+j);
            }
    for (int i=1; i<=n-1; i++)
        e[n+i]=e[i];
    for (int i=1;i<=n;i++)
    {
        ok=1;
        for (int j=1;j<=2*n-1;j++)
            win[j]=0;
        dfs(i);
        for (int j=1;j<=2*n-1;j++)
            if (!win[j])
        {
            ok=0;
            break;
        }
        if (ok)
        {
            ans[++res]=i;
        }
    }
    cout<<res<<"\n";
    for (int i=1;i<=res;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
