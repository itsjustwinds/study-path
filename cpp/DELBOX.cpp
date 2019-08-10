#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn][maxn],dd[maxn][maxn],n,m,maxxi[maxn],maxxj[maxn];
long long res;
int main()
{
        freopen("DELBOX.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        cin>>a[i][j];
                        maxxi[i]=max(maxxi[i],a[i][j]);
                        maxxj[j]=max(maxxj[j],a[i][j]);
                }
        for (int i=1; i<=n; ++i)
        {
                int maxx=0;
                for (int j=1; j<=m; ++j)
                {
                        int cnt=0;
                        if (a[i][j]==maxxi[i])++cnt;
                        if (a[i][j]==maxxj[j])++cnt;
                        maxx=max(maxx,cnt);
                        if (cnt!=2) res+=a[i][j];
                }
                if (maxx!=2) res-=maxxi[i];
        }
        cout<<res;
}
