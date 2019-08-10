#include<bits/stdc++.h>
#define maxn 1005
#define base 10000
#define ll long long
using namespace std;
typedef vector<int > bignum;
bignum f[maxn][maxn],res;
int n,a[maxn],m;
bignum to_big(int n)
{
        return bignum(1,n);
}
void fix(bignum &a)
{
        a.push_back(0);
        for(int i=0; i<a.size()-1; ++i)
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
        for (int i=0; i<b.size(); ++i)
                a[i]+=b[i];
        fix(a);
        return a;
}
ostream& operator <<(ostream& cout,bignum a)
{
        printf("%d",a.back());
        for (int i=a.size()-2; i>=0; --i)
                printf("%04d",a[i]);
        return cout;
}

int main()
{
        freopen("LEM6.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
                cin>>a[i];
        for (int i=a[1]; i<=n; ++i)
                f[i][1]=f[i-1][1]+to_big(1);
        for (int i=1; i<=n; ++i)
        {
                for (int j=2; j<=m; ++j)
                {
                        if (i-a[j]-1<=0) continue;
                        f[i][j]=f[i-1][j]+f[i-a[j]-1][j-1];
                }
        }
        cout<<f[n][m];
        return 0;
}
