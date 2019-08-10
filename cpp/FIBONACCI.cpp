#include<bits/stdc++.h>
#define maxn 1000000
#define ll long long
using namespace std;
ll n,s,res;
struct data
{
    ll s,d;
};
data f[maxn],zero;
data operator + (data a,data b)
{
    data c;
    c.s=a.s+b.s;
    c.d=a.d+b.d;
    return c;
}
int main()
{
    //freopen("FIBONACCI.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    f[0].s=0;
    f[1].d=1;
    for (int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    res=(s-f[n].s)/f[n].d;
    cout<<res;
    return 0;
}
