#include<bits/stdc++.h>
#define maxn 2005
#define ll long long
using namespace std;
ll f[605][605][605],MAX[maxn][30];
int n,c[maxn];
ll tinh(int l,int r,int lever)
{
        if (l>r) return 0;
        if (f[l][r][lever]!=1e18) return f[l][r][lever];
        if (l==r)
        {
                f[l][r][lever]=1ll*lever*c[l];
                return f[l][r][lever];
        }
        for (int i=l; i<=r; ++i)
        {
                f[l][r][lever]=min(f[l][r][lever],tinh(l,i-1,lever+1)+tinh(i+1,r,lever+1)+1ll*lever*c[i]);
        }
        return f[l][r][lever];
}
int main()
{
        freopen("OPTBST.inp","r",stdin);
        freopen("OPTBST.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                cin>>c[i];
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                        for (int k=1; k<=n; ++k)
                                f[i][j][k]=1e18;
        if (n<=600) cout<<tinh(1,n,1);
        return 0;
}
