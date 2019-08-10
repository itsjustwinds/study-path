#include<bits/stdc++.h>
#define maxn 100005
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
struct ps
{
        ll x,y;
};
struct data
{
        ll t;
        ps val;
};
ll n,res,l;
ps f[maxn];
data a[maxn];
ps tinh(ps a,ll b)
{
        a.x+=a.y*b;
        ll k=__gcd(a.x,a.y);
        a.x/=k;
        a.y/=k;
        return a;
}
bool operator <=(ps a,ps b)
{
        a.x*=b.y;
        b.x*=a.y;
        return a.x<=b.x;
}
bool cmp(data a,data b)
{
        return a.t<b.t;
}
int findd(int l,int r,ps x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (x<=f[m])
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        return res;
}
int main()
{
        freopen("WALKING.inp","r",stdin);
        freopen("WALKING.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(l);
        read(n);
        for (int i=1;i<=n;++i)
        {
                read(a[i].t);
                ll v;
                read(v);
                a[i].val=tinh({l,v},a[i].t);
        }
        sort(a+1,a+n+1,cmp);
        f[1]=a[1].val;
        res=1;
        for (int i=2;i<=n;++i)
        {
                ps x=a[i].val;
                int k=findd(1,res,x);
                if (k==res) ++res;
                f[k+1]=x;
        }
        cout<<res;
        return 0;
}
