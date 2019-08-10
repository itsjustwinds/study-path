#include<bits/stdc++.h>
using namespace std;
char a[400005];
int m;
int f[400005];
int main()
{
    freopen("795e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(a+1);
    int n=strlen(a+1);
    cin>>m;
    for (int i=1;i<=n-1;i++)
        a[n+i]=a[i];
    for (int i=1;i<=n;i++)
        f[i]=(f[i-1]*10+a[i]-48)%m;
    int res=f[n];
    for (int i=n+1;i<=2*n-1;i++)
    {
        f[i]=(f[i-1]*10+a[i]+48+m-f[i-1])%m;
        if (a[i]!='0')res=min(res,f[i]);
    }
    cout<<res;
    return 0;
}
