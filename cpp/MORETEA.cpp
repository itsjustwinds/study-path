#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
struct data
{
        int minn,d;
        ll val,lazy;
};
data st[4*maxn];
int n,a[maxn],M,Nchild[maxn],cnt,chain[maxn],pos[maxn],P[maxn],head[maxn],d;
int h[maxn],pre[maxn],high[maxn];
vector<int > e[maxn];
void dfs(int u,int trc)
{
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                pre[v]=u;
                high[v]=high[u]+1;
                dfs(v,u);
                Nchild[u]+=Nchild[v];
        }
        Nchild[u]++;
}
void hld(int u,int trc)
{
        if (head[cnt]==0) head[cnt]=u;
        P[++d]=u;
        pos[u]=d;
        chain[u]=cnt;
        int vtx=-1;
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i];
                if (v==trc) continue;
                if (vtx==-1||Nchild[v]>Nchild[vtx])
                        vtx=v;
        }
        if (vtx!=-1)  hld(vtx,u);
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i];
                if (v==trc||v==vtx) continue;
                ++cnt;
                h[cnt]=h[chain[u]]+1;
                hld(v,u);
        }
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]= {a[P[l]],1,a[P[l]],0};
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
        st[id].val=st[id*2].val+st[id*2+1].val;
        st[id].d=st[id*2].d+st[id*2+1].d;
        st[id].lazy=0;
}
int lca(int u,int v)
{
        while(1)
        {
                if (chain[u]==chain[v])
                {
                        int tmp=min(pos[u],pos[v]);
                        return P[tmp];
                }
                if (h[chain[u]]>h[chain[v]])
                {
                        u=pre[head[chain[u]]];
                }
                else
                {
                        v=pre[head[chain[v]]];
                }
        }
}
void down(int id)
{
        ll t=st[id].lazy;
        st[id*2].lazy+=t;
        st[id*2+1].lazy+=t;
        if (st[id*2].minn!=1e9)st[id*2].minn-=t;
        if (st[id*2+1].minn!=1e9)st[id*2+1].minn+=t;
        st[id*2].val-=1ll*st[id*2].d*t;
        st[id*2+1].val-=1ll*st[id*2+1].d*t;
        st[id].lazy=0;
}
void update(int id,int l,int r,int i,int j,int val)
{
        if (l>j||r<i) return;
        if (l==r)
        {
                st[id].minn-=val;
                st[id].val-=val;
                return;
        }
        down(id);
        int  m=(l+r)>>1;
        update(id*2,l,m,i,j,val);
        update(id*2+1,m+1,r,i,j,val);

        st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
        st[id].val=st[id*2].val+st[id*2+1].val;
}
ll get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l==r)
        {
                if (st[id].minn==1e9) return 0;
                if(st[id].minn>=0) return st[id].val;
                st[id].minn=1e9;
                return 0;
        }
        if (l>=i&&r<=j)
        {
                if (st[id].minn==1e9) return 0;
                if (st[id].minn>=0) return st[id].val;
        }
        int m=(l+r)>>1;
        down(id);
        ll t1=get(id*2,l,m,i,j);
        ll t2=get(id*2+1,m+1,r,i,j);
        st[id].val=st[id*2].val+st[id*2+1].val;
        st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
        return t1+t2;
}
void change(int u,int w,int val)
{
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        update(1,1,n,pos[w]+1,pos[u],val);
                        break;
                }
                update(1,1,n,pos[head[cu]],pos[u],val);
                u=pre[head[cu]];
        }
}
ll getval(int u,int w)
{
        ll res=0;
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        res+=get(1,1,n,pos[w],pos[u]);
                        break;
                }
                res+=get(1,1,n,pos[head[cu]],pos[u]);
                u=pre[head[cu]];
        }
        return res;
}
int main()
{
        freopen("MORETEA.inp","r",stdin);
        //freopen("MORETEA.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>n>>M>>test;
        for (int i=1; i<=n; ++i)
        {
                cin>>a[i];
                a[i]=M-a[i];
        }
        for (int i=2; i<=n; ++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        dfs(1,-1);
        cnt=1;
        hld(1,-1);
        build(1,1,n);
        while(test--)
        {
                int t,u,v,val;
                cin>>t;
                if (t==0)
                {
                        cin>>u>>v>>val;
                        int w=lca(u,v);
                        change(u,w,val);
                        change(v,w,val);
                        change(w,pre[w],val);
                        continue;
                }
                cin>>u>>v;
                int w=lca(u,v);
                ll res=1ll*(high[u]-2*high[w]+high[v]+1)*M-getval(u,w)-getval(v,w)+getval(w,w);
                cout<<res<<"\n";
        }
}
