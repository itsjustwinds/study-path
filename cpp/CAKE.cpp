#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll g[maxn][maxn];
int x1[maxn],y1[maxn],x2[maxn],y2[maxn],a[2*maxn],d;
int n,m,k,dd[maxn][maxn];
ll bat(ll x,int k)
{
        return x|(1ll<<k);
}
bool check(int i,int j)
{
        return i>=1&&i<=m&&j>=1&&j<=n;
}
void dfs(int i,int j)
{
        dd[i][j]=1;
        if (check(i-1,j)&&dd[i-1][j]==0&&g[i][j]==g[i-1][j]) dfs(i-1,j);
        if (check(i+1,j)&&dd[i+1][j]==0&&g[i][j]==g[i+1][j]) dfs(i+1,j);
        if (check(i,j-1)&&dd[i][j-1]==0&&g[i][j]==g[i][j-1]) dfs(i,j-1);
        if (check(i,j+1)&&dd[i][j+1]==0&&g[i][j]==g[i][j+1]) dfs(i,j+1);
}
int main()
{
        freopen("CAKE.inp","r",stdin);
        freopen("CAKE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        while(1)
        {
                cin>>n>>m;
                if (n==0&&m==0) break;
                cin>>k;
                for (int i=1;i<=k;++i)
                {
                        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
                        if (y1[i]>y2[i])
                        {
                                swap(x1[i],x2[i]);
                                swap(y1[i],y2[i]);
                        }
                        if (x1[i]>x2[i]) swap(x1[i],x2[i]);
                        x1[i]++;y1[i]++;
                }
                /*d=1;
                a[1]=0;
                for (int i=1;i<=k;++i) a[++d]=x1[i];
                for (int i=1;i<=k;++i) a[++d]=x2[i];
                sort(a+1,a+d+1);
                for (int i=1;i<=k;++i)
                {
                        x1[i]=lower_bound(a+1,a+d+1,x1[i])-a;
                        x2[i]=lower_bound(a+1,a+d+1,x2[i])-a;
                }
                d=1;
                a[1]=0;
                for (int i=1;i<=k;++i) a[++d]=y1[i];
                for (int i=1;i<=k;++i) a[++d]=y2[i];
                sort(a+1,a+d+1);
                for (int i=1;i<=k;++i)
                {
                        y1[i]=lower_bound(a+1,a+d+1,y1[i])-a;
                        y2[i]=lower_bound(a+1,a+d+1,y2[i])-a;
                }
                for (int i=1;i<=d;++i)
                        for (int j=1;j<=d;++j)
                        {
                        g[i][j]=0;
                        dd[i][j]=0;
                        }*/
                for (int i=1;i<=m;++i)
                        for (int j=1;j<=n;++j)
                {
                        g[i][j]=0;
                        dd[i][j]=0;
                }
                for (int h=1;h<=k;++h)
                {
                        for (int i=x1[h];i<=x2[h];++i)
                                for (int j=y1[h];j<=y2[h];++j)
                                g[i][j]=bat(g[i][j],h);
                }
                int res=0;
                for (int i=1;i<=m;++i)
                        for (int j=1;j<=n;++j)
                if (!dd[i][j])
                {
                        ++res;
                        dfs(i,j);
                }
                cout<<res<<"\n";
        }
}
