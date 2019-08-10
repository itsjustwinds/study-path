#include <bits/stdc++.h>
#define mod 111539786
using namespace std;
struct matrix
{
    int n,m;
    long long h[5][5];
};
matrix a,k;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for (int i=1;i<=c.n;i++)
        for (int j=1;j<=c.m;j++)
    {
        c.h[i][j]=0;
        for (int k=1;k<=a.n;k++)
            c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%mod;
    }
    return c;
}
matrix power(int n)
{
    if (n==1) return a;
    matrix tmp=power(n>>1);
    tmp=tmp*tmp;
    if (n%2==1)
        tmp=tmp*a;
    return tmp;
}
int main()
{
    //freopen("latgach4.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    a.n=2;
    a.m=2;
    a.h[1][1]=0;
    a.h[1][2]=1;
    a.h[2][1]=1;
    a.h[2][2]=1;
    k.n=2;
    k.m=1;
    k.h[1][1]=1;
    k.h[2][1]=2;
    while (t)
    {
        t--;
        int n;
        cin>>n;
        if (n==1||n==2)
        {
            if (n==1) cout<<1<<"\n";
            if (n==2) cout<<2<<"\n";
            continue;
        }
        matrix tmp=power(n-1);
        matrix res=tmp*k;
        cout<<res.h[1][1]<<"\n";
    }
    return 0;
}
