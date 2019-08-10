#include<bits/stdc++.h>
#define maxn 1000005
#define base 10
using namespace std;
typedef vector<int> bignum;
bignum f[maxn],sum;
int n,k;
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
ostream& operator <<(ostream& cout,const bignum &a)
{
            for (int i=a.size()-1; i>=0; --i)
                        cout<<a[i];
            return cout;
}
bignum to_big(int a)
{
            bignum c;
            c.clear();
            while(a)
            {
                        c.push_back(a%base);
                        a/=base;
            }
            return fix(c);
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
bignum operator -(bignum a,const bignum &b)
{
            for (int i=0; i<b.size(); ++i)
            {
                        a[i]-=b[i];
            }
            return fix(a);
}
bignum operator *(bignum a,const bignum &b)
{
            bignum c(a.size()+b.size());
            for (int i=0; i<a.size(); ++i)
                        for (int j=0; j<b.size(); ++j)
                                    c[i+j]+=a[i]*b[j];
            return fix(c);
}
int main()
{
            freopen("SPBINARY.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>k;
            f[1]=to_big(1);
            sum=to_big(1);
            for (int i=2; i<=n; ++i)
            {
                        if (i<=k)
                        {
                                    f[i]=f[i-1]*to_big(2);
                                    sum=sum+f[i];
                                    continue;
                        }
                        f[i]=sum;
                        sum=sum*to_big(2)-f[i-k];
            }
            cout<<f[n]*to_big(2);
            return 0;
}
