#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int f[maxn][maxn],n,a[maxn],res;
int main()
{
    freopen("seq1.inp","r",stdin);
    freopen("seq1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int tmp=1;tmp<n;tmp++)
    {
        memset(f,0,sizeof(f));
        for (int i=1;i<=tmp;i++)
            for (int j=tmp+1;j<=n;j++)
        {
            if (a[i]<a[j]) f[i][j]=f[i-1][j-1]+1;
            f[i][j]=max(f[i][j],f[i-1][j]);
            f[i][j]=max(f[i][j],f[i][j-1]);
            res=max(res,f[i][j]);
        }
    }
    cout<<res;
    return 0;
}
