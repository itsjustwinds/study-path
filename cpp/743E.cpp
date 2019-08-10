#include<bits/stdc++.h>
#define maxn 1005
#define oo 1000000005
using namespace std;
int a[maxn],n,res,f[maxn],e[10][maxn],dem[maxn],dd[maxn][maxn],dp[maxn][maxn],power[maxn],sl[maxn][maxn];
int check(int m)
{
    if (m==0) return 1;
    for (int i=1;i<=255;i++) f[i]=oo;
    int cur[10];
    for (int i=1;i<=8;i++) cur[i]=0;
    f[0]=0;
    for (int i=1;i<=n;i++){
        int x=a[i];
        cur[x]++;
        int len;
        if (cur[x]>=m)len=e[x][cur[x]-m+1];
        else continue;
        for (int j=0;j<=255;j++)
        if (!(j&(1<<(x-1)))){
            if (f[j]>len) continue;
            int k=j|(1<<(x-1));
            if (f[k]>i)
            {
                f[k]=i;
            }
        }
    }
    if (f[255]!=oo) return 1;
     return 0;
}
int tinh(int m)
{
    if (m==0)
    {
            int ds=0;
        int dd2[10];
        memset(dd2,0,sizeof(dd2));
        for (int i=1;i<=n;i++)
            dd2[a[i]]=1;
        for (int i=1;i<=8;i++)
            ds+=dd2[i];
        return ds;
    }
    dd[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int x=0;x<=255;x++)
        {
            if (dd[x][i-1])
            {
                dd[x][i]=1;
                dp[x][i]=dp[x][i-1];
            }
            if (x&(1<<(a[i]-1)))
            {
                int y=x^(1<<(a[i]-1));
                int p=sl[a[i]][i]-m;
                if (p<0) continue;
                int j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]];
                j--;
                if (j<i&&dd[y][j]&&sl[a[i]][j]==p)
                {
                    dd[x][i]=1;
                    dp[x][i]=max(dp[x][i],dp[y][j]+m);
                }
                p=sl[a[i]][i]-m-1;
                if (p<0) continue;
                j=upper_bound(sl[a[i]]+1,sl[a[i]]+n+1,p)-sl[a[i]];
                j--;
                if (j<i&&dd[y][j]&&sl[a[i]][j]==p)
                {
                    dd[x][i]=1;
                    dp[x][i]=max(dp[x][i],dp[y][j]+m+1);
                }
            }
        }
    }
    return dp[255][n];
}
int main()
{
    freopen("743E.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=8;i++)
        power[1<<(i-1)]=i;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        e[a[i]][++dem[a[i]]]=i;
        for (int j=1;j<=8;j++)
            sl[j][i]=sl[j][i-1];
        sl[a[i]][i]++;
    }
    int l=0,r=n/8;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (check(m))
        {
            l=m+1;
            res=m;
        }
        else r=m-1;
    }
    cout<<tinh(res);
    return 0;
}
