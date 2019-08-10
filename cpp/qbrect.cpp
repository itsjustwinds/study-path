#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,h[maxn],res,r[maxn],l[maxn],a[maxn][maxn];
int main()
{
    freopen("qbrect.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    h[0]=-1000000000;
    h[m+1]=-1000000000;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]==1) h[j]++;
            else h[j]=0;
        for (int j=1; j<=m; j++)
        {
            l[j]=j;
            while(h[l[j]-1]>=h[j]) l[j]=l[l[j]-1];
        }
        for (int j=m; j>=1; j--)
        {
            r[j]=j;
            while(h[r[j]+1]>=h[j]) r[j]=r[r[j]+1];
        }
        for (int j=1; j<=m; j++)
            res=max(res,h[j]*(r[j]-l[j]+1));
    }
    cout<<res;
    return 0;
}
