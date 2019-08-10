#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int dd1[maxn],dd2[maxn],n,mod,power[30],dd[30];
ll res;
void dfs(int i)
{
        if (i==(n+1)/2+1)
        {
                int tmp=0;
                for (int j=1;j<=n/2;++j)
                        tmp=(tmp*10+dd[j])%mod;
                for (int j=(n+1)/2;j>=1;--j)
                        tmp=(tmp*10+dd[j])%mod;
                if (dd[1]!=0) dd1[tmp]++;
                dd2[tmp]++;
                return;
        }
        for (int j=0;j<=9;++j)
        {
                dd[i]=j;
                dfs(i+1);
        }
}
int main()
{
        freopen("MBIPALIN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>mod;
        n/=2;
        power[0]=1;
        for (int i=1;i<=20;++i)
                power[i]=(power[i-1]*10)%mod;
        dfs(1);
        for (int i=0;i<mod;++i)
        if (dd1[i])
        {
                int j=(mod-(1ll*i*power[n])%mod+mod)%mod;
                res+=1ll*dd2[j]*dd1[i];
        }
        cout<<res;
}
