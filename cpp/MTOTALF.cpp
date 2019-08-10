#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,res;
struct data
{
            int v,f,c;
};
vector<data> e;
vector<int> g[maxn];
int pos[maxn],dd[maxn],cnt,s,t,d[maxn];
bool bfs()
{
            dd[s]=++cnt;
            queue<int> q;
            while(!q.empty()) q.pop();
            q.push(s);
            while(!q.empty())
            {
                        int u=q.front();
                        pos[u]=0;
                        q.pop();
                        for (int i=0;i<(int)g[u].size();++i)
                        {
                                    int id=g[u][i];
                                    int v=e[id].v;
                                    if (dd[v]==cnt||e[id].f==e[id].c) continue;
                                    dd[v]=cnt;
                                    d[v]=d[u]+1;
                                    if (v==t) return 1;
                                    q.push(v);
                        }
            }
            return dd[t]==cnt;
}
int dfs(int u,int low)
{
            if (u==t||low==0) return low;
            for (;pos[u]<(int)g[u].size();++pos[u])
            {
                        int id=g[u][pos[u]];
                        int v=e[id].v;
                        if (d[v]!=d[u]+1||e[id].f==e[id].c) continue;
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
int main()
{
            freopen("MTOTALF.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            s='A'-'A'+1;
            t='Z'-'A'+1;
            for (int i=1;i<=n;++i)
            {
                        int u,v,w;
                        char x,y;
                        cin>>x>>y>>w;
                        u=x-'A'+1;
                        v=y-'A'+1;
                        data tmp;
                        tmp.v=v;
                        tmp.f=0;
                        tmp.c=w;
                        g[u].push_back(e.size());
                        e.push_back(tmp);
                        tmp.v=u;
                        g[v].push_back(e.size());
                        e.push_back(tmp);
            }
            while(bfs())
            {
                        while(int x=dfs(s,1000000))
                                    res+=x;
            }
            cout<<res;
            return 0;
}
