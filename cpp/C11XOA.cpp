#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
#define base 10000
using namespace std;
typedef vector<int > bignum;
bignum res,f[maxn][2];
int n,ar[10];
void fix(bignum &c)
{
        c.push_back(0);
        for (int i=0; i<c.size(); ++i)
        {
                c[i+1]+=c[i]/base;
                c[i]%=base;
                if (c[i]<0)
                {
                        c[i]+=base;
                        c[i+1]--;
                }
        }
        while(c.size()>1&&c.back()==0) c.pop_back();
}
bignum to_big(int n)
{
        return bignum(1,n);
}
bignum operator +(bignum a,const bignum &b)
{
        a.resize(max(a.size(),b.size()));
        for (int i=0; i<b.size(); ++i)
                a[i]+=b[i];
        fix(a);
        return a;
}
bignum operator -(bignum a,const bignum &b)
{
        for (int i=0; i<b.size(); ++i)
                a[i]-=b[i];
        fix(a);
        return a;
}
ostream& operator << (ostream& cout, const bignum &a)
{
        printf("%d", a.back());
        for (int i=(int)a.size()-2; i>=0; i--)
                printf("%04d", a[i]);
        return cout;
}
int main()
{
        freopen("C11XOA.inp","r",stdin);
        //freopen("C11XOA.out","w",stdout);
        int test;
        scanf("%d",&test);
        int maxx=0;
        for (int i=1;i<=test;++i)
        {
                scanf("%d",&ar[i]);
                maxx=max(maxx,ar[i]);
        }
        f[1][0]=to_big(1);
        f[1][1]=to_big(1);
        for (int i=2; i<=maxx; ++i)
        {
                f[i][0]=f[i-1][1];
                f[i][1]=f[i-1][0]+f[i-1][1];
        }
        for (int i=1;i<=test;++i)
        {
                n=ar[i];
                if (n>4)res=f[n][0]+f[n][1]-f[n-4][1]-f[n-4][0];
                else res=f[n][0]+f[n][1]-to_big(1);
                cout<<res<<"\n";
        }
        return 0;
}
