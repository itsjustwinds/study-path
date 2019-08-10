#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int a[maxn],n,m,t;
long long res;
int main()
{
        freopen("LAVENDER.inp","r",stdin);
        freopen("LAVENDER.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>t;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                res+=1ll*(m)/a[i]*(t/m);
                int x=t%m;
                res+=1ll*(x)/a[i];
        }
        cout<<res;
        return 0;
}
