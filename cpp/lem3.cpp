#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000000
using namespace std;
int f[20][maxn],n,a[20][20],res;
int setbit(int c,int k,int x)
{
    if (c==1) return x|(1<<(k-1));
    return x^(1<<(k-1));
}
int get(int k,int n)
{
    return (n>>(k-1))&1;
}
int main()
{
    freopen("lem3.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    int tmp=1;
    for (int i=1; i<=n; i++)
        tmp*=2;
    tmp-=1;
    for (int j=1; j<=n; j++)
        for (int i=1; i<=tmp; i++)
            f[j][i]=oo;
    for (int i=1; i<=n; i++)
    {
        f[i][1<<(i-1)]=0;
    }
    for (int k=3; k<=tmp; k++)
    {
        for (int i=1; i<=n; i++)
        {
            if (!get(i,k)) continue;
            int h=setbit(0,i,k);
            for (int j=1; j<=n; j++)
            {
                if (!get(j,k)) continue;
                if (i==j) continue;
                f[i][k]=min(f[i][k],f[j][h]+a[j][i]);
            }
        }
    }
    res=oo;
    for (int i=1; i<=n; i++)
        res=min(res,f[i][tmp]);
    cout<<res;
    return 0;
}
