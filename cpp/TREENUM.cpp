#include<bits/stdc++.h>
#define maxn 63
#define base 10000
#define ll long long
using namespace std;
typedef vector<int> bignum;
ll power[maxn],n;
bignum res,power3[maxn];
bignum to_big(int a)
{
        bignum c;
        c.clear();
        while(a)
        {
                c.push_back(a%base);
                a/=base;
        }
        if (c.size()==0) c.push_back(0);
        return c;
}
bignum fix(bignum &a)
{
        a.push_back(0);
        for (int i=0; i<a.size(); ++i)
        {
                a[i+1]+=a[i]/base;
                a[i]%=base;
                while(a[i]<0)
                {
                        a[i]+=base;
                        --a[i+1];
                }
        }
        while(a.size()>=2&&a.back()==0) a.pop_back();
        return a;
}
ostream& operator << (ostream& cout, const bignum &a)
{
        printf("%d", a.back());
        for (int i=(int)a.size()-2; i>=0; i--)
                printf("%04d", a[i]);
        return cout;
}

bignum operator +(bignum a,const bignum &b)
{
        a.resize(max(a.size(),b.size()));
        for (int i=0; i<b.size(); ++i)
        {
                a[i]+=b[i];
        }
        return fix(a);
}
bignum operator *(bignum &a,const bignum &b)
{
        bignum c(a.size()+b.size());
        for (int i=0; i<a.size(); ++i)
                for (int j=0; j<b.size(); ++j)
                        c[i+j]+=a[i]*b[j];
        return fix(c);
}
int main()
{
        freopen("TREENUM.inp","r",stdin);
        int test;
        scanf("%d",&test);
        power[0]=1;
        for (int i=1; i<maxn; ++i)
                power[i]=power[i-1]*2;
        power3[0]=to_big(1);
        for (int i=1; i<maxn; ++i)
                power3[i]=power3[i-1]*to_big(3);
        while(test--)
        {
                scanf("%lld",&n);
                res=to_big(0);
                for (int i=maxn-1; i>=0; --i)
                {
                        if (power[i]<=n)
                        {
                                n-=power[i];
                                res=res+power3[i];
                        }
                }
                cout<<res<<"\n";
        }
        return 0;
}
