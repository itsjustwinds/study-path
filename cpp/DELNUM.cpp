#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int a[maxn],n,len[maxn],dd[maxn],trc[maxn];
int findd(int l,int r,int x)
{
        int res=l-1;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (x>a[m])
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        return res;
}
int main()
{
        freopen("DELNUM.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        len[n]=1;
        a[n+1]=-1e9;
        a[0]=-1e9;
        for (int i=n-1;i>=1;--i)
        if (a[i]<a[i+1]) len[i]=len[i+1]+1;
        else len[i]=1;
        for (int i=1;i<=n;++i)
                trc[i]=i-1;
        for (int i=1;i<n-1;++i)
        if (!dd[i])
        {
                int k=len[i+1];
                int x=findd(i+1,i+k,a[i]);
                if (a[x]>=a[x+1]) --x;
                for (int j=i+1;j<=x;++j)
                        dd[j]=1;
                trc[x+1]=i;
                if (a[trc[i]]>a[i]&&a[x+1]>a[i])
                {
                        dd[i]=1;
                        trc[x+1]=trc[i];
                }
        }
        int ans=0;
        for (int i=1;i<=n;++i)
        if (!dd[i]) cout<<a[i]<<" ";
        //cout<<ans;
        return 0;
}
