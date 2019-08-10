#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int a[maxn],n,x,k;
long long res;
int main()
{
        //freopen("873A.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k>>x;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n-k;++i)
                res+=a[i];
        for (int i=max(1,n-k+1);i<=n;++i)
                res+=x;
        cout<<res;
}
