#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
struct matrix
{
    int n,m;
    int h[55][55];
};
int n,k,f[100];
matrix a,dmcd;
int powe(int a,int n)
{
    if (n==1) return a;
    int tmp=powe(a,n>>1);
    tmp=((ll)tmp*tmp)%mod;
    if (n%2==1) tmp=((ll)tmp*a)%mod;
    return tmp;
}
int c(int a,int b)
{
    return ((ll)f[a]*powe(((ll)f[b]*f[a-b])%mod,mod-2))%mod;
}
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for (int i=1; i<=c.n; i++)
        for (int j=1; j<=c.m; j++)
        {
            c.h[i][j]=0;
            for (int k=1; k<=a.m; k++)
                c.h[i][j]=((ll)c.h[i][j]+((ll)a.h[i][k]*b.h[k][j])%mod)%mod;
        }
    return c;
}
matrix power(matrix a, int n)
{
    if (n==1) return a;
    matrix tmp=power(a,n/2);
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    freopen("c11cal.inp","r",stdin);
    //freopen("c11cal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0]=1;
    for (int i=1; i<=50; i++)
        f[i]=((ll)f[i-1]*i)%mod;
    while(cin>>n>>k)
    {
        if (n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        a.n=k+2;a.m=k+2;
        for (int i=1;i<=k+2;i++)
            for (int j=1;j<=k+2;j++)
            a.h[i][j]=0;
        a.h[k+2][k+1]=1;a.h[k+2][k+2]=1;
        for (int i=1;i<=k+1;i++)
        {
            int tmp=i-1;
            for (int j=0;j<=tmp;j++)
                a.h[i][j+1]=c(tmp,j);
        }
        dmcd.n=k+2;dmcd.m=1;
        for (int i=1;i<=k+1;i++)
            dmcd.h[i][1]=1;
            dmcd.h[k+2][1]=0;
        matrix tmp=power(a,n);
        matrix res=tmp*dmcd;
        cout<<res.h[k+2][1]<<"\n";
    }
    return 0;
}
