#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int a[maxn],n,pmax[maxn][35],f[maxn],ans,dp[maxn],pmin[maxn][35],k;
int maxx(int i,int j)
{
        int log=log2(j-i+1);
        return max(pmax[i][log],pmax[j-(1<<log)+1][log]);
}
int minn(int i,int j)
{
        int log=log2(j-i+1);
        return min(pmin[i][log],pmin[j-(1<<log)+1][log]);
}
int main()
{
        freopen("KDIFF.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;i++)
                cin>>a[i];
        for (int i=1;i<=n;i++)
                pmax[i][0]=a[i];
        for (int i=1;i<=n;i++)
                pmin[i][0]=a[i];
        for (int j=1;1<<j<=n;j++)
        {
                for (int i=1;i+(1<<j)-1<=n;i++)
                {
                        pmax[i][j]=max(pmax[i][j-1],pmax[i+(1<<(j-1))][j-1]);
                }
        }
        for (int j=1;1<<j<=n;j++)
        {
                for (int i=1;i+(1<<j)-1<=n;i++)
                {
                        pmin[i][j]=min(pmin[i][j-1],pmin[i+(1<<(j-1))][j-1]);
                }
        }
        dp[1]=1;
        for (int i=2;i<=n;i++)
        {
                for (int j=dp[i-1];j<=i;j++)
                {
                        if (maxx(j,i)-minn(j,i)>k) continue;
                        dp[i]=j;
                        f[i]=i-j+1;
                        break;
                }
        }
        for (int i=1;i<=n;i++)
        {
                if (f[i]==i) ans=max(ans,f[i]);
                else ans=max(ans,f[i]+f[i-f[i]]);
                f[i]=max(f[i],f[i-1]);
        }
        cout<<ans;
        return 0;
}
