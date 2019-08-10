#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
long long res;
int root[maxn],val[maxn],n,m,dd[maxn];
int get(int u)
{
        if (root[u]==u) return u;
        root[u]=get(root[u]);
        return root[u];
}
int main()
{
        //freopen("893C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>val[i];
        for (int i=1;i<=n;++i)
                root[i]=i;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                int ru=get(u);
                int rv=get(v);
                if (ru==rv) continue;
                root[ru]=rv;
                val[rv]=min(val[rv],val[ru]);
        }
        for (int i=1;i<=n;++i)
        {
                int r=get(i);
                if (dd[r]) continue;
                dd[r]=1;
                res+=val[r];
        }
        cout<<res;
}
