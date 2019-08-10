#include<bits/stdc++.h>
#define mod 1000000000000007ll
#define ll long long
using namespace std;
int test,n;
struct matrix
{
        int n,m;
        ll h[10][10];
};
matrix base,a;
ll nhan(ll a,ll n)
{
        if (n==0) return 0;
        if (n==1) return a%mod;
        ll tmp=nhan(a,n>>1);
        tmp=(tmp+tmp)%mod;
        if (n&1) tmp=(tmp+a)%mod;
        return tmp;
}
matrix operator *(matrix a,matrix b)
{
        matrix c;
        c.n=a.n;c.m=a.m;
        for (int i=1;i<=c.n;++i)
                for (int j=1;j<=c.m;++j)
        {
                c.h[i][j]=0;
                for (int k=1;k<=a.m;++k)
                {
                        c.h[i][j]=((ll)c.h[i][j]+nhan(a.h[i][k],b.h[k][j]))%mod;
                }
        }
        return c;
}
matrix power(matrix a,int n)
{
        if (n==1) return a;
        matrix tmp=power(a,n>>1);
        tmp=tmp*tmp;
        if(n&1) tmp=tmp*a;
        return tmp;
}
int main()
{
        freopen("VOSTRIBO.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        base.n=4;base.m=4;
        base.h[1][2]=1;
        base.h[2][3]=1;
        base.h[3][1]=1;base.h[3][2]=1;base.h[3][3]=1;
        base.h[4][2]=1;base.h[4][4]=1;
        a.n=1;a.m=4;
        a.h[1][1]=1;
        a.h[2][1]=2;
        a.h[3][1]=3;
        a.h[4][1]=1;
        cin>>test;
        while(test--)
        {
                cin>>n;
                if (n==1)
                {
                        cout<<a.h[4][1]<<"\n";
                        continue;
                }
                matrix tmp=power(base,n-1);
                tmp=tmp*a;
                cout<<tmp.h[4][1]<<"\n";
        }
        return 0;
}
