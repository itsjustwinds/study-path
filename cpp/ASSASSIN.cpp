#include<bits/stdc++.h>
#define maxn 3005
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
int num[maxn],low[maxn],cnt,n,m,pos[maxn],dem,dd[maxn][maxn];
stack<int > st;
int DD[maxn],d[maxn];
vector<int > edge[maxn];
typedef pair<int,int >II;
bitset<maxn > f[maxn];
vector<II > ED;
int s,t;
struct data
{
        int u,v,c,f;
};
vector<int >g[maxn],e[maxn];
vector<data > EDGE;
void add_edge(int u,int v,int c)
{
        g[u].push_back(EDGE.size());
        EDGE.push_back({u,v,0,c});
        g[v].push_back(EDGE.size());
        EDGE.push_back({v,u,0,0});
}
void DFS(int u)
{
        f[u].set(u);
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                DFS(v);
                f[u]|=f[v];
        }
}
void dfs(int u)
{
        num[u]=low[u]=++cnt;
        st.push(u);
        for (int i=0;i<edge[u].size();++i)
        {
                int v=edge[u][i];
                if (num[v]) low[u]=min(low[u],num[v]);
                else
                {
                        dfs(v);
                        low[u]=min(low[u],low[v]);
                }
        }
        if (num[u]==low[u])
        {
                ++dem;
                while(1)
                {
                        int t=st.top();
                        pos[t]=dem;
                        num[t]=low[t]=1e9;
                        st.pop();
                        if (t==u) break;
                }
        }
}
bool bfs()
{
        DD[s]=++cnt;
        queue<int >q;
        q.push(s);
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                pos[u]=0;
                for (int i=0;i<g[u].size();++i)
                {
                        int id=g[u][i];
                        int v=EDGE[id].v;
                        if (DD[v]==cnt||EDGE[id].f==EDGE[id].c) continue;
                        DD[v]=cnt;
                        d[v]=d[u]+1;
                        q.push(v);
                }
        }
        return DD[t]==cnt;
}
int dfsx(int u,int low)
{
        if (u==t||low==0) return low;
        for (;pos[u]<g[u].size();++pos[u])
        {
                int id=g[u][pos[u]];
                int v=EDGE[id].v;
                if (d[v]!=d[u]+1||EDGE[id].f>=EDGE[id].c) continue;
                int x=dfsx(v,min(low,EDGE[id].c-EDGE[id].f));
                if (x!=0)
                {
                        EDGE[id].f+=x;
                        EDGE[id^1].f-=x;
                        return x;
                }
        }
        return 0;
}
int main()
{
        freopen("ASSASSIN.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        int test;
        read(test);
        for (int ii=1;ii<=test;++ii)
        {
                cin>>n>>m;
                for (int i=1;i<=n;++i)
                {
                        num[i]=0;
                        low[i]=0;
                }
                ED.clear();
                cnt=0;
                dem=0;
                for (int i=1;i<=n;++i)
                {
                        //e[i].clear();
                        edge[i].clear();
                }
                for (int i=1;i<=m;++i)
                {
                        int u,v;
                        read(u);read(v);
                        edge[u].push_back(v);
                        ED.push_back(II(u,v));
                }
                for (int i=1;i<=n;++i)
                if (!num[i]) dfs(i);
                for (int i=0;i<ED.size();++i)
                {
                        int u=ED[i].fs;
                        int v=ED[i].sc;
                        int pu=pos[u];
                        int pv=pos[v];
                        if (pu==pv||dd[pu][pv]) continue;
                        dd[pu][pv]=1;
                        e[pu].push_back(pv);
                }
                EDGE.clear();
                for (int i=1;i<=dem;++i)
                        g[i].clear();
                for (int i=1;i<=dem;++i)
                        f[i].reset();
                for (int i=1;i<=dem;++i)
                if (f[i].count()==0)
                {
                        DFS(i);
                }
                for (int i=1;i<=dem;++i)
                {
                        for (int j=1;j<=dem;++j)
                        {
                                int k=f[i].test(j);
                                if (k)
                                {
                                        add_edge(i,j+dem,1);
                                }
                        }
                }
                s=2*n+1;
                t=2*n+2;
                for (int i=1;i<=n;++i)
                        add_edge(s,i,1);
                for (int i=n+1;i<=2*n;++i)
                        add_edge(i,t,1);
                int res=n;
                cnt=0;
                while(bfs())
                {
                        while(int x=dfsx(s,1e9))
                        {
                                res-=x;
                        }
                }
                cout<<res<<"\n";
        }
        return 0;
}
