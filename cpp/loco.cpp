#include<bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;
ifstream fi("loco.inp");
ofstream fo("loco.out");
struct matrix
{
    int n,m;
    int h[5][5];
};
matrix a,f;
int m;
ll n;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;c.m=b.m;
    for (int i=1;i<=c.n;i++)
        for (int j=1;j<=c.m;j++)
    {
        c.h[i][j]=0;
        for (int k=1;k<=a.m;k++)
            c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%m;
    }
    return c;
}
matrix power(matrix a,ll n)
{
    if (n==1) return a;
    matrix temp=power(a,n/2);
    temp=temp*temp;
    if (n%2==1) temp=temp*a;
    return temp;
}
int main()
{
    //freopen("loco.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n>>m;
    a.h[1][2]=1;
    a.h[2][3]=1;
    a.h[3][4]=1;
    a.h[4][4]=1;a.h[4][2]=1;a.h[4][3]=1;
    f.h[1][1]=1;f.h[2][1]=2;f.h[3][1]=4;f.h[4][1]=7;
    a.n=4;a.m=4;
    f.n=4;f.m=1;
    if (n<=4)
    {
        fo<<f.h[n][1]%m;
        return 0;
    }
    matrix tmp=power(a,n-4);
    matrix res=tmp*f;
    fo<<res.h[4][1];
    return 0;
}
