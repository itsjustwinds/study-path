#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
            int u,v,w,m,id,pos;
            char s;
};
data c[maxn],q[maxn],f[maxn];
int n,head[maxn],chain[maxn],pos[maxn],a[maxn],cnt,dem,h[maxn],test,trc[maxn],fc,st[5*maxn],ed[maxn],res,ans[maxn];
typedef pair<int,int> II;
vector<int> e[maxn];
bool cmp (data a,data b)
{
            return a.w<b.w;
}
void hld(int u)
{
            if (head[cnt]==0) head[cnt]=u;
            chain[u]=cnt;
            a[++dem]=u;
            pos[u]=dem;
            int vtx=-1;
            for (int i=0; i<(int)e[u].size(); ++i)
            {
                        int v=e[u][i];
                        if (v==trc[u]) continue;
                        trc[v]=u;
                        if (vtx==-1) vtx=v;
            }
            if (vtx!=-1) hld(vtx);
            for (int i=0; i<(int)e[u].size(); ++i)
            {
                        int v=e[u][i];
                        if (v==trc[u]||v==vtx) continue;
                        ++cnt;
                        h[cnt]=h[chain[u]]+1;
                        hld(v);
            }
            ed[u]=dem;
}
void update(int id,int l,int r,int i)
{
            if (l>i||r<i) return;
            if (l==r)
            {
                        st[id]=1;
                        return;
            }
            int m=(l+r)>>1;
            update(id*2,l,m,i);
            update(id*2+1,m+1,r,i);
            st[id]=st[id*2]+st[id*2+1];
}
int lca(int u,int v)
{
          while(chain[u]!=chain[v])
          {
                    if (h[chain[u]]>h[chain[v]]) u=trc[head[chain[u]]];
                    else v=trc[head[chain[v]]];
          }
          if (pos[u]<pos[v]) return u;
          else return v;
}
int get(int id,int l,int r,int i,int j)
{
            if (l>j||r<i)
            {
                        return 0;
            }
            if (l>=i&&r<=j) return st[id];
            int m=(l+r)>>1;
            return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
void getres(int u,int v)
{
            while(1)
            {
                        int cu=chain[u],cv=chain[v];
                        if (cu==cv)
                        {
                                    res+=get(1,1,n,pos[v]+1,pos[u]);
                                    break;
                        }
                        res+=get(1,1,n,pos[head[cu]],pos[u]);
                        u=trc[head[cu]];
            }
}
int main()
{
            freopen("D:\\C++\\debug\\NETWRKNB.inp","r",stdin);
            freopen("D:\\C++\\debug\\NETWRKNB.out","w",stdout);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
           // scanf("%d %d",&n,&test);
            cin>>n>>test;
            for (int i=1; i<n; ++i)
            {
                        int u,v,w;
                        //scanf("%d %d %d",&u,&v,&w);
                        cin>>u>>v>>w;
                        e[u].push_back(v);
                        e[v].push_back(u);
                        c[i].u=u;
                        c[i].v=v;
                        c[i].w=w;
                        f[++fc].w=w;
                        f[fc].pos=i;
            }
            h[1]=1;
            sort(f+1,f+fc+1,cmp);
            cnt=1;
            for (int i=1; i<=test; ++i)
            {
                        char x;
                        //scanf("%c",&x);
                        //scanf("%c",&q[i].s);
                        cin>>q[i].s;
                        q[i].id=i;
                        if (q[i].s=='P')
                        {
                                    //scanf("%d %d %d",&q[i].u,&q[i].v,&q[i].w);
                                    cin>>q[i].u>>q[i].v>>q[i].w;
                                    continue;
                        }
                        //scanf("%d %d",&q[i].u,&q[i].w);
                        cin>>q[i].u>>q[i].w;
            }
            sort(q+1,q+test+1,cmp);
            hld(1);
            for (int i=1; i<n; ++i)
            {
                        int u=c[i].u;
                        int v=c[i].v;
                        if (u==trc[v])
                        {
                                    c[i].m=v;
                        }
                        else c[i].m=u;
            }
            int now=1;
            for (int i=1; i<=test; ++i)
            {
                        while(now!=fc+1&&f[now].w<=q[i].w)
                        {
                                    int k=f[now].pos;
                                    update(1,1,n,pos[c[k].m]);
                                    ++now;
                        }
                        if (q[i].s=='P')
                        {
                                    int u=q[i].u;
                                    int v=q[i].v;
                                    int w=lca(u,v);
                                    res=0;
                                    getres(u,w);
                                    getres(v,w);
                                    ans[q[i].id]=res;
                        }
                        else
                        {
                                    int k=q[i].u;
                                    int u=c[k].u;
                                    int v=c[k].v;
                                    if (u==trc[v])
                                    {
                                                res=get(1,1,n,pos[v]+1,ed[v]);
                                                ans[q[i].id]=res;
                                                continue;
                                    }
                                    res=get(1,1,n,1,n);
                                    res-=get(1,1,n,pos[u]+1,ed[u]);
                                    //if (c[k].w<=q[i].w) res--;
                                    ans[q[i].id]=res;
                        }
            }
            for (int i=1; i<=test; ++i)
            {
                        cout<<ans[i]<<"\n";
            }
            return 0;
}
