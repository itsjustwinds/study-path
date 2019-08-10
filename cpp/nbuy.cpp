#include<bits/stdc++.h>
#define maxn 50005
#define fs first
#define sc second
#define ll long long
using namespace std;
ll f[maxn],n,s;
typedef pair<ll,ll> II;
II a[1000];
int main()
{
    //freopen("nbuy.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs>>a[i].sc;
    for (int i=1;i<=s+5005;i++)
        f[i]=1000000000;
        f[0]=0;
    for (int i=1;i<=n;i++)
    {
    for (int j=0;j<=s;j++)
        f[j+a[i].fs]=min(f[j]+a[i].sc,f[j+a[i].fs]);
    }
    ll res=1000000000;
    for (int i=s;i<=s+5005;i++)
        res=min(res,f[i]);
    cout<<res;
    return 0;
}
