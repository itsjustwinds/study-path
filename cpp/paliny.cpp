#include<bits/stdc++.h>
#define maxn 50005
#define mod 1000000007
#define ll long long
using namespace std;
struct data
{
        ll b[2];
};
data base,hashS[maxn],hashT[maxn],power[maxn];
char s[maxn],t[maxn];
int n,res;
data getS(int i,int j)
{
        data c;
        for (int k=0;k<=1;++k)
        {
                c.b[k]=(hashS[j].b[k]-((ll)hashS[i-1].b[k]*power[j-i+1].b[k])%mod+mod)%mod;
        }
        return c;
}
data getT(int i,int j)
{
        data c;
        for (int k=0;k<=1;++k)
        {
                c.b[k]=(hashT[j].b[k]-((ll)hashT[i-1].b[k]*power[j-i+1].b[k])%mod+mod)%mod;
        }
        return c;
}
bool operator ==(data a,data b)
{
        return a.b[0]==b.b[0]&&a.b[1]==b.b[1];
}
int check(int m)
{
        for (int i=1;i<=n-m+1;++i)
        {
                if (getS(i,i+m-1)==getT(n-m-i+2,n-i+1)) return 1;
        }
        return 0;
}
int main()
{
        freopen("PALINY.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>s[i];
                t[n-i+1]=s[i];
        }
        power[0].b[0]=1;
        power[0].b[1]=1;
        base.b[0]=37;
        base.b[1]=147;
        for (int i=1;i<=n;++i)
        for (int k=0;k<=1;++k)
                power[i].b[k]=((ll)power[i-1].b[k]*base.b[k])%mod;
        for (int i=1;i<=n;++i)
                for (int k=0;k<=1;++k)
        {
                hashS[i].b[k]=((ll)hashS[i-1].b[k]*base.b[k]+(int)s[i])%mod;
                hashT[i].b[k]=((ll)hashT[i-1].b[k]*base.b[k]+(int)t[i])%mod;
        }
        int l=1,r=n-(n%2==0);
        while(l<=r)
        {
                int m=((l+r)>>1);
                m+=(m%2!=1);
                if (check(m))
                {
                        res=max(res,m);
                        l=m+2;
                }
                else r=m-2;
        }
        l=2;r=n-(n%2==1);
        while(l<=r)
        {
                int m=((l+r)>>1);
                m+=(m%2!=0);
                if (check(m))
                {
                        res=max(res,m);
                        l=m+2;
                }
                else r=m-2;
        }
        cout<<res;
        return 0;
}
