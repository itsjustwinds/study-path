#include<bits/stdc++.h>
#define maxn 100005
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
int w[maxn],n,a[maxn],b[maxn],pre[maxn],TMP[maxn],dd[maxn];
vector<int > E[maxn],e[maxn];
long long res;
void DFS(int u,int trc)
{
        for (int i=0;i<E[u].size();++i)
        {
                int v=E[u][i];
                if (v==trc) continue;
                pre[v]=u;
                e[u].push_back(v);
                DFS(v,u);
        }
}
void dfs(int u,int sum)
{
        if (e[u].size()==0)
        {
                if (b[u]>=a[u]) w[u]=sum-1;
                else w[u]=sum+1;
                return;
        }
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                int k;
                if (b[u]>=a[u]) k=-1;
                else k=1;
                dfs(v,sum+k);
        }
}
int get()
{
        dfs(1,0);
        w[0]=-1e9;
        int res=0;
        for (int i=1;i<=n;++i)
                if (dd[i]==0&&e[i].size()==0&&w[i]>w[res]) res=i;
        dd[res]=1;
        return res;
}
int main()
{
        freopen("TREE.inp","r",stdin);
        freopen("TREE.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=1;i<=n;++i)
        {
                read(a[i]);
                TMP[i]=a[i];
        }
        for (int i=2;i<=n;++i)
        {
                int u,v;
                read(u);
                read(v);
                E[u].push_back(v);
                E[v].push_back(u);
        }
        DFS(1,-1);
        while(int x=get())
        {
                if (x<=0) break;
                if (w[x]<=0) break;
                int u=x;
                b[u]++;
                while(u!=1)
                {
                        int v=pre[u];
                        b[v]++;
                        u=v;
                }
        }
        for (int i=1;i<=n;++i)
                res+=abs(a[i]-b[i]);
        write(res);
        return 0;
}
