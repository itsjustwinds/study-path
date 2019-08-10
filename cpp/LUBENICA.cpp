#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int pos[maxn],a[maxn],chain[maxn],head[maxn],high[maxn],cnt,trc[maxn],dem,n,nchild[maxn];
typedef pair<int,int > II;
vector<II > e[maxn];
struct data
{
        int minn,maxx;
};
data st[4*maxn];
data combine(data a,data b)
{
        return {min(a.minn,b.minn),max(a.maxx,b.maxx)};
}
void dfs(int u)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i].fs;
                if (v==trc[u]) continue;
                trc[v]=u;
                dfs(v);
                nchild[u]+=nchild[v];
        }
        nchild[u]++;
}
void hld(int u,int c)
{
        if (!head[cnt]) head[cnt]=u;
        pos[u]=++dem;
        a[dem]=c;
        chain[u]=cnt;
        int vtx=-1;
        int maxx=0;
        int val=0;
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i].fs;
                if (v==trc[u]) continue;
                trc[v]=u;
                if (nchild[v]>maxx)
                {
                        vtx=v;
                        val=e[u][i].sc;
                        maxx=nchild[v];
                }
        }
        if (vtx!=-1 )hld(vtx,val);
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i].fs;
                if (v==trc[u]||v==vtx) continue;
                ++cnt;
                high[cnt]=high[chain[u]]+1;
                hld(v,e[u][i].sc);
        }
}
data get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i||l>r)
        {
                data tmp;
                tmp.minn=1e9;
                tmp.maxx=-1e9;
                return tmp;
        }
        if (l>=i&&r<=j) return st[id];
        int m=(l+r)>>1;
        data tmp1=get(id*2,l,m,i,j);
        data tmp2=get(id*2+1,m+1,r,i,j);
        return combine(tmp1,tmp2);
}
void build(int id,int l,int r)
{
        if (l==r&&l==1)
        {
                st[id].minn=1e9;
                st[id].maxx=-1e9;
                return;
        }
        if (l==r)
        {
                st[id].minn=a[l];
                st[id].maxx=a[l];
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=combine(st[id*2],st[id*2+1]);
}
int lca(int u,int v)
{
        while(chain[u]!=chain[v])
        {
                if (high[chain[u]]>high[chain[v]])
                        u=trc[head[chain[u]]];
                else v=trc[head[chain[v]]];
        }
        if (pos[u]<pos[v]) return u;
        else return v;
}
data go(int u,int w)
{
        data res;
        res.minn=1e9;
        res.maxx=-1e9;
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        data tmp=get(1,1,n,pos[w]+1,pos[u]);
                        res=combine(res,tmp);
                        break;
                }
                data tmp=get(1,1,n,pos[head[cu]],pos[u]);
                res=combine(res,tmp);
                u=trc[head[cu]];
        }
        return res;
}
int main()
{
        freopen("D:\\C++\\LUBENICA.inp","r",stdin);
        //freopen("D:\\C++\\LUBENICA.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2; i<=n; ++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                e[u].push_back(II(v,c));
                e[v].push_back(II(u,c));
        }
        cnt=1;
        dfs(1);
        hld(1,-1);
        build(1,1,n);
        int test;
        cin>>test;
        while(test--)
        {
                int u,v;
                cin>>u>>v;
                if (u==v)
                {
                        cout<<0<<" "<<0<<"\n";
                        continue;
                }
                int w=lca(u,v);
                data tmp1=go(u,w);
                data tmp2=go(v,w);
                data res=combine(tmp1,tmp2);
                cout<<res.minn<<" "<<res.maxx<<"\n";
        }
}
