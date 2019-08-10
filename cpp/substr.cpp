#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000007
using namespace std;
char a[maxn],b[maxn];
int n,m;
struct data
{
        int b[2];
};
data base,hA[maxn],hB[maxn],power[maxn];
data get(int l,int r)
{
        data c;
        for (int j=0;j<=1;++j)
                c.b[j]=(hA[r].b[j]-(1ll*hA[l-1].b[j]*power[r-l+1].b[j])%mod+mod)%mod;
        return c;
}
bool operator == (data a,data b)
{
        return a.b[0]==b.b[0]&&a.b[1]==b.b[1];
}
int main()
{
        freopen("SUBSTR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        base.b[0]=26;base.b[1]=137;
        power[0].b[0]=1;power[0].b[1]=1;
        cin>>(a+1);
        cin>>(b+1);
        n=strlen(a+1);
        m=strlen(b+1);
        for (int i=1;i<=n;++i)
        for (int j=0;j<=1;++j)
        {
                power[i].b[j]=(1ll*power[i-1].b[j]*base.b[j])%mod;
        }
        for (int i=1;i<=n;++i)
        for (int j=0;j<=1;++j)
        {
                hA[i].b[j]=((1ll*hA[i-1].b[j]*base.b[j])%mod+a[i]-'a')%mod;
        }
        for (int i=1;i<=m;++i)
        for (int j=0;j<=1;++j)
        {
                hB[i].b[j]=((1ll*hB[i-1].b[j]*base.b[j])%mod+b[i]-'a')%mod;
        }
        for (int i=1;i<=n-m+1;++i)
        {
                data tmp=get(i,i+m-1);
                if (tmp==hB[m])
                {
                        cout<<i<<" ";
                }
        }
        return 0;
}
