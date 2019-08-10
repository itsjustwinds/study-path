#include<bits/stdc++.h>
#define maxn 505
#define ll long long
#define base 10000
using namespace std;
typedef vector<int >bignum;
bignum f[100005],d[100005];
int n,c[maxn],m[maxn],s;
void fix(bignum &a)
{
        a.push_back(0);
        for (int i=0;i<a.size();++i)
        {
                a[i+1]+=a[i]/base;
                a[i]%=base;
                if (a[i]<0)
                {
                        a[i+1]--;
                        a[i]+=base;
                }
        }
        while(a.size()>1&&a.back()==0) a.pop_back();
}
bignum operator +(bignum a,const bignum &b)
{
        a.resize(max(a.size(),b.size()));
        for (int i=0;i<b.size();++i)
                a[i]+=b[i];
        fix(a);
        return a;
}
bignum operator -(bignum a,const bignum &b)
{
        for (int i=0;i<b.size();++i)
                a[i]-=b[i];
        fix(a);
        return a;
}
ostream& operator << (ostream& cout, const bignum &a){
    printf("%d", a.back());
    for (int i=(int)a.size()-2; i>=0; i--)
    printf("%04d", a[i]);
    return cout;
}
bignum to_big(int a)
{
        return bignum(1,a);
}
int main()
{
        freopen("QBMARKET.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>s>>n;
        for (int i=1;i<=n;++i)
                cin>>c[i]>>m[i];
        f[0]=to_big(1);
        for (int i=1;i<=n;++i)
        {
                for (int j=c[i];j<=s;++j)
                {
                        d[j]=f[j-c[i]];
                        d[j]=d[j]+d[j-c[i]];
                        if (j-(m[i]+1)*c[i]>=0) d[j]=d[j]-f[j-(m[i]+1)*c[i]];
                }
                for (int j=0;j<=s;++j)
                {
                        f[j]=f[j]+d[j];
                        d[j]=to_big(0);
                }
        }
        cout<<f[s];
        return 0;
}
