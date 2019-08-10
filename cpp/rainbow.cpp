#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int a[maxn][maxn],n,res,dd[maxn],dem;
void dfs(int pre,int u)
{
    if (dd[u]==1) return ;
    dem++;
    dd[u]=1;
    for (int i=1;i<=n;i++)
        if (i!=u&&i!=pre&&a[pre][u]!=a[u][i])
    {
        dfs(u,i);
    }
    else if (i!=u&&i!=pre)
    {
        dem--; return;
    }
}
int main()
{
    freopen("rainbow.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        res=0;
        test--;
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            cin>>a[i][j];
        for (int i=1;i<=n;i++)
            {
                dem=0;
                for (int j=1;j<=n;j++)
                    dd[j]=0;
                dfs(0,i);
                res=max(res,dem);
            }
        cout<<res<<"\n";
    }
    return 0;
}
