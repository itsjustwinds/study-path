#include<bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
int a[maxn],n,f[maxn],power[maxn],cnt[maxn];
int main()
{
     freopen("803F.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    power[0]=1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++)
        power[i]=((ll)power[i-1]*2)%mod;
    for (int i=maxn;i>=1;i--)
    {
        int sum=0;
        for (int j=i;j<=maxn;j+=i)
            sum+=cnt[j];
        f[i]=(power[sum]-1)%mod;
        for (int j=i+i;j<=maxn;j+=i)
        {
            f[i]=(f[i]-f[j]+mod)%mod;
        }
    }
    cout<<f[1];
    return 0;
}
