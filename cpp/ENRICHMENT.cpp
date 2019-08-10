#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > a,sum;
int n,m,res;
int main()
{
        freopen("ENRICHMENT.inp","r",stdin);
        //freopen("ENRICHMENT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        a.resize(n+1);
        sum.resize(n+1);
        for (int i=0; i<=n; ++i)
        {
                a[i].resize(m+1);
                sum[i].resize(m+1);
        }
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        cin>>a[i][j];
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
                }
        res=1e9;
        for (int i=3; i<=n; ++i)
                for (int j=3; j<=m; ++j)
                {
                        res=min(res,sum[i][j]-sum[i-3][j]-sum[i][j-3]+sum[i-3][j-3]);
                }
        cout<<res;
        return 0;
}
