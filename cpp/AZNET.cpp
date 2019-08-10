#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
        int u,v;
};
int root[maxn],n,m,minn,maxx,a[3][maxn],k,sl[3],dm[3][maxn],dem,ans[maxn];
data c[maxn];
int findroot(int u)
{
        if (root[u]==u) return u;
        root[u]=findroot(root[u]);
        return root[u];
}
void resetroot()
{
        for (int i=1; i<=n; i++)
                root[i]=i;
}
void solve()
{
        resetroot();
        maxx=0;
        minn=n-1;
        for (int i=1; i<=sl[1]; i++)
        {
                int tmp=dm[1][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                maxx++;
                root[ru]=rv;
        }
        resetroot();
        for (int i=1; i<=sl[2]; i++)
        {
                int tmp=dm[2][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                minn--;
                root[ru]=rv;
        }
        int res=2123456789;
        for (int i=minn; i<=maxx; i++)
                if (a[1][i]+a[2][n-i-1]<res)
                {
                        res=a[1][i]+a[2][n-i-1];
                        k=i;
                }
        memset(ans,0,sizeof(ans));
        dem=0;
        resetroot();
        for (int i=1; i<=sl[1]; i++)
        {
                int tmp=dm[1][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                dem++;
                ans[tmp]=1;
                root[ru]=rv;
                if (dem==k) break;
        }
        for (int i=1; i<=sl[2]; i++)
        {
                int tmp=dm[2][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                dem++;
                ans[tmp]=1;
                root[ru]=rv;
                if (dem==n-1) break;
        }
        if (dem==n-1)
        {
                for (int i=1; i<=m; i++)
                        if (ans[i]) cout<<i<<" ";
                return;
        }
        memset(ans,0,sizeof(ans));
        dem=0;
        resetroot();
        for (int i=1; i<=sl[2]; i++)
        {
                int tmp=dm[2][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                dem++;
                ans[tmp]=1;
                root[ru]=rv;
                if (dem==n-k-1) break;
        }
        for (int i=1; i<=sl[1]; i++)
        {
                int tmp=dm[1][i];
                int u=c[tmp].u;
                int v=c[tmp].v;
                int ru=findroot(u);
                int rv=findroot(v);
                if (ru==rv) continue;
                dem++;
                ans[tmp]=1;
                root[ru]=rv;
                if (dem==n-1) break;
        }
        for (int i=1; i<=m; i++)
                if (ans[i]) cout<<i<<" ";
}
int main()
{
        freopen("D:\\C++\\debug\\AZNET.inp","r",stdin);
        //freopen("D:\\C++\\debug\\AZNET.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n>>m;
                sl[1]=0;
                sl[2]=0;
                for (int i=1; i<=2; i++)
                {
                        for (int j=1; j<n; j++)
                                cin>>a[i][j];
                }
                for (int i=1; i<=m; i++)
                {
                        int u,v,w;
                        cin>>u>>v>>w;
                        dm[w][++sl[w]]=i;
                        c[i].u=u;
                        c[i].v=v;
                }
                solve();
                cout<<"\n";
        }
}
