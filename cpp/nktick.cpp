#include<bits/stdc++.h>
#define maxn 60005
#define ll long long
using namespace std;
ll f[maxn];
int a[maxn],r[maxn],n;
int main()
{
        freopen("NKTICK.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<n;++i)
                cin>>r[i];
        r[n]=1e9;
        f[1]=a[1];
        for (int i=2;i<=n;++i)
                f[i]=min(f[i-1]+a[i],f[i-2]+r[i-1]);
        cout<<f[n];
        return 0;
}
