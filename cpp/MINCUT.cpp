#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
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
ll sum[maxn][maxn],res;
int n,m,a[maxn][maxn];
ll tinh(int x1,int y1,int x2,int y2)
{
        return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
        freopen("MINCUT.inp","r",stdin);
        freopen("MINCUT.out","w",stdout);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        //cin>>n>>m>>test;
        read(n);read(m);read(test);
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
        {
                //cin>>a[i][j];
                read(a[i][j]);
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
        while(test--)
        {
                int x,y,u,v;
                res=1e18;
                //cin>>x>>y>>u>>v;
                read(x);read(y);read(u);read(v);
                int l=y,r=v-1;
                while(l<=r)
                {
                        int m=(l+r)>>1;
                        ll TMP=tinh(x,y,u,m)-tinh(x,m+1,u,v);
                        if (TMP>0)
                        {
                                res=min(res,TMP);
                                r=m-1;
                        }
                        else
                        {
                                res=min(res,-TMP);
                                l=m+1;
                        }
                }
                l=x,r=u-1;
                while(l<=r)
                {
                        int m=(l+r)>>1;
                        ll TMP=tinh(x,y,m,v)-tinh(m+1,y,u,v);
                        if (TMP>0)
                        {
                                res=min(res,TMP);
                                r=m-1;
                        }
                        else
                        {
                                res=min(res,-TMP);
                                l=m+1;
                        }
                }
                cout<<res<<"\n";
        }
}
