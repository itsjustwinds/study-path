#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll f[maxn][2];
int n,a[maxn];
vector<int >e[maxn];
void dfs(int u)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                dfs(v);
                f[u][0]+=max(0LL,max(f[v][0],f[v][1]));
                f[u][1]+=max(0LL,f[v][0]);
        }
        f[u][1]+=a[u];
}
int main()
{
        freopen("BUATIEC.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=2;i<=n;++i)
        {
                int u,v;
                cin>>u>>v;
                e[v].push_back(u);
        }
        dfs(1);
        cout<<f[1][1];
        return 0;
}
