#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
        int n,m;
        ll h[5][5];
};
matrix base,a;
ll x,n,mod;
void read(ll &a)
{
        a=0;
        char s=getchar();
        for(;s>='0'&&s<='9';s=getchar())
        {
                a=a*10+s-'0';
        }
}
ll nhan(ll a,ll b)
{
        if (b==0) return 0;
        if (b==1) return a;
        ll tmp=nhan(a,b>>1);
        tmp=(tmp*2)%mod;
        if (b&1) tmp=(tmp+a)%mod;
        return tmp;
}
matrix operator *(matrix a,matrix b)
{
        matrix c;
        c.n=a.n,c.m=b.m;
        for (int i=1;i<=c.n;++i)
                for (int j=1;j<=c.m;++j)
        {
                c.h[i][j]=0;
                for (int k=1;k<=a.m;++k)
                        c.h[i][j]=(c.h[i][j]+nhan(a.h[i][k],b.h[k][j]))%mod;
        }
        return c;
}
matrix power(matrix a,ll n)
{
        if (n==1) return a;
        matrix tmp=power(a,n>>1);
        tmp=tmp*tmp;
        if (n&1) tmp=tmp*a;
        return tmp;
}
void go()
{
        if (n==1)
        {
                //cout<<x%mod<<"\n";
                printf("%lld\n",x%mod);
                return;
        }
        ll tmp=1;
        ll Xtmp=x;
        while(Xtmp)
        {
                tmp=(tmp*10)%mod;
                Xtmp/=10;
        }
        base.n=2,base.m=2;
        base.h[1][2]=tmp;base.h[1][1]=1;
        base.h[2][2]=tmp;
        a.n=2,a.m=1;
        a.h[1][1]=x%mod;
        a.h[2][1]=x%mod;
        matrix Tmp=power(base,n-1);
        Tmp=Tmp*a;
        //cout<<Tmp.h[1][1]<<"\n";
        printf("%lld\n",Tmp.h[1][1]);
}
int main()
{
        freopen("REMAINDER.inp","r",stdin);
        freopen("REMAINDER.out","w",stdout);
        ll test;
        read(test);
        while(test--)
        {
                //scanf("%lld %lld %lld",&x,&n,&mod);
                read(x);
                read(n);
                read(mod);
                //cin>>x>>n>>mod;
                go();
        }
        return 0;
}
