#include<bits/stdc++.h>
#define maxn 10005
#define base 1000000000
using namespace std;
typedef vector<int> bignum;
bignum f[maxn];
int n,k;
bignum to_big(int a)
{
            bignum c;
            c.clear();
            while(a)
            {
                        c.push_back(a%base);
                        a/=base;
            }
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
                        printf("%09d", a[i]);
            return cout;
}

bignum operator +(bignum a,const bignum &b)
{
            a.resize(max(a.size(),b.size()));
            for (int i=0; i<b.size(); ++i)
                        a[i]+=b[i];
            return fix(a);
}
bignum operator -(bignum a,const bignum &b)
{
            a.resize(max(a.size(),b.size()));
            for (int i=0; i<b.size(); ++i)
                        a[i]-=b[i];
            return fix(a);
}
bignum operator *(const bignum &a,const bignum &b)
{
            bignum c(a.size()+b.size());
            for (int i=0; i<a.size(); ++i)
                        for (int j=0; j<b.size(); ++j)
                                    c[i+j]+=a[i]*b[j];
            return fix(c);
}
int main()
{
            freopen("NKTOSS.inp","r",stdin);
            scanf("%d %d",&n,&k);
            bignum one=to_big(1);
            bignum two=to_big(2);
            f[k]=one;
            bignum sum=one;
            for (int i=k+1; i<=n; ++i)
            {
                        f[i]=two*f[i-1]+sum-f[i-k-1];
                        sum=sum*two;
            }
            cout<<f[n];
            return 0;
}
