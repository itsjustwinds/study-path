#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,a[maxn],up[maxn],down[maxn];
int main()
{
        //freopen("LADDER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        down[n]=n;
        up[n]=n;
        for (int i=n-1;i>=1;--i)
        {
                if (a[i]>=a[i+1]) down[i]=down[i+1];
                else down[i]=i;
                if (a[i]<=a[i+1]) up[i]=up[i+1];
                else up[i]=i;
        }
        while(m--)
        {
                int l,r;
                cin>>l>>r;
                int x=up[l];
                if (down[x]>=r) cout<<"Yes\n";
                else cout<<"No\n";
        }
        return 0;
}
