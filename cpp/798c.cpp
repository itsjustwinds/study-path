#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],res,maxx,n;
int main()
{
    freopen("798c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>a[1];
    maxx=a[1];
    a[1]%=2;
    for (int i=2;i<=n;i++)
    {
        cin>>a[i];
        maxx=__gcd(maxx,a[i]);
        a[i]%=2;
    }
    if (maxx>1)
    {
        cout<<"YES\n";
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++)
        if (a[i])
    {
        res+=(a[i+1]==0)?2:1;
        a[i]=0;
        a[i+1]=0;
    }
    cout<<"YES\n";
    cout<<res;
    return 0;
}
