#include<bits/stdc++.h>
#define maxn 25005
#define fs first
#define sc second
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
int d[maxn],n,m,s,t,val[maxn],cnt,h[maxn],dd[maxn],pos[maxn],res;
struct data
{
        int u,v,val,f,c;
};
typedef pair<int,int > II;
II PP[maxn];
vector<data > EDGE;
vector<data > edge;
vector<int > g[maxn],G[maxn],atm;
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.val>b.val;
        }
};
void dijks()
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        q.push({1,0,0,0,0});
        d[1]=0;
        while(!q.empty())
        {
                int u=q.top().u;
                int c=q.top().val;
                q.pop();
                if (c!=d[u]) continue;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=edge[id].v;
                        int l=edge[id].val;
                        if (d[u]+l<d[v])
                        {
                                d[v]=d[u]+l;
                                q.push({v,0,d[v],0,0});
                        }
                }
        }
        for (int i=1;i<=n;++i)
                PP[i]=II(d[i],i);
}
bool bfs()
{
        ++cnt;
        dd[s]=cnt;
        queue<int > q;
        while(!q.empty()) q.pop();
        q.push(s);
        while (!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0;i<G[u].size();++i)
                {
                        int id=G[u][i];
                        int v=EDGE[id].v;
                        if (dd[v]==cnt||EDGE[id].f==EDGE[id].c) continue;
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
        for (;pos[u]<G[u].size();++pos[u])
        {
                int id=G[u][pos[u]];
                int v=EDGE[id].v;
                if (h[v]!=h[u]+1||EDGE[id].f==EDGE[id].c) continue;
                int x=dfs(v,min(low,EDGE[id].c-EDGE[id].f));
                if (x)
                {
                        EDGE[id].f+=x;
                        EDGE[id^1].f-=x;
                        return x;
                }
        }
        return 0;
}
void add_EDGE(int u,int v,int c)
{
        G[u].push_back(EDGE.size());
        EDGE.push_back({u,v,0,0,c});
        G[v].push_back(EDGE.size());
        EDGE.push_back({v,u,0,0,c});
}
void solve()
{
        for(int i=1;i<=n+1;++i)
                G[i].clear();
        EDGE.clear();
        for (int i=0;i<edge.size();++i)
        {
                int u=edge[i].u;
                int v=edge[i].v;
                if (d[u]+edge[i].val==d[v]) add_EDGE(u,v,1);
        }
        for (int i=0;i<atm.size();++i)
        {
                int v=atm[i];
                //cout<<g[s].size()<<" ";
                add_EDGE(s,v,val[v]);
                //cout<<g[s].size()<<"\n";
        }
        while(bfs())
        {
                while(int x=dfs(s,1e9))
                {
                        res+=x;
                }
        }
}
int main()
{
        freopen("main.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        read(n);read(m);read(s);
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                read(u);read(v);read(c);
                g[u].push_back(edge.size());
                edge.push_back({u,v,c,0,1});
                g[v].push_back(edge.size());
                edge.push_back({v,u,c,0,1});
        }
        for (int i=1;i<=s;++i)
        {
                int x;
                read(x);
                val[x]++;
        }
        for (int i=1;i<=n;++i)
                d[i]=1e9;
        dijks();
        s=n+1,t=1;
        sort(PP+1,PP+n+1);
        res+=val[1];
        for (int i=1;i<=n;++i)
        {
                atm.push_back(PP[i].sc);
                if (PP[i].fs!=PP[i+1].fs)
                {
                        if (PP[i].fs!=0)solve();
                        atm.clear();
                }
        }
        write(res);
}
