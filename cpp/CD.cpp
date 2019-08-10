#include<bits/stdc++.h>
#define maxn 205
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
int n,w,f[20005],trc[20005],dd[maxn],D[maxn],res,ans[maxn],W;
struct data
{
        int val,id;
};
data a[maxn];
bool cmp(data a,data b)
{
        return a.val<b.val;
}
void sub1()
{
        for (int i=1;i<=w;++i)
                f[i]=-1e9;
        f[0]=0;
        for (int i=1;i<=n;++i)
        {
                for (int j=w-a[i].val;j>=0;--j)
                {
                        if (f[j]==-1e9)  continue;
                        if (f[j]+1>f[j+a[i].val])
                        {
                                f[j+a[i].val]=f[j]+1;
                                trc[j+a[i].val]=i;
                        }
                }
        }
        int X=0,maxx=0;
        for (int i=w;i>=0;--i)
        if (f[i]>maxx)
        {
                maxx=f[i];
                X=i;
        }
        while(X)
        {
                int i=trc[X];
                dd[a[i].id]=1;
                X-=a[i].val;
        }
        for (int i=1;i<=n;++i)
        {
                int id=a[i].id;
                if (dd[id]) continue;
                if (w-a[i].val>=0)
                {
                        dd[id]=2;
                        w-=a[i].val;
                }
                else break;
        }
        //for (int i=1;i<=n;++i)
        //        cout<<dd[i]<<" ";
        for (int i=1;i<=n;++i)
        {
                write(dd[i]);
                putchar(' ');
                //cout<<ans[i]<<" ";
        }
}
void dfs(int i,int w)
{
        if (i==n+1)
        {
                int S=W;
                for (int i=1;i<=n;++i)
                if (D[i]==0)
                {
                        if (S-a[i].val>=0)
                        {
                                D[i]=2;
                                S-=a[i].val;
                        }
                        else break;
                }
                int dem=0;
                for (int i=1;i<=n;++i)
                if (D[i]!=0) ++dem;
                if (dem>res)
                {
                        res=dem;
                        for (int i=1;i<=n;++i)
                                dd[i]=D[i];
                }
                for (int i=1;i<=n;++i)
                if (D[i]==2) D[i]=0;
                return;
        }
        dfs(i+1,w);
        D[i]=1;
        if (w-a[i].val>=0)dfs(i+1,w-a[i].val);
        D[i]=0;
}
void sub2()
{
        dfs(1,w);
        for (int i=1;i<=n;++i)
                ans[a[i].id]=dd[i];
        for (int i=1;i<=n;++i)
        {
                write(ans[i]);
                putchar(' ');
                //cout<<ans[i]<<" ";
        }
}
int main()
{
        freopen("CD.inp","r",stdin);
        freopen("CD.out","w",stdout);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>w;
        W=w;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].val;
                a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        if (w<=20000) sub1();
        else
                sub2();
}
