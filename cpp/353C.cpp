#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,dp[maxn],ans;
char s[maxn];
int main()
{
        freopen("353C.inp","r",stdin);
        //freopen("353C.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                dp[i]=dp[i-1]+a[i];
        }
        cin>>(s+1);
        for (int i=1;i<=n;++i)
        if (s[i]=='1')
        {
                ans=max(ans+a[i],dp[i-1]);
        }
        cout<<ans;
        return 0;
}
