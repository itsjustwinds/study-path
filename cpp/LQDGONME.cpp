#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int d[20][maxn],a[20][maxn],n,m,f[maxn];
int check(int i,int j)
{
        for (int k=1;k<=m;k++)
        {
                if (d[k][i]>d[k][j]) return 0;
        }
        return 1;
}
int main()
{
        freopen("LQDGONME.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;i++)
        {
                for (int j=1;j<=n;j++)
                {
                        cin>>a[i][j];
                        d[i][a[i][j]]=j;
                }
        }
        int res=0;
        for (int i=1;i<=n;i++)
        {
                for (int j=0;j<i;j++)
                {
                        if (!check(a[1][j],a[1][i])) continue;
                        f[i]=max(f[i],f[j]+1);
                }
                res=max(res,f[i]);
        }
        cout<<res;
}
