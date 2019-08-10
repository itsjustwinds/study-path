#include<bits/stdc++.h>
#define maxn 15005
using namespace std;
int res;
int bitmax[2*maxn],bitmin[2*maxn],n,sum[2*maxn],b[2*maxn],S[2*maxn],m,k;
int Fmax[maxn],Fmin[maxn];
void updatemin(int u,int val)
{
        while(u)
        {
                bitmin[u]=min(bitmin[u],val);
                u-=u&(-u);
        }
}
void updatemax(int u,int val)
{
        while(u)
        {
                bitmax[u]=max(bitmax[u],val);
                u-=u&(-u);
        }
}
int getmin(int u)
{
        int res=1e9;
        while(u<2*maxn)
        {
                res=min(res,bitmin[u]);
                u+=u&(-u);
        }
        return res;
}
int getmax(int u)
{
        int res=-1e9;
        while(u<2*maxn)
        {
                res=max(res,bitmax[u]);
                u+=u&(-u);
        }
        return res;
}
bool check()
{
        for (int i=0; i<2*maxn; ++i)bitmin[i]=1e9;
        for (int i=0; i<2*maxn; ++i)bitmax[i]=-1e9;
        for (int i=1; i<=n; ++i)
        {
                sum[i+n]=sum[i]-m;
                S[i]=sum[i];
                S[i+n]=sum[i+n];
        }
        S[2*n+1]=0;
        sort(S+1,S+2*n+2);
        for (int i=1; i<=2*n+1; i++)b[i]=lower_bound(S+1,S+2*n+2,sum[i])-S;
        updatemin(b[2*n+1],0);
        updatemax(b[2*n+1],0);
        for (int i=1; i<=n; ++i)
        {
                int tmax=getmax(b[i+n]);
                int tmin=getmin(b[i+n]);
                Fmax[i]=tmax+1;
                Fmin[i]=tmin+1;
                updatemax(b[i],tmax+1);
                updatemin(b[i],tmin+1);
        }
        return (k>=Fmin[n]&&k<=Fmax[n]);
}
int main()
{
        freopen("QBSEGPAR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1; i<=n; ++i)
        {
                int a;
                cin>>a;
                sum[i]=sum[i-1]+a;
        }
        int l=-1e9,r=1e9;
        while(l<=r)
        {
                m=(l+r)>>1;
                if (check())
                {
                        res=m;
                        r=m-1;
                }
                else l=m+1;
        }
        cout<<res;
}
