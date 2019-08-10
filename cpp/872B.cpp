#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],maxx,minn,n,k;
int main()
{
        //freopen("872B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        minn=1e9;
        maxx=-1e9;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                maxx=max(a[i],maxx);
                minn=min(minn,a[i]);
        }
        if (k==1)
        {
                cout<<minn;
                return 0;
        }
        cout<<maxx;
        return 0;
}
