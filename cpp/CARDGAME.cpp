#include<bits/stdc++.h>
#define maxn 200005
#define mod 1000000007
using namespace std;
int f[maxn],n,a[maxn],sum,d;
int main()
{
        freopen("CARDGAME.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        ++n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                if (f[a[i]]==0) ++d;
                ++f[a[i]];
        }
        cout<<d<<"\n";
        for (int i=2;i<=n;++i)
}
