#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,k;
int val[maxn],res,trc[maxn],a[maxn],m,d;
vector<int > e[maxn];
void DFS(int u)
{
        val[u]+=a[u];
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                trc[v]=u;
                DFS(v);
                val[u]+=val[v];
        }
}
int dfs(int u)
{
        int sum=0;
        if (val[u]<=m)
        {
                int t=trc[u];
                if (val[t]<=m)
                {
                        return sum;
                }
                ++d;
                return val[u];
        }
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                sum+=dfs(v);
                if (val[u]-sum<=m)
                {
                        ++d;
                        return val[u];
                }
        }
        if (val[u]-sum<=m)
        {
                int t=trc[u];
                if (val[t]-sum<=m)
                {
                        return sum;
                }
                sum=val[u];
                ++d;
                return sum;
        }
        return sum;
}
bool check()
{
        d=0;
        dfs(1);
        if (d>k+1) return 0;
        return 1;
}
bool cmp(int a,int b)
{
        return val[a]<val[b];
}
int main()
{
        freopen("VMCUT2.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=2;i<=n;++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        DFS(1);
        for (int i=1;i<=n;++i)
                sort(e[i].begin(),e[i].end(),cmp);
        int l=20,r=20;
        while(l<=r)
        {
                m=(l+r)>>1;
                if (check())
                {
                        res=m;
                        r=m-1;
                }
                else l=m+1;
        }
        cout<<res;
        return 0;
}
