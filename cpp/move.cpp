#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define sc second
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
int n,c[maxn],t[maxn];
typedef pair<int,int > II;
int res;
II a[maxn];
struct cmp
{
        bool operator ()(II a,II b)
        {
                if (a.sc!=b.sc)return a.sc>b.sc;
                return a.fs>b.fs;
        }
};
bool check(int m)
{
        priority_queue<II,vector<II>,cmp > q;
        for (int i=1; i<=n; ++i)
        {
                int T=m/t[i];
                int x=max(1,c[i]-T);
                int y=min(n,c[i]+T);
                q.push(II(x,y));
        }
        for (int i=1; i<=n; ++i)
        {
                vector<II > e;
                e.clear();
                while(1)
                {
                        if (q.empty()) return 0;
                        II tmp=q.top();
                        q.pop();
                        if (tmp.fs<=i&&tmp.sc>=i)
                        {
                                for (int j=0; j<e.size(); ++j)
                                        q.push(e[j]);
                                break;
                        }
                        e.push_back(tmp);
                }
        }
        return 1;
}
int main()
{
        freopen("MOVE.inp","r",stdin);
        freopen("MOVE.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=1; i<=n; ++i)
        {
                read(c[i]);
                read(t[i]);
        }
        int l=1,r=1e9;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        res=m;
                        r=m-1;
                }
                else l=m+1;
        }
        write(res);
}
