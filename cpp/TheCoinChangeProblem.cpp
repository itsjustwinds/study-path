#include<bits/stdc++.h>
#define maxn 10000
#define ll long long
using namespace std;
ll a[maxn],n,m,f[maxn];
int main()
{
    freopen("TheCoinChangeProblem.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
            if (f[j])
        {
            f[j+a[i]]+=f[j];
        }
    }
    cout<<f[m];
    return 0;
}
