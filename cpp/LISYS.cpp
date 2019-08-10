#include<bits/stdc++.h>
#define mod 3
using namespace std;
int n,m,s,res;
vector<vector<int > > a;
int col[50005],row[50005];
int main()
{
        freopen("LISYS.inp","r",stdin);
        freopen("LISYS.out","w",stdout);
        scanf("%d%d%d",&n,&m,&s);
        a.resize(n+1);
        for (int i=1; i<=n; ++i)
        {
                a[i].resize(m+1);
                for (int j=1; j<=m; ++j)
                        scanf("%d",&a[i][j]);
        }
        while(s--)
        {
                int k;
                scanf("%d",&k);
                if (k<=n)
                {
                        row[k]++;
                }
                else col[k-n]++;
        }
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        int x=(a[i][j]+row[i]+col[j])%mod;
                        if (x==0)++res;
                }
        printf("%d",res);
        return 0;
}
