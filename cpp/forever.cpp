#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    long long n,m;
    long long h[5][5];
};
long long n;
matrix a,k;
const int mod = 1e9 + 7;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;c.m=b.m;
    for (int i=1;i<=c.n;i++)
        for (int j=1;j<=c.m;j++)
    {
        c.h[i][j]=0;
        for (int k=1;k<=a.m;k++)
            c.h[i][j]=(c.h[i][j]+(long long )a.h[i][k]*b.h[k][j])%mod;
    }
    return c;
}
matrix power(long long n,matrix a)
{
    if (n==1) return a;
    matrix tmp=power(n>>1,a);
    tmp=tmp*tmp;
    if(n&1)
    {
        tmp=tmp*a;
    }
    return tmp;
}
int main()
{
    freopen("forever.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a.n=3;a.m=3;
    a.h[1][2]=1;
    a.h[2][3]=1;
    a.h[3][1]=1;a.h[3][2]=1;a.h[3][3]=1;
    matrix k;
    k.n=3;
    k.m=1;
    k.h[1][1]=1;
    k.h[2][1]=2;
    k.h[3][1]=4;
    if (n<=3) cout<<k.h[n][1];
    else
    {
        matrix tmp=power(n-3,a)*k;
        cout<<tmp.h[3][1];
    }
    return 0;
}
