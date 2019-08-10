#include<bits/stdc++.h>
#define maxn 4005
#define ll long long
#define base 10000
using namespace std;
typedef vector<int > bignum;
bignum f[maxn],emp;
int n;
void fix(bignum &a)
{
        a.push_back(0);
        for (int i=0; i<a.size()-2; ++i)
        {
                a[i+1]+=a[i]/base;
                a[i]%=base;
                if (a[i]<0)
                {
                        a[i]+=base;
                        a[i+1]--;
                }
        }
        while(a.size()>=2&&a.back()==0) a.pop_back();
}
ostream& operator << (ostream& cout, const bignum &a)
{
        printf("%d", a.back());
        for (int i=(int)a.size()-2; i>=0; i--)
                printf("%04d", a[i]);
        return cout;
}

bignum to_big(int a)
{
        return bignum(1,a);
}
bignum operator +(bignum a,const bignum &b)
{
        a.resize(max(a.size(),b.size()));
        for (int i=0; i<b.size(); ++i)
                a[i]+=b[i];
        fix(a);
        return a;
}
int main()
{
        freopen("PBCDEM.inp","r",stdin);
        cin>>n;
        f[0]=to_big(1);
        for (int i=1; i<n; ++i)
                for (int j=n-i; j>=0; --j)
                        if (f[j].size()!=0)
                                f[i+j]=f[i+j]+f[j];
        cout<<f[n];
}
