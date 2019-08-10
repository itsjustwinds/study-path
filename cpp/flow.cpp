#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
struct data
{
        int v,f,c;
};
vector<data > e;
vector<int > g[maxn];
int n,m,dd[maxn],d[maxn],s,t,cnt,pos[maxn];
long long res;
bool bfs()
{
        dd[s]=++cnt;
        queue<int >q;
        while(!q.empty()) q.pop();
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0; i<g[u].size(); ++i)
                {
                        int id=g[u][i];
                        int v=e[id].v;
                        if (dd[v]==cnt||e[id].f==e[id].c) continue;
                        dd[v]=cnt;
                        d[v]=d[u]+1;
                        q.push(v);
                }
        }
        return dd[t]==cnt;
}
int dfs(int u,int val)
{
        if (u==t||val==0) return val;
        for (; pos[u]<g[u].size(); ++pos[u])
        {
                int id=g[u][pos[u]];
                int v=e[id].v;
                if (d[v]!=d[u]+1||e[id].c==e[id].f) continue;
                int tmp=dfs(v,min(val,e[id].c-e[id].f));
                if (tmp)
                {
                        e[id].f+=tmp;
                        e[id^1].f-=tmp;
                        return tmp;
                }
        }
        return 0;
}
int main()
{
        freopen("FLOW.inp","r",stdin);
        freopen("FLOW.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>s>>t;
        for (int i=1; i<=m; ++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                g[u].push_back(e.size());
                e.push_back({v,0,c});
                g[v].push_back(e.size());
                e.push_back({u,0,0});
        }
        while(bfs())
        {
                while(int x=dfs(s,1000000000))
                {
                        res+=x;
                }
        }
        cout<<res<<"\n";
        return 0;
}

