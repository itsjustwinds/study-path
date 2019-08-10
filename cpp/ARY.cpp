#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m,a[maxn][maxn],b[maxn][maxn],le[maxn],ri[maxn],h[maxn];
int f[maxn][maxn];
deque<int >s;
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
bool check(int i,int j)
{
        int ok=1;
        if (a[i-1][j]-a[i][j]!=a[i][j]-a[i+1][j]) ok=0;
        if (a[i-1][j-1]-a[i][j-1]!=a[i][j-1]-a[i+1][j-1]) ok=0;
        if (a[i-1][j+1]-a[i][j+1]!=a[i][j+1]-a[i+1][j+1]) ok=0;
        if (a[i][j-1]-a[i][j]!=a[i][j]-a[i][j+1]) ok=0;
        if (a[i-1][j-1]-a[i-1][j]!=a[i-1][j]-a[i-1][j+1]) ok=0;
        if (a[i+1][j-1]-a[i+1][j]!=a[i+1][j]-a[i+1][j+1]) ok=0;
        return ok;
}
void solve()
{
        read(n);
        read(m);
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        read(a[i][j]);
        for (int i=2; i<n; ++i)
                for (int j=2; j<m; ++j)
                        if (check(i,j)) b[i][j]=1;
                        else b[i][j]=0;
        int res=0;
        for (int i=1; i<=n; ++i)
        {
                int d=2;
                for (int j=3; j<=m; ++j)
                {
                        if (a[i][j-2]-a[i][j-1]==a[i][j-1]-a[i][j]) ++d;
                        else d=2;
                        res=max(res,d);
                        f[i][j]=d;
                }
        }
        for (int i=1;i<n;++i)
        {
                for (int j=3;j<=m;++j)
                {
                        int t=min(f[i][j],f[i+1][j]);
                        res=max(res,2*t);
                }
        }
        for (int j=1; j<=m; ++j)
        {
                int d=2;
                for (int i=3; i<=n; ++i)
                {
                        if (a[i-2][j]-a[i-1][j]==a[i-1][j]-a[i][j]) ++d;
                        else d=2;
                        res=max(res,d);
                        f[i][j]=d;
                }
        }
        for (int j=1;j<m;++j)
        {
                for (int i=3;i<=n;++i)
                {
                        int t=min(f[i][j],f[i][j+1]);
                        res=max(res,2*t);
                }
        }
        for (int i=2;i<n;++i)
        {
                for (int j=2;j<m;++j)
                        h[j]=(h[j]+1)*b[i][j];
                while(!s.empty()) s.pop_back();
                s.push_back(1);
                for (int j=2;j<m;++j)
                {
                        while(s.size()>1&&h[s.back()]>=h[j]) s.pop_back();
                        le[j]=s.back()+1;
                        s.push_back(j);
                }
                while(!s.empty()) s.pop_back();
                s.push_back(m);
                for (int j=m-1;j>1;--j)
                {
                        while(s.size()>1&&h[s.back()]>=h[j]) s.pop_back();
                        ri[j]=s.back()-1;
                        s.push_back(j);
                }
                for (int j=2;j<m;++j)
                {
                        if (!h[j]) continue;
                        res=max(res,(h[j]+2)*(ri[j]-le[j]+3));
                }
        }
        writeln(res);
}
int main()
{
        freopen("ARY.inp","r",stdin);
        freopen("ARY.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        int test;
        read(test);
        while(test--)
                solve();
        return 0;
}
