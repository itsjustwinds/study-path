#include<bits/stdc++.h>
#define maxn 10005
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
typedef pair<int,int > II;
map<II,int > M,c;
int n,m;
vector<int > e[maxn];
int main()
{
        freopen("TRAVEL.inp","r",stdin);
        freopen("TRAVEL.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);read(m);
        for (int i=1;i<=m;++i)
        {
                int u,v;
                read(u);read(v);
                if (u>v) swap(u,v);
                II tmp=II(u,v);
                if (c[tmp]!=0) continue;
                c[tmp]=1;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        for (int k=1;k<=n;++k)
        {
                sort(e[k].begin(),e[k].end());
                for (int i=0;i<e[k].size();++i)
                        for (int j=i+1;j<e[k].size();++j)
                {
                        int u=e[k][i];
                        int v=e[k][j];
                        if (u>v) swap(u,v);
                        II tmp=II(u,v);
                        if (M[tmp])
                        {
                                write(M[tmp]);putchar(' ');
                                write(u);putchar(' ');
                                write(k);putchar(' ');
                                write(v);
                                return 0;
                        }
                        M[tmp]=k;
                }
        }
        printf("-1");
}
