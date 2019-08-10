#include<bits/stdc++.h>
#define maxn 25
using namespace std;
int k,n;
struct matrix
{
    int n,m;
    int h[maxn][maxn];
};
matrix a;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            c.h[i][j]=0;
            for (int k=1; k<=n; k++)
                c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%10;
        }
    return c;
}
matrix power(int n)
{
    if (n==1) return a;
    matrix tmp=power(n/2);
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    freopen("mat.inp","r",stdin);
    //freopen("mat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    a.n=n;
    a.m=n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            int x;
            cin>>x;
            a.h[i][j]=x%10;
        }
    matrix res;
    res=power(k);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout<<res.h[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
