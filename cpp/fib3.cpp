#include<bits/stdc++.h>
#define mod 1000000007
#include<fstream>
#define ll long long
using namespace std;
ifstream fi("fib3.inp");
ofstream fo("fib3.out");
ll s1,s2,n;
struct matrix
{
    int n,m;
    ll h[5][5];
};
matrix a,f;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;c.m=b.m;
    for (int i=1;i<=c.n;i++)
        for (int j=1;j<=c.m;j++)
    {
        c.h[i][j]=0;
        for (int k=1;k<=a.m;k++)
            c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%mod;
    }
    return c;
}
matrix power(matrix a, ll n)
{
    if (n==1) return a;
    matrix tmp=power(a,n/2);
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    //freopen("fib3.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    fi>>test;
    a.n=3;a.m=3;
    f.n=3;f.m=1;
    a.h[1][2]=1;
    a.h[2][3]=1;
    a.h[3][2]=1;a.h[3][3]=1;
    while (test)
    {
        test--;
        fi>>s1>>s2>>n;
        f.h[1][1]=s1%mod;
        f.h[2][1]=s2%mod;
        f.h[3][1]=(s1+s2)%mod;
        if (n<=2)
        {
            fo<<f.h[n+1][1]<<"\n";
            continue;
        }
        matrix tmp=power(a,n-2);
        matrix res=tmp*f;
        fo<<res.h[3][1]<<"\n";
    }
    fi.close();
    return 0;
}
