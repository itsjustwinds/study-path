#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
int h[maxn][maxn],d[maxn][maxn],n,m,dx[5],dy[5];
ll res;
bool check(int i,int j)
{
        return (i>=1&&i<=n&&j>=1&&j<=m);
}
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
struct data
{
        int x,y,c;
};
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.c>b.c;
        }
};
void dijks()
{
        priority_queue<data,vector<data>,cmp > q;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                d[i][j]=1e9;
        for (int i=1;i<=n;++i)
        {
                d[i][1]=h[i][1];
                d[i][m]=h[i][m];
                q.push({i,1,d[i][1]});
                q.push({i,m,d[i][m]});
        }
        for (int j=2;j<m;++j)
        {
                d[1][j]=h[1][j];
                d[n][j]=h[n][j];
                q.push({1,j,d[1][j]});
                q.push({n,j,d[n][j]});
        }
        while(!q.empty())
        {
                int x=q.top().x;
                int y=q.top().y;
                int c=q.top().c;
                q.pop();
                if (c!=d[x][y]) continue;
                for (int i=1;i<=4;++i)
                {
                        int u=x+dx[i];
                        int v=y+dy[i];
                        if (!check(u,v)) continue;
                        if (max(c,h[u][v])<d[u][v])
                        {
                                d[u][v]=max(c,h[u][v]);
                                q.push({u,v,d[u][v]});
                        }
                }
        }
}
int main()
{
        freopen("WATER.inp","r",stdin);
        freopen("WATER.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        dx[1]=-1;dy[1]=0;
        dx[2]=0;dy[2]=1;
        dx[3]=1;dy[3]=0;
        dx[4]=0;dy[4]=-1;
        read(n);read(m);
        for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
                read(h[i][j]);
        dijks();
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                res+=max(0,d[i][j]-h[i][j]);
        write(res);
}
