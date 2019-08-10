#include<bits/stdc++.h>
#define maxn 10005
#define oo 1000000000
#define ll long long
using namespace std;
struct data
{
        ll n;
        int s,k;
};
int n;
data  f[maxn],c[maxn];
bool operator <(const data &a,const data &b)
{
        if (a.n!=b.n) return a.n<b.n;
        if (a.s!=b.s) return a.s<b.s;
        return a.k<b.k;
}
data operator +(const data &a,const data &b)
{
        data c;
        c={a.n+b.n,a.s+b.s,a.k+b.k};
        return c;
}
int main()
{
        freopen("LEM7.inp","r",stdin);
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
                c[i]={i+1,1,1};
                for (int j=2;j*j<=i;++j)
                if (i%j==0)
                {
                        data tmp={j+i/j,j,1};
                        if (tmp<c[i])c[i]=tmp;
                }
        }
        for (int i=1;i<=n;++i)
        f[i]={oo,oo,oo};
        for (int i=1;i<=n;++i)
        {
                for (int j=0;j<i;++j)
                if ((f[j]+c[i-j])<f[i]) f[i]=f[j]+c[i-j];
        }
        printf("%lld %d %d",f[n].n,f[n].s,f[n].k);
        return 0;
}
