#include<bits/stdc++.h>
#define maxn 500005
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
int n,dd[maxn],now;
long long res;
struct data
{
        int a,b,pos;
};
vector<data >ans;
data a[maxn];
bool cmp(data a,data b)
{
        return a.a<b.a;
}
typedef pair<int,int > II;
struct cmpx
{
        bool operator ()(II a,II b)
        {
                return a.fs<b.fs;
        }
};
stack<int > s;
priority_queue<II,vector<II>,cmpx > q;
int main()
{
        freopen("DIVIDE.inp","r",stdin);
        freopen("DIVIDE.out","w",stdout);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //cin>>n;
        read(n);
        for (int i=1;i<=n;++i)
                read(a[i].a);
        for (int i=1;i<=n;++i)
        {
                read(a[i].b);
                a[i].pos=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                q.push(II(a[i].b,i));
                if (i%2)
                {
                        int pos=q.top().sc;
                        int x=q.top().fs;
                        q.pop();
                        res+=x;
                        dd[pos]=1;
                        s.push(pos);
                }
        }
        cout<<res<<"\n";
        for (int i=n;i>=1;--i)
        if (!dd[i])
        {
                cout<<a[i].pos<<" "<<a[s.top()].pos<<"\n";
                s.pop();
        }
}

