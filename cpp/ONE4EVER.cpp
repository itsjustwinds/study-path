#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,n,mod,k,b;
struct matrix
{
        int  n,m;
        ll h[5][5];
};
matrix dm,a;
ll tinh(ll a,ll n)
{
        if (a==0||n==0) return 0;
        if (n==1) return a;
        ll tmp=tinh(a,n>>1);
        tmp=(tmp+tmp)%mod;
        if (n&1) tmp=(tmp+a)%mod;
        return tmp;
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
                        {
                                c.h[i][j]=(c.h[i][j]+tinh(a.h[i][k],b.h[k][j]))%mod;
                        }
                }
        return c;
}
matrix power(matrix a,ll n)
{
        if (n==1) return a;
        matrix tmp=power(a,n>>1);
        tmp=tmp*tmp;
        if (n&1) tmp=tmp*a;
        return tmp;
}
int main()
{
        freopen("ONE4EVER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>x>>b>>mod>>k;
                if (k==1)
                {
                        cout<<b%mod<<"\n";
                        continue;
                }
                dm.n=3;
                dm.m=3;
                a.n=3;
                a.m=1;
                dm.h[1][2]=1;
                dm.h[2][2]=x;
                dm.h[2][3]=1;
                dm.h[3][3]=1;
                a.h[1][1]=b;
                a.h[2][1]=(tinh(x,b)+b)%mod;
                a.h[3][1]=b;
                matrix tmp=power(dm,k-1);
                matrix res=tmp*a;
                cout<<res.h[1][1]<<"\n";
        }
        return 0;
}
