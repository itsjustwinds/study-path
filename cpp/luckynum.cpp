#include<bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
int n,k,l[maxn],r[maxn],res;
int main()
{
    //freopen("luckynum.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    l[0]=1;
    l[1]=9;
    r[n]=10;
    r[n+1]=1;
    for (int i=1;i<=n;i++)
        l[i]=((ll)l[i-1]*10)%mod;
    for (int i=n;i>=1;i--)
        r[i]=((ll)r[i+1]*10)%mod;
    res=((ll)res+r[k+1]-(r[k+2])+mod)%mod;
    res=((ll)res+l[n-k]-(l[n-k-1])+mod)%mod;
    for (int i=2;i<=n-k;i++)
        res=((ll)res+1LL*l[i-1]*r[i+k-1])%mod;
    cout<<res;

}
