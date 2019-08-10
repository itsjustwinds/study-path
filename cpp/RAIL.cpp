#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int a[maxn],n,d[maxn],maxx,trc[maxn];
ll f[maxn],sum[maxn];
vector<int > res;
bool check(int m)
{
        memset(f,0,sizeof f);
        f[0]=1;
        for (int i=1;i<=n;++i)
                for (int j=i;j>=max(1,i-m+1);--j)
        {
                if (f[j-1]==0) continue;
                if (sum[i]-sum[j-1]>0)
                {
                        f[i]=1;
                        trc[i]=j-1;
                        break;
                }
        }
        if (f[n]==0) return 0;
        int t=n;
        res.clear();
        while(t!=0)
        {
                int tr=trc[t];
                res.push_back(t-tr);
                t=tr;
        }
        return 1;
}
int main()
{
        freopen("RAIL.inp","r",stdin);
        freopen("RAIL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                sum[i]=sum[i-1]+a[i];
        }
        int l=1,r=1e9;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        r=m-1;
                        maxx=m;
                }
                else l=m+1;
        }
        cout<<res.size()<<" "<<maxx<<"\n";
        for (int i=res.size()-1;i>=0;--i)
                cout<<res[i]<<" ";
        return 0;
}
