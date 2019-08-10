#include<bits/stdc++.h>
#define maxn 1000005
#define mod 1000000009
using namespace std;
int res,ddM[maxn],ddN[maxn],n,m,k,X;
int tinh(int a,int n)
{
        if (n==0) return 1;
        if (n==1) return a;
        int tmp=tinh(a,n>>1);
        tmp=(1ll*tmp*tmp)%mod;
        if (n&1) tmp=(1ll*tmp*a)%mod;
        return tmp;
}
int main()
{
        freopen("SKPV15_5.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        X=1;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                ddN[x]++;
        }
        for (int i=1;i<=m;++i)
        {
                int x;
                cin>>x;
                ddM[x]++;
        }
        for (int i=2;i<=1e6;++i)
        if (ddM[i])
        {
                if (ddN[i]>ddM[i])
                {
                        cout<<0;
                        return 0;
                }
                X=(1ll*X*(ddM[i]-ddN[i]+1))%mod;
        }
        for (int i=1;i<=k;++i)
                res=(res+(1ll*tinh(X,i-1)*tinh((X-1+mod)%mod,k-i))%mod)%mod;
        cout<<res;
}
