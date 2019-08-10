#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int res,n,a[maxn];
int main()
{
        freopen("S_INDEX.inp","r",stdin);
        //freopen("S_INDEX.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);
        cin>>n;
        for(int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1);
        int now=0;
        for (int i=1;i<=n;++i)
        {
                while(now<n&&a[now+1]<i) ++now;
                if (n-now>=i) res=i;
        }
        cout<<res;
        return 0;
}
