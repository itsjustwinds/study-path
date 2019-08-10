#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll res;
struct data
{
        int u,v,c;
};
data e[maxn];
int root[maxn],n,m;
bool cmp(const data &a,const data &b)
{
        return a.c>b.c;
}
int getroot(int u)
{
        if (root[u]==u) return u;
        root[u]=getroot(root[u]);
        return root[u];
}
int main()
{
        freopen("NKRACING.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                cin>>e[i].u>>e[i].v>>e[i].c;
                res+=e[i].c;
        }
        sort(e+1,e+m+1,cmp);
        for (int i=1;i<=n;++i)
                root[i]=i;
        int d=0;
        for (int i=1;i<=m;++i)
        {
                int u=e[i].u;
                int v=e[i].v;
                int ru=getroot(u);
                int rv=getroot(v);
                if (ru==rv) continue;
                root[ru]=rv;
                res-=e[i].c;
                ++d;
                if (d==n-1) break;
        }
        cout<<res;
        return 0;
}
