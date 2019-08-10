#include<bits/stdc++.h>
using namespace std;
int f[500],n,k,ngto[500],nt[500],dem;
void ftich(int n,int p)
{
    for (int i=1;i<=dem;i++)
    if (n%nt[i]==0)
    {
        while(n%nt[i]==0)
        {
            n=n/nt[i];
            f[nt[i]]+=p;
        }
        if (n==1) return;
    }
}
int main()
{
    //freopen("divisors.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=2;i<=435;i++)
        if (ngto[i]==0)
    {
        nt[++dem]=i;
        for (int j=i*i;j<=435;j+=i)
            ngto[j]=1;
    }
    while(cin>>n>>k)
    {
        for (int i=2;i<=n;i++)
            f[i]=0;
        for (int i=2;i<=n;i++)
            ftich(i,1);
        for (int i=2;i<=k;i++)
            ftich(i,-1);
        for (int i=2;i<=n-k;i++)
            ftich(i,-1);
        long long res=1;
        for (int i=1;i<=n;i++)
            res*=(f[i]+1);
        cout<<res<<"\n";
    }
    return 0;
}
