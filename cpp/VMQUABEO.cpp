#include<bits/stdc++.h>
#define maxn 5000005
#define ll long long
using namespace std;
int f[maxn],dp[maxn],n,a[maxn],k,l,pmax[maxn][35],pmin[maxn][35];
ll res;
int minn(int i,int j)
{
        int log=log2(j-i+1);
        return min(pmin[i][log],pmin[j-(1<<log)+1][log]);
}
int maxx(int i,int j)
{
        int log=log2(j-i+1);
        return max(pmax[i][log],pmax[j-(1<<log)+1][log]);
}
int findd(int l,int r,int x)
{
        int kq=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (maxx(m,x)-minn(m,x)<=k)
                {
                        kq=m;
                        r=m-1;
                }
                else l=m+1;
        }
        return kq;
}
int main()
{
        freopen("VMQUABEO.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>l>>k;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        for (int i=1; i<=n; i++)
                pmin[i][0]=a[i];
        for (int i=1; i<=n; i++)
                pmax[i][0]=a[i];
        for (int j=1; 1<<j<=n; j++)
        {
                for (int i=1; i+(1<<j)-1<=n; i++)
                {
                        pmin[i][j]=min(pmin[i][j-1],pmin[i+(1<<(j-1))][j-1]);
                }
        }
        for (int j=1; 1<<j<=n; j++)
        {
                for (int i=1; i+(1<<j)-1<=n; i++)
                {
                        pmax[i][j]=max(pmax[i][j-1],pmax[i+(1<<(j-1))][j-1]);
                }
        }
        dp[1]=1;
        for (int i=2; i<=n; i++)
        {
                int j=findd(dp[i-1],i,i);
                if (i-j-l+1>0)res+=i-j-l+1;
                dp[i]=j;
        }
        cout<<res;
        return 0;
}
