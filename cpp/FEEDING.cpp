#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll res;
int a[maxn],p[maxn],n,minn;
int main()
{
        freopen("FEEDING.inp","r",stdin);
        freopen("FEEDING.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
                cin>>p[i];
        minn=1e9;
        for (int i=1;i<=n;++i)
        {
                minn=min(minn,p[i]);
                res+=1ll*minn*a[i];
        }
        cout<<res;
        return 0;
}
