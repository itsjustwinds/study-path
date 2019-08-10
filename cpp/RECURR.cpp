#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int f[maxn],n,d,b[maxn],ok;
struct matrix
{
        int h[55][55],n,m;
};
matrix a,base;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;c.m=b.m;
    for (int i=1;i<=c.n;i++)
        for (int j=1;j<=c.m;j++)
    {
        c.h[i][j]=0;
        for (int k=1;k<=a.m;k++)
            c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%3;
    }
    return c;
}
matrix power(int n,matrix a)
{
    if (n==1) return a;
    matrix tmp=power(n>>1,a);
    tmp=tmp*tmp;
    if (n&1) tmp=tmp*a;
    return tmp;
}
int main()
{
        freopen("RECURR.inp","r",stdin);
        //freopen("RECURR.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>d;
                memset(base.h,0,sizeof base.h);
                for (int i=1;i<=d;++i)
                        a.h[i][i+1]=1;
                a.h[d+1][1]=1;
                for (int i=2;i<=d;++i)
                        a.h[d+1][i]=-1;
                base.n=d+1;base.m=d+1;
                for (int i=1;i<=d;++i)
                        cin>>b[i];
                a.n=1;
                a.m=d+1;
                for (int i=1;i<=d;++i)
                        a.h[1][i]=b[d-i+1];
                for (int i=1;i<=d;++i)
                {
                        matrix tmp=power(n+d-i,base)
                }
        }
}
