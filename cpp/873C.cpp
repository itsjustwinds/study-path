#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int a[maxn][maxn],n,m,k;
int res,c;
int main()
{
        //freopen("873C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
                cin>>a[i][j];
        for (int j=1;j<=m;++j)
        {
                int cnt=0;
                int maxx=0;
                int now=0;
                for (int i=1;i<=n;++i)
                if (a[i][j]==1)
                {
                        int tmp=0;
                        cnt++;
                        for (int h=i;h<=i+min(k,n-i+1)-1;++h)
                        if (a[h][j]==1) ++tmp;
                        if (tmp>maxx)
                        {
                                maxx=tmp;
                                now=cnt;
                        }
                }
                res+=maxx;
                c+=max(0,now-1);
        }
        cout<<res<<" "<<c;
        return 0;
}
