#include<bits/stdc++.h>
#define oo 10000005
#define maxn 105
using namespace std;
int f[maxn][maxn],n,m,a[maxn][maxn],maxx;
int main()
{
    freopen("lip.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t)
    {
        t--;
        maxx=0;
        cin>>n>>m;
        for (int j=0; j<=m; j++)
            a[0][j]=oo;
        for (int i=0; i<=n; i++)
            a[i][0]=oo;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                f[i][j]=-oo;
        f[1][1]=1;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                cin>>a[i][j];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                if (a[i-1][j]<a[i][j]) f[i][j]=max(f[i][j],f[i-1][j]+1);
                if (a[i][j-1]<a[i][j]) f[i][j]=max(f[i][j],f[i][j-1]+1);
                if (f[i][j]>maxx) maxx=f[i][j];
            }
        cout<<maxx<<"\n";
    }
}
