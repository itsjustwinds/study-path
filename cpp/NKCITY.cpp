#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
            int u,v,w;
};
data c[maxn];
int n,m,res,root[maxn];
bool cmp(data a,data b)
{
            return a.w<b.w;
}
int getr(int u)
{
            if (root[u]==u) return u;
            root[u]=getr(root[u]);
            return root[u];
}
int main()
{
            freopen("NKCITY.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            for (int i=1; i<=m; ++i)
            {
                        cin>>c[i].u>>c[i].v>>c[i].w;
            }
            sort(c+1,c+m+1,cmp);
            int dem=0;
            for (int i=1; i<=n; ++i) root[i]=i;
            for (int i=1; i<=m; ++i)
            {
                        int u=c[i].u;
                        int v=c[i].v;
                        int ru=getr(u);
                        int rv=getr(v);
                        if (ru==rv) continue;
                        root[ru]=rv;
                        ++dem;
                        res=max(res,c[i].w);
                        if (dem==n-1) break;
            }
            cout<<res;
            return 0;
}
