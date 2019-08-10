#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int high[maxn],n,m,s,dd[maxn],f[maxn][maxn],res;
vector<int > e[maxn];
void bfs()
{
        queue<int >q;
        while(!q.empty()) q.pop();
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (!high[v])
                        {
                                high[v]=high[u]+1;
                                if (dd[u]) dd[v]=1;
                                q.push(v);
                                continue;
                        }
                        if (high[v]==high[u]+1) dd[v]=1;
                }
        }
}
int main()
{
        freopen("STABLE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>s;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                if (f[u][v] ) continue;
                f[u][v]=1;
                e[u].push_back(v);
        }
        high[s]=1;
        bfs();
        for (int i=1;i<=n;++i)
                res+=(dd[i]==1);
        cout<<res;
        return 0;
}
