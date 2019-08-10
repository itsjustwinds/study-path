#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
ll res;
int f[maxn],n;
struct data
{
        int u,v;
        ll c;
};
data edge[maxn];
vector<int > e[maxn];
void dfs(int u,int trc)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                dfs(v,u);
                f[u]+=f[v];
        }
        ++f[u];
}
int main()
{
        freopen("NTTREE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for(int i=1;i<n;++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                u++;v++;
                edge[i]={u,v,c};
                e[u].push_back(v);
                e[v].push_back(u);
        }
        dfs(1,-1);
        for (int i=1;i<n;++i)
        {
                int u=edge[i].u;
                int v=edge[i].v;
                ll c=edge[i].c;
                int tmp=min(f[u],f[v]);
                res+=1ll*c*tmp*(n-tmp);
        }
        cout<<res;
        return 0;
}
