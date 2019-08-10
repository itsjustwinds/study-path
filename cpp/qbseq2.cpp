#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
#define fs first
#define sc second
using namespace std;
ll f[maxn][100],n,k,a[maxn];
int main()
{
    freopen("qbseq.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=x%k;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<k;j++)
        f[i][j]=-10000000;
   f[1][a[1]]=1;
   for (int i=2;i<=n;i++)
   {
       for (int j=0;j<k;j++)
        f[i][(j+a[i])%k]=max(f[i-1][(j+a[i])%k],f[i-1][j]+1);
   }
   ll res=0;
   for (int i=1;i<=n;i++)
    res=max(res,f[i][0]);
   cout<<res;
    return 0;
}
