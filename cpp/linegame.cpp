#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
#define maxn 1000005
using namespace std;
int a[maxn],n;
typedef pair<ll,ll> II;
II f[maxn];
int main()
{
    freopen("linegame.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    f[1].sc=a[1];
    for (int i=1;i<=n;i++)
    {
        f[i].fs=max(f[i-1].fs,f[i-1].sc-a[i]);
        f[i].sc=max(f[i-1].sc,f[i-1].fs+a[i]);
    }
    cout<<max(f[n].fs,f[n].sc);
    return 0;
}
