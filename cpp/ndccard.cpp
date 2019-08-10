#include<bits/stdc++.h>
#define maxn 10005
#define oo 1000000007
using namespace std;
int a[maxn],f[maxn][5],n,m;
long long res;
int main()
{
    freopen("ndccard.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    //sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        for (int j=2;j<=3;j++)
        f[i][j]=-oo;
    for (int i=1; i<=n; i++)
    {
        f[i][1]=a[i];
        for (int j=2; j<=3; j++)
        {
            for (int k=1; k<=i-1; k++)
                if (f[k][j-1]+a[i]<=m)
                    f[i][j]=max(f[i][j],f[k][j-1]+a[i]);
        }
    }
    res=0;
    for (int i=1; i<=n; i++)
    {
        res=max(res,(long long)f[i][3]);
    }
    cout<<res;
    return 0;
}

