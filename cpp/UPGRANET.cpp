#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
struct data
{
        int u,v,w;
};
int n,m,cnt,chain[maxn],head[maxn],pos[maxn],h[maxn],base[maxn],trc[maxn],dem,val[maxn],root[maxn],st[4*maxn];
data c[maxn];
long long res;
int dd[maxn],kq;
bool cmp(data a,data b)
{
        return a.w>b.w;
}
typedef pair<int,int> II;
vector<II> e[maxn];
int getr(int u)
{
        if (root[u]==u) return u;
        root[u]=getr(root[u]);
        return root[u];
}
void hld(int u)
{
        if (head[cnt]==0) head[cnt]=u;
        chain[u]=cnt;
        pos[u]=++dem;
        base[dem]=u;
        int vtx=-1;
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i].fs;
                if (v==trc[u]) continue;
                trc[v]=u;
                val[v]=e[u][i].sc;
                if (vtx==-1) vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i].fs;
                if (v==vtx||v==trc[u]) continue;
                cnt++;
                h[cnt]=h[chain[u]]+1;
                hld(v);
        }
}
int lca(int u,int v)
{
        while(1)
        {
                int cu=chain[u];
                int cv=chain[v];
                if (cu==cv) break;
                if (h[cu]>h[cv]) u=trc[head[cu]];
                else v=trc[head[cv]];
        }
        if (pos[u]>pos[v]) return v;
        else return u;
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=val[base[l]];
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 10000000;
        if (l>=i&&r<=j) return st[id];
        int m=(l+r)>>1;
        return min(get(id*2,l,m,i,j),get(id*2+1,m+1,r,i,j));
}
void getmin(int u,int w)
{
        while(1)
        {
                int cu=chain[u];
                int cw=chain[w];
                if (cu==cw)
                {
                        kq=min(kq,get(1,1,dem,pos[w]+1,pos[u]));
                        return;
                }
                kq=min(kq,get(1,1,dem,pos[head[cu]],pos[u]));
                u=trc[head[cu]];
        }
}
int main()
{
        freopen("UPGRANET.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                cin>>c[i].u>>c[i].v>>c[i].w;
        }
        sort(c+1,c+m+1,cmp);
        dem=0;
        cnt=1;
        for (int i=1;i<=n;i++)
                root[i]=i;
        for (int i=1;i<=m;++i)
        {
                int u=c[i].u;
                int v=c[i].v;
                int ru=getr(u);
                int rv=getr(v);
                if (ru==rv) continue;
                ++dem;
                dd[i]=1;
                root[ru]=rv;
                e[u].push_back(II(v,c[i].w));
                e[v].push_back(II(u,c[i].w));
                //cout<<u<<" "<<v<<"\n";
                if (dem==n-1) break;
        }
        dem=0;
        hld(1);
        build(1,1,dem);
        for (int i=1;i<=m;i++)
        if (!dd[i])
        {
                int u=c[i].u;
                int v=c[i].v;
                int w=lca(u,v);
                kq=10000000;
                getmin(u,w);
                getmin(v,w);
                res+=(kq-c[i].w);
        }
        cout<<res;
        return 0;
}
