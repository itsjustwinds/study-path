#include <bits/stdc++.h>
using namespace std;
int maxn[100001],f[100001];
int main()
{
    //freopen("MAXARR1.INP","r",stdin);
    //freopen("MAXARR1.OUT","w",stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n;
    f[1]=1;
    maxn[1]=1;
    for (int i=2;i<=100000;i++)
    {
        if (i%2==0) f[i]=f[i/2];
            else f[i]=f[i/2]+f[i/2+1];
        maxn[i]=max(maxn[i-1],f[i]);
    }
    for (int i=1;i<=t;i++)
    {
        cin>>n;
        cout<<maxn[n]<<"\n";
    }
    return 0;
}
