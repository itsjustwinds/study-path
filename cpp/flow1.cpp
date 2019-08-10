#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,m,pos[maxn],s,t,res,cnt,dd[maxn],d[maxn];
vector<int >g[maxn];
struct data
{
        int u,v,f,c;
};
vector<data >edge;
string S;
data f[maxn];
void ed(int s,int t)
{
        g[s].push_back(edge.size());
        edge.push_back({s,t,0,1});
        g[t].push_back(edge.size());
        edge.push_back({t,s,0,0});
}
bool bfs()
{
        dd[s]=++cnt;
        queue<int > q;
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0; i<g[u].size(); ++i)
                {
                        int id=g[u][i];
                        int v=edge[id].v;
                        if (dd[v]==cnt||edge[id].f>=edge[id].c) continue;
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
        for(; pos[u]<g[u].size(); ++pos[u])
        {
                int id=g[u][pos[u]];
                int v=edge[id].v;
                if (d[v]!=d[u]+1||edge[id].f==edge[id].c) continue;
                int x=dfs(v,min(val,edge[id].c-edge[id].f));
                if (x!=0)
                {
                        edge[id].f+=x;
                        edge[id^1].f-=x;
                        return x;
                }
        }
        return 0;
}

int main()
{
        freopen("FLOW1.inp","r",stdin);
        //freopen("FLOW1.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        s=2*n+2*m+1;
        t=2*n+2*m+2;
        for (int i=1; i<=n; ++i)
        {
                ed(s,i);
                ed(n+i,t);
        }
        getline(cin,S);
        for (int i=1; i<=n; ++i)
        {
                getline(cin,S);
                int t=0;
                stringstream ss(S);
                while(ss >> t)
                {
                        ed(i,2*n+t);
                }
        }
        for (int i=1;i<=m;++i)
        {
                ed(2*n+i,2*n+m+i);
        }
        for (int i=1; i<=n; ++i)
        {
                getline(cin,S);
                int t=0;
                stringstream ss(S);
                while(ss >> t)
                {
                        ed(2*n+m+t,n+i);
                }
        }
        while(bfs())
        {
                int x=0;
                while(x=dfs(s,1e9)!=0)
                {
                        res+=x;
                }
        }
        for (int i=0;i<edge.size();i+=2)
        {
                if (edge[i].f!=1) continue;
                int u=edge[i].u;
                int v=edge[i].v;
                if (v>=2*n+1&&v<=2*n+m)
                {
                        f[v-2*n].u=u;
                }
                if (u>=2*n+m+1&&u<=2*n+2*m)
                {
                        f[u-2*n-m].v=v-n;
                }
        }
        for (int i=1;i<=m;++i)
                cout<<f[i].u<<" "<<f[i].v<<"\n";
        return 0;
}
