#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn*maxn],a[maxn][maxn],n,m,now,res;
void dfs(int i,int j)
{
    if (i<0||i>n||j<0||j>m) return;
    if (a[i][j]!=1) return;
    f[now]++;
    a[i][j]=now;
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i,j-1);
}
int main()
{
    freopen("black.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    now=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]==1)
            {
                now++;
                dfs(i,j);
            }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            int tmp1=a[i-1][j];
            int tmp2=a[i][j+1];
            int tmp3=a[i+1][j];
            int tmp4=a[i][j-1];
            int tmp=1;
            tmp+=f[tmp1];
            if (tmp2!=tmp1)
                tmp+=f[tmp2];
            if (tmp3!=tmp2&&tmp3!=tmp1)
                tmp+=f[tmp3];
            if (tmp4!=tmp3&&tmp4!=tmp2&&tmp4!=tmp1)
                tmp+=f[tmp4];
            res=max(res,tmp);
        }
    cout<<res;
    return 0;
}
