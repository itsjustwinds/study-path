#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int f[maxn][maxn],n,a[maxn],b[maxn],m,res;
typedef pair<int,int> II;
II ac[maxn];
int main()
{
    freopen("seq2.inp","r",stdin);
    freopen("seq2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int j=1;j<=n;j++)
    for (int i=j;i>=1;i--)
    {
        if (a[i]<a[j]) f[i][j]=f[i+1][j-1]+1;
        f[i][j]=max(f[i][j],max(f[i+1][j],f[i][j-1]));
        res=max(res,f[i][j]);
    }
    cout<<res;
    return 0;
}
