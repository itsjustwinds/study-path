#include<bits/stdc++.h>
#define maxn 305
using namespace std;
int a[maxn],ans,n,m,test,h[maxn],dd[maxn],pos[maxn],cnt,s,t;
struct data
{
        int v,f,c;
};
vector<data > e;
vector<int > g[maxn];
bool bfs()
{
        dd[s]=++cnt;
        queue<int > q;
        while(!q.empty()) q.pop();
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=e[id].v;
                        if (dd[v]==cnt||e[id].f==e[id].c) continue;
                        dd[v]=cnt;
                        h[v]=h[u]+1;
                        q.push(v);
                }
        }
        return dd[t]==cnt;
}
int dfs(int u,int low)
{
        if (u==t||low==0) return low;
        for (;pos[u]<g[u].size();++pos[u])
        {
                int id=g[u][pos[u]];
                int v=e[id].v;
                if (h[v]!=h[u]+1) continue;
                if (e[id].f==e[id].c) continue;
                int get=dfs(v,min(low,e[id].c-e[id].f));
                if (get)
                {
                        e[id].f+=get;
                        e[id^1].f-=get;
                        return get;
                }
        }
        return 0;
}
void read(int &n)
{
        n=0;
        char c=getchar();
        int neg=0;
        if (c=='-') neg=1;
        for (;c>='0'&&c<='9';c=getchar())
        {
                n=n*10+(c-'0');
        }
        if (neg) n*=-1;
}
int main()
{
        freopen("COCONUTS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        while(1)
        {
                read(n);
                read(m);
                if (n==0&&m==0) break;
                for (int i=1; i<=n; ++i)
                        read(a[i]);
                e.clear();
                for (int i=0; i<=n+1; ++i)
                        g[i].clear();
                s=0;
                t=n+1;
                ans=0;
                h[s]=1;
                for (int i=1; i<=m; ++i)
                {
                        int u,v;
                        read(u);
                        read(v);
                        g[u].push_back(e.size());
                        e.push_back({v,0,1});
                        g[v].push_back(e.size());
                        e.push_back({u,0,1});
                }
                for (int i=1; i<=n; ++i)
                {
                        if (a[i])
                        {
                                g[s].push_back(e.size());
                                e.push_back({i,0,1});
                                g[i].push_back(e.size());
                                e.push_back({s,0,0});
                                continue;
                        }
                        g[i].push_back(e.size());
                        e.push_back({t,0,1});
                        g[t].push_back(e.size());
                        e.push_back({i,0,0});
                }
                while(bfs())
                {
                        while(int x=dfs(s,1e9))
                        {
                                ans+=x;
                        }
                }
                cout<<ans<<"\n";
        }
}
