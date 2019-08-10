#include<bits/stdc++.h>
#define maxn 35
#define base 10
using namespace std;
int a[maxn][maxn],n,m,k,sb;
bool check(int i,int j)
{
        return i>0&&i<=n&&j>0&&j<=m;
}
int id(int i,int j)
{
        return (i-1)*m+j;
}
typedef vector<int > vi;
typedef vector<int > bignum;
vi f[maxn*maxn];
vi operator +(vi a,const vi &b)
{
        for (int i=0; i<b.size(); ++i)
                a[i]=(a[i]+b[i])%2;
        return a;
}
bignum to_big(int a)
{
        return bignum(1,a);
}
bignum fix(bignum &c)
{
        c.push_back(0);
        for (int i=0; i<(int)c.size(); ++i)
        {
                c[i+1]+=c[i]/base;
                c[i]%=base;
                while(c[i]<0)
                {
                        c[i]+=base;
                        --c[i+1];
                }
        }
        while (c.size()>=2 && c.back()==0) c.pop_back();
        return c;
}
ostream& operator <<(ostream& cout,const bignum &a)
{
        for (int i=a.size()-1; i>=0; --i)
                cout<<a[i];
        return cout;
}
bignum operator *(bignum a,const bignum &b)
{
        bignum c(a.size()+b.size());
        for (int i=0; i<a.size(); ++i)
                for (int j=0; j<b.size(); ++j)
                        c[i+j]+=a[i]*b[j];
        return fix(c);
}
bignum res;
int main()
{
        freopen("BOMB.inp","r",stdin);
        freopen("BOMB.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        cin>>a[i][j];
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        if (a[i][j]!=-1)
                        {
                                ++k;
                                f[k].resize(n*m+2);
                                if (check(i-1,j)) f[k][id(i-1,j)]=1;
                                if (check(i,j+1)) f[k][id(i,j+1)]=1;
                                if (check(i+1,j)) f[k][id(i+1,j)]=1;
                                if (check(i,j-1)) f[k][id(i,j-1)]=1;
                                f[k][n*m+1]=a[i][j];
                        }
        sb=m*n-k;
        for (int i=1; i<=k; ++i)
        {
                int c=-1;
                for (int j=1; j<=n*m; ++j)
                        if (f[i][j]!=0)
                        {
                                c=j;
                                break;
                        }
                if (c==-1)
                {
                        if (f[i][n*m+1]==0) sb++;
                        else
                        {
                                cout<<0;
                                return 0;
                        }
                        continue;
                }
                for (int j=i+1; j<=k; ++j)
                {
                        if (f[j][c]==0) continue;
                        f[j]=f[i]+f[j];
                }
        }
        res=to_big(1);
        for (int i=1; i<=sb; ++i)
                res=res*to_big(2);
        cout<<res;
        return 0;
}
