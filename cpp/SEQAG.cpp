#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
#define mod 1000000000
using namespace std;
int a[maxn],pmax[maxn][35],pmin[maxn][35],n;
int getmin(int i,int j)
{
        int log=log2(j-i+1);
        return min(pmin[i][log],pmin[j-(1<<log)+1][log]);
}
int getmax(int i,int j)
{
        int log=log2(j-i+1);
        return max(pmax[i][log],pmax[j-(1<<log)+1][log]);
}
ll res,sum[maxn];
typedef pair<int,int > II;
int get(int l,int r,II x,int i)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (II(getmax(m,i),getmin(m,i))==x)
                {
                        res=m;
                        r=m-1;
                }
                else l=m+1;
        }
        return res;
}
int main()
{
        freopen("SEQAG.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
                sum[i]=sum[i-1]+i;
        for (int i=1; i<=n; ++i)
        {
                pmin[i][0]=a[i];
                pmax[i][0]=a[i];
        }
        for (int j=1; 1<<j<=n; ++j)
                for (int i=1; i+(1<<j)-1<=n; ++i)
                {
                        pmax[i][j]=max(pmax[i][j-1],pmax[i+(1<<(j-1))][j-1]);
                        pmin[i][j]=min(pmin[i][j-1],pmin[i+(1<<(j-1))][j-1]);
                }
        for (int i=1; i<=n; ++i)
        {
                int now=i;
                while(now>0)
                {
                        int minn=getmin(now,i);
                        int maxx=getmax(now,i);
                        II snow=II(maxx,minn);
                        int tmp=get(1,now,snow,i);
                        int cnt=now-tmp+1;
                        res=(res+(1ll*((1ll*minn*maxx)%mod)*((sum[i-tmp+1]-sum[i-now])%mod))%mod)%mod;
                        now=tmp-1;
                }
        }
        cout<<res;
        return 0;
}
