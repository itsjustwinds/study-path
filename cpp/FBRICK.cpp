#include<bits/stdc++.h>
#define maxn 10
#define ll long long
using namespace std;
struct matrix
{
        int n,m;
        ll h[maxn][maxn];
};
matrix a,dm;
ll x,n,mod;
matrix operator *(matrix a,matrix b)
{
        matrix c;
        c.n=a.n;c.m=b.m;
        for (int i=1;i<=c.n;i++)
                for (int j=1;j<=c.m;j++)
        {
                c.h[i][j]=0;
                for (int k=1;k<=a.m;k++)
                {
                        c.h[i][j]=(c.h[i][j]+(a.h[i][k]*b.h[k][j])%mod+mod)%mod;
                }
        }
        return c;
}
matrix power(matrix a,ll n)
{
        if (n==1) return a;
        matrix c=power(a,n>>1);
        c=c*c;
        if (n&1) c=c*a;
        return c;
}
int main()
{
        freopen("FBRICK.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>x>>n>>mod;
                x%=mod;
                if (n==1)
                {
                        cout<<1<<"\n";
                        continue;
                }
                if (n==2)
                {
                        ll tmp=(x*x)%mod;
                        cout<<(tmp+1)%mod<<"\n";
                        continue;
                }
                a.n=4;
                a.m=4;
                dm.n=4;
                dm.m=1;
                a.h[1][2]=1;
                a.h[2][1]=1;a.h[2][2]=(4*(x*x)%mod)%mod;
                a.h[2][3]=-(4*x)%mod;
                a.h[3][2]=(2*x)%mod;
                a.h[3][3]=-1;
                a.h[4][2]=1;
                a.h[4][4]=1;
                dm.h[1][1]=1;
                dm.h[2][1]=(x*x)%mod;
                dm.h[3][1]=x;
                dm.h[4][1]=1;
                matrix tmp1=power(a,n-1);
                matrix res=tmp1*dm;
                cout<<res.h[4][1]<<"\n";
        }
        return 0;
}
