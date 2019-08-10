#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
using namespace std;
ll f[maxn][505],res;
int n,k;
vector<int >e[maxn];
void dfs(int u,int trc)
{
        f[u][0]=1;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                dfs(v,u);
                for (int j=0;j<k;++j)
                        res+=1ll*f[u][j]*f[v][k-j-1];
                for (int j=1;j<k;++j)
                        f[u][j]+=f[v][j-1];
        }
}
int main()
{
        freopen("DISTTREE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=2;i<=n;++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        dfs(1,-1);
        cout<<res;
        return 0;
}
