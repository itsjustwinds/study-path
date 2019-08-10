#include<bits/stdc++.h>
#define maxn 2005
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define M 501000
#define N 2020
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);
#define bit(S, i) ((S >> i) & 1)
using namespace std;
int n,r1,r2;
bitset<500005> a[maxn],b[maxn];
vector<int > e1[maxn],e2[maxn];
bitset<500005> c;
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
void dfs1(int u)
{
        for (int i=0; i<e1[u].size(); ++i)
        {
                int v=e1[u][i];
                a[v]|=a[u];
                dfs1(v);
        }
}
void dfs2(int u)
{
        for (int i=0; i<e2[u].size(); ++i)
        {
                int v=e2[u][i];
                b[v]|=b[u];
                dfs2(v);
        }
}
int p,q,u,v;
int main()
{
        freopen("SPY.inp","r",stdin);
        IO;
        int test;
        read(n);
        read(test);
        //cin>>n>>test;
        FOR(i, 1, n)
        {
                read(p);
                read(q);
                if (p) e1[p].push_back(i);
                else r1=i;
                if (q) e2[q].push_back(i);
                else r2=i;
        }
        REP(i, test)
        {
                read(u);
                read(v);
                a[u].set(i);
                b[v].set(i);
        }
        dfs1(r1);
        dfs2(r2);
        for (int i=1; i<=n; ++i)
        {
                c=a[i]&b[i];
                writeln(c.count());
        }
        return 0;
}
