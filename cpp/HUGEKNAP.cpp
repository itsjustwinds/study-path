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
int f[1005],n,m,trc[maxn][1005],w[maxn],val[maxn],maxval,maxnum;
vector<int > res;
void solve()
{
        read(n);
        read(m);
        memset(f,0,sizeof f);
        memset(trc,0,sizeof trc);
        maxval=0;
        maxnum=0;
        for (int i=1;i<=n;++i) read(w[i]);
        for (int i=1;i<=n;++i) read(val[i]);
        for (int i=1;i<=n;++i)
        {
               for (int j=m-w[i];j>=0;--j)
               {
                       int k=j+w[i];
                       if (f[j]+val[i]>f[k])
                       {
                               f[k]=f[j]+val[i];
                               trc[i][k]=i;
                       }
                       if (f[k]>maxval)
                       {
                               maxval=f[k];
                               maxnum=k;
                       }
               }
        }
        write(maxval);putchar(' ');
        res.clear();
        int i=n;
        while(i&&maxnum)
        {
                int t=trc[i][maxnum];
                if (t)
                {res.push_back(t);
                maxnum-=w[t];
                }
                --i;
        }
        write(res.size());putchar('\n');
        for (int i=0;i<res.size();++i)
        {
                write(res[i]);putchar(' ');
        }
}
int main()
{
        freopen("D:\\c++\\HUGEKNAP.inp","r",stdin);
        freopen("D:\\c++\\HUGEKNAP.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        int test;
        read(test);
        while(test--)
        {
                solve();
        }
}
