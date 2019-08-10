#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int le[maxn],ri[maxn],n,a[maxn],res,sum[maxn],m;
int main()
{
        freopen("ACM_A.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>m;
                for (int i=1; i<=n; ++i)
                        cin>>a[i];
                a[0]=-1;
                a[n+1]=-1;
                res=0;
                for (int i=1; i<=n; ++i)
                        sum[i]=sum[i-1]+a[i];
                for (int i=1; i<=n; ++i)
                {
                        le[i]=i;
                        while(a[i]<a[le[i]-1]) le[i]=le[le[i]-1];
                }
                for (int i=n; i>=1; --i)
                {
                        ri[i]=i;
                        while(a[i]<a[ri[i]+1]) ri[i]=ri[ri[i]+1];
                }
                for (int i=1; i<=n; ++i)
                        if (a[i]==m)
                        {
                                int l=le[i],r=ri[i];
                                res=max(res,sum[r]-sum[l-1]);
                        }
                cout<<res<<"\n";
        }
        return 0;
}
