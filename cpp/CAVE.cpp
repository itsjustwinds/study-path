#include<bits/stdc++.h>
#define fs first
#define sc second
#define maxn 3000005
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

int n,p[maxn][30],pa[maxn],R,high[maxn];
vector<int > res,e[maxn],uc;
typedef pair<int,int > II;

void dfs(int u)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==pa[u]) continue;
                pa[v]=u;
                high[v]=high[u]+1;
                dfs(v);
        }
}
int lca(int u,int v)
{
        if (high[u]<high[v]) swap(u,v);
        int log=log2(high[u]);
        for (int i=log;i>=0;--i)
        if (high[u]-(1<<i)>=high[v]) u=p[u][i];
        if (u==v) return u;
        for (int i=log;i>=0;--i)
        if (p[u][i]!=-1&&p[v][i]!=-1&&p[u][i]!=p[v][i])
        {
                u=p[u][i];
                v=p[v][i];
        }
        return pa[u];
}
int s[maxn],l,r,d,m,inq[maxn],dd[maxn];
void bfs()
{
        int maxx=0;
        queue<II >q;
        q.push(II(1,0));
        dd[1]=1;
        while(!q.empty())
        {
                int u=q.front().fs;
                int num=q.front().sc;
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (dd[v]) continue;
                        dd[v]=1;
                        q.push(II(v,num+1));
                        if (num+1>maxx)
                        {
                                maxx=num+1;
                                R=v;
                        }
                }
        }
}
void DFS(int u)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==pa[u]) continue;
                DFS(v);
        }
        inq[u]=1;
        s[++r]=u;
        if (r-l+1>=m)
        {
                int v=s[r-m+1];
                int w=lca(u,v);
                if (inq[w])
                {
                        int T=r-m+1;
                        for (int i=r;i>=T;--i)
                        if (s[i]!=w&&inq[pa[s[i]]]==0) return;
                        while(r>=T)
                        {
                                inq[s[r]]=0;
                                --r;
                        }
                        d-=m;
                }
        }
}
bool check()
{
        inq[0]=1;
        for (int i=1;i<=n;++i)
                inq[i]=0;
        l=1,r=0;
        d=n;
        DFS(R);
        return d==0;
}
int main()
{
        freopen("CAVE.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=2;i<=n;++i)
        {
                int x;
                read(x);
                e[x].push_back(i);
                e[i].push_back(x);
        }
        for (int i=2;i*i<=n;++i)
        if (n%i==0)
        {
                uc.push_back(i);
                uc.push_back(n/i);
        }
        res.push_back(1);
        res.push_back(n);
        bfs();
        dfs(R);
        for (int j=1;(1<<j)<=n;++j)
                for (int i=1;i<=n;++i)
                        p[i][j]=-1;
        for (int i=1;i<=n;++i)
                p[i][0]=pa[i];
        for (int j=1;(1<<j)<=n;++j)
                for (int i=1;i<=n;++i)
        {
                if (p[i][j-1]==-1) continue;
                p[i][j]=p[p[i][j-1]][j-1];
        }
        for (int i=0;i<uc.size();++i)
        {
                int x=uc[i];
                m=x;
                if (check()) res.push_back(n/x);
        }
        sort(res.begin(),res.end());
        for (int i=0;i<res.size();++i)
                cout<<res[i]<<" ";
}
