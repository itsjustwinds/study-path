#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        int u,v;
        ll w;
};
ll n,p,root[maxn],a[maxn];
ll res;
data e[maxn];
bool cmp(data a,data b)
{
        return a.w<b.w;
}
int get(int u)
{
        if (root[u]==u) return u;
        root[u]=get(root[u]);
        return root[u];
}
int main()
{
        freopen("CHEER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>p;
        res=10000;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i];
                res=min(res,a[i]);
        }
        for (int i=1;i<=p;i++)
        {
                int u,v,w;
                cin>>u>>v>>w;
                e[i].u=u;
                e[i].v=v;
                e[i].w=2*w+a[u]+a[v];
        }
        sort(e+1,e+p+1,cmp);
        for (int i=1;i<=n;i++)
        {
                root[i]=i;
        }
        int dem=0;
        for (int i=1;i<=p;i++)
        {
                if (dem==n-1) break;
                int u=e[i].u;
                int v=e[i].v;
                int ru=get(u);
                int rv=get(v);
                if (ru==rv) continue;
                root[ru]=rv;
                res+=e[i].w;
                dem++;
        }
        cout<<res;
        return 0;
}
