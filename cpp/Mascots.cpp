#include<bits/stdc++.h>
#define ll long long
#define maxn 3005
#define mod 1000000007
using namespace std;
int gt[maxn*maxn];
int a[maxn][maxn],n,r,c;
int g[maxn][maxn],f[maxn][maxn],C[maxn][maxn],res;
int topx,topy,downx,downy;
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
int cal(int x,int y)
{
        if (x==r&&y==c) return 1;
        if (f[x][y]!=-1) return f[x][y];
        int res=0;
        if (x<r)res+=(1ll*cal(x+1,y)*gt[y])%mod;
        if (y<c)res+=(1ll*cal(x,y+1)*gt[x])%mod;
        f[x][y]=res;
        return res;
}
int main()
{
        freopen("Mascots.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        read(r);
        read(c);
        read(n);
        topx=1e9,topy=1e9;
        for (int i=1; i<=n; ++i)
        {
                int u,v;
                read(u);
                read(v);
                topx=min(topx,u);
                topy=min(topy,v);
                downx=max(downx,u);
                downy=max(downy,v);
                a[u][v]=1;
        }
        for  (int i=1; i<=r; ++i)
                for (int j=1; j<=c; ++j)
                {
                        f[i][j]=-1;
                        g[i][j]=-1;
                }
        gt[0]=1;
        for (int i=1; i<=r*c; ++i)
                gt[i]=(1ll*gt[i-1]*i)%mod;
        for (int i=0;i<=max(r,c);++i)
                C[0][i]=1;
        for(int i=1;i<=max(r,c);++i)
                for (int j=i;j<=max(r,c);++j)
                C[i][j]=(C[i-1][j-1]+C[i][j-1])%mod;
        res=(1ll*cal(downx-topx+1,downy-topy+1)*gt[(downx-topx+1)*(downy-topy+1)-n])%mod;
        res=(1ll*res*C[topx-1][r-(downx-topx+1)])%mod;
        res=(1ll*res*C[topy-1][c-(downy-topy+1)])%mod;
        write(res);
        return 0;
}
