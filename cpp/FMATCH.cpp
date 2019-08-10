#include<bits/stdc++.h>
#define maxn 50005
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
int n,m,d[2*maxn],res,match[2*maxn],nil;
vector<int > e[2*maxn];
bool bfs()
{
        queue<int > q;
        while(!q.empty()) q.pop();
        for (int i=1;i<=n;++i)
        if (match[i]==nil)
        {
                d[i]=0;
                q.push(i);
        }
        else d[i]=1e9;
        d[nil]=1e9;
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (d[match[v]]!=1e9) continue;
                        d[match[v]]=d[u]+1;
                        q.push(match[v]);
                }
        }
        return d[nil]!=1e9;
}
bool dfs(int u)
{
        if (u==nil) return 1;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (d[match[v]]!=d[u]+1) continue;
                int x=dfs(match[v]);
                if (x)
                {
                        match[u]=v;
                        match[v]=u;
                        return 1;
                }
        }
        return 0;
}
int main()
{
        freopen("FMATCH.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        read(n);
        read(m);
        int k;
        read(k);
        for (int i=1;i<=k;++i)
        {
                int u,v;
                read(u);
                read(v);
                v+=n;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        while(bfs())
        {
                for (int i=1;i<=n;++i)
                if (match[i]==nil&&dfs(i)) ++res;
        }
        //for (int i=1;i<=n;++i)
        //if (match[i]) cout<<i<<" "<<match[i]<<"\n";
        write(res);
}
