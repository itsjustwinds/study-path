#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int st[5*maxn],n,c[maxn][maxn],head[maxn],pos[maxn],cnt,dem,chain[maxn],trc[maxn],h[maxn],res,a[maxn];
vector<int> e[maxn];
void hld(int u)
{
        if (head[cnt]==0) head[cnt]=u;
        pos[u]=++dem;
        a[dem]=u;
        chain[u]=cnt;
        int vtx=-1;
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                trc[v]=u;
                if (vtx==-1) vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i];
                if (v==trc[u]||v==vtx) continue;
                cnt++;
                h[cnt]=h[chain[u]]+1;
                hld(v);
        }
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=c[trc[a[l]]][a[l]];
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
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
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j) return st[id];
        int m=(l+r)>>1;
        return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
void getdis(int u,int w)
{
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        res+=get(1,1,dem,pos[w]+1,pos[u]);
                        break;
                }
                res+=get(1,1,dem,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
}
int getpos(int u,int w)
{
    int kq=0;
    while(1)
    {
            int cu=chain[u],cw=chain[w];
            if (cu==cw)
            {
                    kq+=pos[u]-pos[w]+1;
                    break;
            }
            kq+=pos[u]-pos[head[cu]]+1;
            u=trc[head[cu]];
    }
    return kq;
}
void solve(int u,int w,int k)
{
        while(k)
        {
                int cu=chain[u];
                int tmp=pos[u]-pos[head[cu]]+1;
                if (k-tmp<=0)
                {
                        res=a[pos[head[cu]]+tmp-k];
                        return;
                }
                k-=tmp;
                u=trc[head[cu]];
        }
        res=w;
}
int main()
{
        freopen("QTREE2.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cnt=1;
                dem=0;
                cin>>n;
                for (int i=1;i<=n;i++)
                        e[i].clear();
                memset(head,0,sizeof(head));
                for (int i=1;i<n;i++)
                {
                        int u,v,val;
                        cin>>u>>v>>val;
                        c[u][v]=val;
                        c[v][u]=val;
                        e[u].push_back(v);
                        e[v].push_back(u);
                }
                hld(1);
                build(1,1,dem);
                char s[10];
                while(1)
                {
                        cin>>(s+1);
                        if (s[2]=='O') break;
                        if (s[2]=='I')
                        {
                                int u,v;
                                cin>>u>>v;
                                int w=lca(u,v);
                                res=0;
                                getdis(u,w);
                                getdis(v,w);
                                cout<<res<<"\n";
                                continue;
                        }
                        if (s[2]=='T')
                        {
                                int u,v,k;
                                cin>>u>>v>>k;
                                res=0;
                                int w=lca(u,v);
                                int k1=getpos(u,w);
                                int k2=getpos(v,w);
                                if (k1>=k)
                                {
                                        solve(u,w,k);
                                }
                                else if (k1+k2-k>=0)solve(v,w,k1+k2-k);
                                else res=v;
                                cout<<res<<"\n";
                        }
                }
        }
        return 0;
}

