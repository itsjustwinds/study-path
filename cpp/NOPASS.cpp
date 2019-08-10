#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,res,now;
int main()
{
        freopen("NOPASS.inp","r",stdin);
        freopen("NOPASS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                a[x]=i;
        }
        int now=0;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                int tmp=a[x];
                if (tmp<now) ++res;
                now=max(now,tmp);
        }
        cout<<res;
        return 0;
}
