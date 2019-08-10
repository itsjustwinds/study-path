#include <bits/stdc++.h>
#define maxn 100005
#define long long long
#define mod 1000000007
using namespace std;
long ans;
int n;
int main()
{
    freopen("socola.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 0; i <= n; i += 2)
        for (int j = 0; i + j <= n; j += 3)
            ans=(ans+1)%mod;
    cout<<ans;
    return 0;
}
