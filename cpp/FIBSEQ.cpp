#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
ll m;
int n;
int a[maxn],sum,mod,dd[maxn];
struct matrix
{
    int n,m;
    int h[5][5];
};
matrix dmcd,fck;
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
                c.h[i][j]=(c.h[i][j]+((ll)a.h[i][k]*b.h[k][j])%mod)%mod;
        }
    return c;
}
matrix power(matrix a,ll n)
{
    if (n==1) return a;
    matrix tmp=power(a,n>>1);
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    freopen("FIBSEQ.inp","r",stdin);
    freopen("FIBSEQ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    dmcd.n=2;
    dmcd.m=2;
    dmcd.h[1][2]=1;
    dmcd.h[2][1]=1;
    dmcd.h[2][2]=1;
    fck.n=2;
    fck.m=1;
    fck.h[1][1]=1;
    fck.h[2][1]=1;
    while(test--)
    {
        int ok=0;
        cin>>n>>m>>mod;
        if (m==1)
        {
            a[1]=1;
            a[2]=1;
        }
        else if (m==2)
        {
            a[1]=1;
            a[2]=2;
        }
        else
        {
            matrix tmp=power(dmcd,m-2);
            matrix temp=tmp*fck;
            a[1]=temp.h[2][1];
            tmp=power(dmcd,m-1);
            temp=tmp*fck;
            a[2]=temp.h[2][1];
        }
        for (int i=3; i<=n; i++)
            a[i]=(a[i-1]+a[i-2])%mod;
        sum=0;
        memset(dd,-1,sizeof(dd));
        for (int i=1;i<=n;i++)
        {
            sum=(sum+a[i])%mod;
            if (sum==0)
            {
                cout<<i<<" ";
                for (int j=1;j<=i;j++)
                    cout<<m+j-1<<" ";
                cout<<"\n";
                break;
            }
            if (dd[sum]==-1) dd[sum]=i;
            else
            {
                cout<<i-dd[sum]<<" ";
                for (int j=dd[sum]+1;j<=i;j++)
                    cout<<m+j-1<<" ";
                cout<<"\n";
                break;
            }
        }
    }
    return 0;
}
