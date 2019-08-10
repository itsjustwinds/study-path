#include<bits/stdc++.h>
#define maxn 1000005
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
struct data
{
        int u,v,id,c;
};
int root[maxn];
int getr(int u)
{
        if (root[u]==u) return u;
        root[u]=getr(root[u]);
        return root[u];
}
data edge[maxn],nw[maxn],now[105],pos[maxn];
int n,m,q,dd[maxn];
bool cmp(const data &a,const data &b)
{
        return a.c<b.c;
}
void solve()
{
        //cin>>n>>m>>q;
        read(n);read(m);read(q);
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                //cin>>u>>v>>c;
                read(u);read(v);read(c);
                edge[i]={u,v,i,c};
                pos[i]={u,v,i,c};
        }
        sort(edge+1,edge+m+1,cmp);
        while(q--)
        {
                int id,s;
                //cin>>id>>s;
                read(id);read(s);
                for (int i=1;i<=m;++i)
                        dd[i]=0;
                for (int i=1;i<=s;++i)
                {
                        int j,c;
                        read(j);read(c);
                        now[i]=pos[j];
                        now[i].c=c;
                        dd[j]=1;
                }
                sort(now+1,now+s+1,cmp);
                int N=1;
                int d=0;
                int V=0;
                for (int i=1;i<=m;++i)
                {
                        if (dd[edge[i].id]) continue;
                        while(N<=s&&now[N].c<=edge[i].c)
                        {
                                nw[++d]=now[N];
                                if (nw[d].id==id) V=nw[d].c;
                                ++N;
                        }
                        nw[++d]=edge[i];
                        if (nw[d].id==id) V=nw[d].c;
                }
                while(N<=s)
                {
                        nw[++d]=now[N++];
                        if (nw[d].id==id) V=nw[d].c;
                }
                ll S=0;
                for (int i=1;i<=n;++i)
                        root[i]=i;
                d=0;
                for (int i=1;i<=m;++i)
                {
                        int u=nw[i].u;
                        int v=nw[i].v;
                        int val=nw[i].c;
                        int ru=getr(u);
                        int rv=getr(v);
                        if (ru==rv) continue;
                        root[ru]=rv;
                        S+=val;
                        ++d;
                        if (d==n-1) break;
                }
                ll sum=0;
                for (int i=1;i<=n;++i)
                        root[i]=i;
                d=1;
                root[pos[id].u]=pos[id].v;
                sum+=V;
                for (int i=1;i<=m;++i)
                {
                        int u=nw[i].u;
                        int v=nw[i].v;
                        int val=nw[i].c;
                        int ru=getr(u);
                        int rv=getr(v);
                        if (ru==rv||nw[i].id==id) continue;
                        root[ru]=rv;
                        sum+=val;
                        ++d;
                        if (d==n-1) break;
                }
                if (d==n-1&&sum==S)
                {
                        printf("NO\n");
                }
                else printf("YES\n");
        }
}
int main()
{
        freopen("COMNET.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        int test;
        read(test);
        while(test--)
        {
                solve();
        }
}
