#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 1000000007
using namespace std;
struct data
{
            int b[3];
};
data hashA[maxn],hashB[maxn],base,power[maxn];
int n,m,res,ok;
char a[maxn],b[maxn];
bool operator == (data a,data b)
{
            return a.b[1]==b.b[1]&&a.b[2]==b.b[2];
}
data getA(int l,int r)
{
            data c;
            for (int i=1; i<=2; ++i)
                        c.b[i]=(hashA[r].b[i]-((ll)hashA[l-1].b[i]*power[r-l+1].b[i])%mod+mod)%mod;
            return c;
}
data getB(int l,int r)
{
            data c;
            for (int i=1; i<=2; ++i)
                        c.b[i]=(hashB[r].b[i]-((ll)hashB[l-1].b[i]*power[r-l+1].b[i])%mod+mod)%mod;
            return c;
}
int main()
{
            freopen("C11STR2.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>(a+1);
            cin>>(b+1);
            n=strlen(a+1);
            m=strlen(b+1);
            base.b[1]=107;
            base.b[2]=83;
            power[0].b[1]=1;
            power[0].b[2]=1;
            int maxx=max(m,n);
            for (int i=1; i<=maxx; ++i)
                        for (int j=1; j<=2; ++j)
                        {
                                    power[i].b[j]=((ll)power[i-1].b[j]*base.b[j])%mod;
                        }
            for (int i=1; i<=n; ++i)
                        for (int j=1; j<=2; ++j)
                        {
                                    hashA[i].b[j]=(((ll)hashA[i-1].b[j]*base.b[j])%mod+a[i]-'a')%mod;
                        }
            for (int i=1; i<=m; ++i)
                        for (int j=1; j<=2; ++j)
                        {
                                    hashB[i].b[j]=(((ll)hashB[i-1].b[j]*base.b[j])%mod+b[i]-'a')%mod;
                        }
            for (int i=max(1,n-m+1); i<=n; ++i)
            {
                        int tmp=n-i+1;
                        if (getA(i,n)==getB(1,tmp))
                        {
                                    ok=1;
                                    for (int j=1; j<=i-1; ++j)
                                                cout<<a[j];
                                    for (int j=1; j<=m; ++j)
                                                cout<<b[j];
                                    break;
                        }
            }
            if (!ok)
            {
                        for (int j=1; j<=n; ++j)
                                    cout<<a[j];
                        for (int j=1; j<=m; ++j)
                                    cout<<b[j];
            }
            return 0;
}
