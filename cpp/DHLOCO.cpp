#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
        int n,m;
        ll h[5][5];
};
ll n,mod;
matrix a,dm;
matrix operator *(matrix a,matrix b)
{
        matrix c;
        c.n=a.n;
        c.m=b.m;
        for (int i=1; i<=c.n; i++)
                for (int j=1; j<=c.m; j++)
                {
                        c.h[i][j]=0;
                        for (int k=1; k<=a.m; k++)
                                c.h[i][j]=(c.h[i][j]+((ll)a.h[i][k]*b.h[k][j])%mod+mod)%mod;
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
        freopen("DHLOCO.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>mod;
        if (n==1)
        {
                cout<<1%mod;
                return 0;
        }
        a.n=3;
        a.m=3;
        dm.n=3;
        dm.m=1;
        a.h[1][2]=1;
        a.h[2][3]=1;
        a.h[3][1]=1;
        a.h[3][2]=1;
        a.h[3][3]=1;
        dm.h[1][1]=1;
        dm.h[2][1]=2;
        dm.h[3][1]=4;
        matrix tmp=power(a,n-1);
        matrix res=tmp*dm;
        cout<<res.h[1][1];
        return 0;

}
