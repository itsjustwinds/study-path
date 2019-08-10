#include<bits/stdc++.h>
#define maxn 5005
#define ll long long
using namespace std;
ll f[maxn];
int a[maxn],b[maxn],n,m;
int main()
{
        freopen("VOSLIS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=m;++i)
                cin>>b[i];
        for (int i=1;i<=n;++i)
                f[i]=-1e18;
        f[0]=-1e18;
        for (int i=1;i<=n;++i)
        {
                ll tmp=0;
                for (int j=1;j<=m;++j)
                {
                        if (a[i]==b[j])
                        {
                               if (tmp==0) f[j]=0;
                               else f[j]=max(f[j],f[tmp]+abs(a[i]-b[tmp]));
                               continue;
                        }
                        if (f[j]!=-1e18&&f[j]+abs(a[i]-b[j])>f[tmp]+abs(a[i]-b[tmp])) tmp=j;
                }
        }
        ll res=0;
        for (int i=1;i<=m;++i)
                res=max(res,f[i]);
        cout<<res;
}
