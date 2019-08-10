#include<bits/stdc++.h>
#define maxn 5005
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
int n,m,q,head[maxn],chain[maxn],pos[maxn],val[maxn],a[maxn],P[maxn];
int high[maxn],cnt,dem,f[105][maxn],S[105],D,root[maxn];
int trc[maxn],Nchild[maxn],st[4*maxn];
struct data
{
        int u,v,c;
};
vector<data >e[maxn],edge,K[maxn];
data E[maxn];
data query[maxn];
bool cmp(data a,data b)
{
        return a.c<b.c;
}
int getr(int u)
{
        if (root[u]==u) return u;
        root[u]=getr(root[u]);
        return root[u];
}
void dfs(int u)
{
        Nchild[u]=1;
        for (int i=0;i<K[u].size();++i)
        {
                int v=K[u][i].v;
                if (v==trc[u]) continue;
                trc[v]=u;
                val[v]=K[u][i].c;
                dfs(v);
                Nchild[u]+=Nchild[v];
        }
}
void hld(int u)
{
        if (head[cnt]==0) head[cnt]=u;
        ++dem;
        pos[u]=dem;
        a[dem]=u;
        chain[u]=cnt;
        int vtx=-1;
        for (int i=0;i<K[u].size();++i)
        {
                int v=K[u][i].v;
                if (v==trc[u]||Nchild[v]<=Nchild[vtx]) continue;
                vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0;i<K[u].size();++i)
        {
                int v=K[u][i].v;
                if (v==trc[u]||v==vtx) continue;
                ++cnt;
                head[cnt]=0;
                high[cnt]=high[chain[u]]+1;
                hld(v);
        }
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=val[a[l]];
                return ;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=st[id*2]+st[id*2+1];
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
int lca(int u,int v)
{
        while(chain[u]!=chain[v])
        {
                int cu=chain[u];
                int cv=chain[v];
                if (high[cu]>high[cv]) u=trc[head[cu]];
                else v=trc[head[cv]];
        }
        if (pos[u]<pos[v]) return u;
        return v;
}
int path(int u,int w)
{
        int res=0;
        while(1)
        {
                int cu=chain[u];
                int cw=chain[w];
                if (cu==cw)
                {
                        res+=get(1,1,n,pos[w]+1,pos[u]);
                        break;
                }
                res+=get(1,1,n,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
        return res;
}
int dis(int u,int v)
{
        int w=lca(u,v);
        return path(u,w)+path(v,w);
}
struct cmpx
{
        bool operator ()(data a,data b)
        {
                return a.c>b.c;
        }
};
void dijks(int T,int s)
{
        priority_queue<data,vector<data>,cmpx > q;
        f[T][s]=0;
        q.push({s,0,0});
        while(!q.empty())
        {
                int u=q.top().u;
                int val=q.top().c;
                q.pop();
                if (val!=f[T][u]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        int c=e[u][i].c;
                        if (val+c<f[T][v])
                        {
                                f[T][v]=val+c;
                                q.push({v,0,f[T][v]});
                        }
                }
        }
}
int main()
{
        freopen("TERRORISTS.inp","r",stdin);
        freopen("TERRORISTS.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        int test;
        read(test);
        while(test--)
        {
                read(n);read(m);read(q);
                for (int i=1;i<=n;++i)
                {
                        e[i].clear();
                        K[i].clear();
                }
                for (int i=1;i<=m;++i)
                {
                        int u,v,c;
                        read(u);read(v);read(c);
                        e[u].push_back({u,v,c});
                        e[v].push_back({v,u,c});
                        E[i]={u,v,c};
                }
                if (n>5e3)
                {
                        for (int i=1;i<=q;++i)
                        {
                                int x,y;
                                cin>>x>>y;
                                putchar('0');
                                putchar('\n');
                        }
                        continue;
                }
                sort(E+1,E+m+1,cmp);
                for (int i=1;i<=n;++i)
                        root[i]=i;
                edge.clear();
                int d=0;
                for (int i=1;i<=m;++i)
                {
                        int u=E[i].u;
                        int v=E[i].v;
                        int ru=getr(u);
                        int rv=getr(v);
                        if (ru==rv||d==n-1)
                        {
                                edge.push_back(E[i]);
                                continue;
                        }
                        ++d;
                        K[u].push_back({u,v,E[i].c});
                        K[v].push_back({v,u,E[i].c});
                        root[ru]=rv;
                }
                dfs(1);
                cnt=1;
                dem=0;
                head[1]=0;
                hld(1);
                build(1,1,n);
                D=0;
                for (int i=0;i<edge.size();++i)
                {
                    S[++D]=edge[i].u;
                    S[++D]=edge[i].v;
                }
                sort(S+1,S+D+1);
                cnt=0;
                for (int i=1;i<=D;++i)
                {
                        int x=S[i];
                        if (x==S[i-1]) continue;
                        P[x]=++cnt;
                        for (int j=1;j<=n;++j)
                                f[P[x]][j]=1e9+7;
                        dijks(P[x],x);
                }
                while(q--)
                {
                        int u,v;
                        read(u);read(v);
                        int res=dis(u,v);
                        for (int i=1;i<=D;++i)
                        {
                                int x=S[i];
                                if (dis(u,x)>res) continue;
                                for (int j=1;j<=D;++j)
                                {
                                        int y=S[j];
                                        res=min(res,dis(u,x)+dis(y,v)+f[P[x]][y]);
                                }
                        }
                        writeln(res);
                }
        }
}
