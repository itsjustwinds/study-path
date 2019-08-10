#include<bits/stdc++.h>
#define maxn 100005
#define ll unsigned long long
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
int n,m,c,num[maxn],low[maxn],d,cnt,dem[maxn],Nchild[maxn];
ll res;
vector<int > e[maxn],Brige;
void dfs(int u,int trc)
{
        dem[d]++;
        num[u]=low[u]=++cnt;
        Nchild[u]=1;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                if (num[v])
                {
                        low[u]=min(low[u],num[v]);
                }
                else
                {
                        dfs(v,u);
                        Nchild[u]+=Nchild[v];
                        low[u]=min(low[u],low[v]);
                        if (low[v]>num[u])
                        {
                                ++c;
                                Brige.push_back(v);
                        }
                }
        }
}
int main()
{
        freopen("REFORM.inp","r",stdin);
        freopen("REFORM.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        read(n);read(m);
        for (int i=1;i<=m;++i)
        {
                int u,v;
                read(u);read(v);
                e[u].push_back(v);
                e[v].push_back(u);
        }
        for (int i=1;i<=n;++i)
        if (!num[i])
        {
                ++d;
                dfs(i,-1);
        }
        if (d>=3)
        {
                cout<<0;
                return 0;
        }
        if (d==1)
        {
                res=1ll*(m-c)*(1ll*n*(n-1)/2-m);
                for (int i=0;i<Brige.size();++i)
                {
                        int v=Brige[i];
                        res+=1ll*Nchild[v]*(n-Nchild[v])-1;
                }

        }
        else
        {
             res=1ll*(m-c)*dem[1]*dem[2];
        }
        cout<<res;
        return 0;
}
