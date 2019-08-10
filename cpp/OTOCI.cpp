#include<bits/stdc++.h>
#define maxn 300005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;
III que[maxn];
int a[maxn],n,q,root[maxn],head[maxn],chain[maxn],h[maxn],b[maxn],cnt,dem,pos[maxn],trc[maxn],st[5*maxn],res,dd[maxn];
vector<int> e[maxn];
int getroot(int u)
{
        return (root[u]==u) ? u : root[u]=getroot(root[u]);
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j) return st[id];
        int m=(l+r)>>1;
        return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
void getrekt(int u,int v)
{
        int tmp1=u;
        int tmp2=v;
        int w;
        while(1)
        {
                int cu=chain[u],cv=chain[v];
                if (cu==cv) break;
                if (h[cu]>h[cv]) u=trc[head[cu]];
                else v=trc[head[cv]];
        }
        if (pos[u]<pos[v]) w=u;
        else w=v;
        u=tmp1;
        v=tmp2;
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        res+=get(1,1,n,pos[w],pos[u]);
                        break;
                }
                res+=get(1,1,n,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
        u=v;
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        res+=get(1,1,n,pos[w],pos[u]);
                        break;
                }
                res+=get(1,1,n,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
        res-=get(1,1,n,pos[w],pos[w]);
}
void hld(int u)
{
        if (head[cnt]==0) head[cnt]=u;
        a[++dem]=u;
        dd[u]=1;
        chain[u]=cnt;
        pos[u]=dem;
        int vtx=-1;
        for (int i=0; i<(int)e[u].size(); i++)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                trc[v]=u;
                vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0; i<(int)e[u].size(); i++)
        {
                int v=e[u][i];
                if (v==trc[u]||v==vtx) continue;
                cnt++;
                h[cnt]=h[chain[u]]+1;
                hld(v);
        }
}
int lca(int u,int v)
{
        while(1)
        {
                int cu=chain[u],cv=chain[v];
                if (cu==cv) break;
                if (h[cu]>h[cv]) u=trc[head[cu]];
                else v=trc[head[cv]];
        }
        if (pos[u]<pos[v]) return u;
        else return v;
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=b[a[l]];
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r,int i,int val)
{
        if(l>i||r<i) return;
        if (l==r&&l==i)
        {
                st[id]=val;
                return;
        }
        int m=(l+r)>>1;
        update(id*2,l,m,i,val);
        update(id*2+1,m+1,r,i,val);
        st[id]=st[id*2]+st[id*2+1];
}
int main()
{
        freopen("D:\\C++\\debug\\OTOCI.inp","r",stdin);
        //freopen("D:\\C++\\debug\\OTOCI.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
                scanf("%d", &b[i]);
        scanf("%d", &q);
        for (int i=1; i<=n; i++)
                root[i]=i;
        for (int i=1; i<=q; i++)
        {
                char s[15];
                scanf("%s", s + 1);
                if (s[1]=='b')
                {
                        int u,v;
                        que[i].fs=1;
                        scanf("%d%d",&u,&v);
                        int ru=getroot(u);
                        int rv=getroot(v);
                        if (ru==rv)
                        {
                                que[i].sc.fs=0;
                                continue;
                        }
                        root[ru]=rv;
                        e[u].push_back(v);
                        e[v].push_back(u);
                        que[i].sc.fs=1;
                        continue;
                }
                if (s[1]=='p')
                {
                        int u,val;
                        scanf("%d%d",&u,&val);
                        que[i].fs=2;
                        que[i].sc.fs=u;
                        que[i].sc.sc=val;
                        continue;
                }
                if (s[1]=='e')
                {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        if (getroot(u)!=getroot(v))
                        {
                                que[i].fs=3;
                                que[i].sc.fs=-1;
                                continue;
                        }
                        que[i].fs=3;
                        que[i].sc.fs=u;
                        que[i].sc.sc=v;
                }

        }
        for (int i=1; i<=n; i++)
                if (!dd[i])
                {
                        cnt++;
                        hld(i);
                }
        build(1,1,n);
        for (int i=1; i<=q; i++)
        {
                if (que[i].fs==1)
                {
                        if (que[i].sc.fs) printf("yes\n");
                        else printf("no\n");
                        continue;
                }
                if (que[i].fs==2)
                {
                        update(1,1,n,pos[que[i].sc.fs],que[i].sc.sc);
                        continue;
                }
                if (que[i].sc.fs==-1)
                {
                        printf("impossible\n");
                        continue;
                }
                int u=que[i].sc.fs,v=que[i].sc.sc;
                res=0;
                getrekt(u,v);
                printf("%d\n",res);
        }
        return 0;
}
