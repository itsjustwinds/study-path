#include<bits/stdc++.h>
#define maxn 1001005
using namespace std;
int a[maxn],n,dd[2*maxn],k;
long long res;
int main()
{
        freopen("LPERM.inp","r",stdin);
        freopen("LPERM.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
        {
                for (int j=1;j<=k;++j)
                        res+=dd[maxn+a[i]+j];
                dd[maxn+a[i]]++;
        }
        cout<<res;
        return 0;
}
