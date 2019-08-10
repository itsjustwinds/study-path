#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int match[2*maxn],n,m,NIL,d[2*maxn];
vector<int > e[2*maxn];
bool bfs()
{
        queue<int >q;
        while(!q.empty()) q.pop();
        for (int i=1;i<=n;++i)
        if (match[i]==NIL)
        {
                d[i]=0;
                q.push(i);
        }
        else d[i]=1e9;
        d[NIL]=1e9;
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (d[match[v]]==1e9)
                        {
                                d[match[v]]=d[u]+1;
                                q.push(match[v]);
                        }
                }
        }
        return d[NIL]!=1e9;
}
bool dfs(int u)
{
        if (u==NIL) return 1;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (d[match[v]]!=d[u]+1) continue;
                bool x=dfs(match[v]);
                if (x)
                {
                        match[v]=u;
                        match[u]=v;
                        return 1;
                }
        }
        d[u]=1e9;
        return 0;
}
int main()
{
        freopen("MATCH1.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        int u,v;
        while(cin>>u>>v)
        {
                v+=n;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        int res=0;
        while(bfs())
        {
                for (int i=1;i<=n;++i)
                if (match[i]==NIL&&dfs(i)) ++res;
        }
        cout<<res<<"\n";
        for (int i=1;i<=n;++i)
        if (match[i]!=NIL) cout<<i<<" "<<match[i]-n<<"\n";
}
