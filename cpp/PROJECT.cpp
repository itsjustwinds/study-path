#include<bits/stdc++.h>
#define db double
#define maxn 10005
using namespace std;
struct data
{
        int u,v,l,c,id;
        db val;
};
vector<data >edge;
int n,m,root[maxn];
vector<int > res;
bool cmp(data a,data b)
{
        return a.val<b.val;
}
int getr(int u)
{
        if (root[u]==u) return u;
        root[u]=getr(root[u]);
        return root[u];
}
bool check(db k)
{
        for (int i=1;i<=n;++i)
                root[i]=i;
        for (int i=0;i<edge.size();++i)
                edge[i].val=(db)edge[i].c-(db)edge[i].l*k;
        sort(edge.begin(),edge.end(),cmp);
        vector<int >tmp;
        tmp.clear();
        int d=0;
        db sum=0;
        for (int i=0;i<edge.size();++i)
        {
                int u=edge[i].u;
                int v=edge[i].v;
                int ru=getr(u);
                int rv=getr(v);
                if (ru==rv) continue;
                ++d;
                tmp.push_back(edge[i].id);
                root[ru]=rv;
                if (d==n-1) break;
        }
        if (d==n-1&&sum<=0)
        {
                res=tmp;
                return 1;
        }
        return 0;
}
int main()
{
        freopen("PROJECT.inp","r",stdin);
        freopen("PROJECT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v,l,c;
                cin>>u>>v>>l>>c;
                edge.push_back({u,v,l,c,i,0});
        }
        db l=0,r=1e8;
        db esp=1e-4;
        while(r-l>esp)
        {
                db m=(l+r)/2;
                if (check(m))
                {
                        r=m;
                }
                else l=m;
        }
        for (int i=0;i<res.size();++i)
                cout<<res[i]<<" ";
        return 0;
}
