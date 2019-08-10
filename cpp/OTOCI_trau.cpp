//PN
#include <bits/stdc++.h>
#define maxn 300005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;
int n,Q,a[maxn],deg[maxn];
vector<int> g[maxn];

III query[3*maxn];

int lt[maxn];

int cl[maxn],x[maxn],pre[maxn],depth[maxn];
int cnt[maxn],child[maxn];
int xhlt[maxn],pos[maxn],head[maxn],dhlt[maxn];
int m,L,R;

int it[4*maxn];
int tim(int u)
{
        if(lt[u]==u) return lt[u];
        lt[u]=tim(lt[u]);
        return lt[u];
}
void xaycau(int i,int u,int v)
{
        int u1=tim(u);
        int v1=tim(v);
        if(u1!=v1)
        {
                lt[u1]=v1;
                deg[u]++;
                g[u].push_back(v);
                deg[v]++;
                g[v].push_back(u);
        }
}
void HLTExtract(int r)
{
        ++L;
        int L1=L;
        R=L-1;
        x[++R]=r;
        cl[r]=1;

        pre[r]=depth[r]=0;
        while(L<=R)
        {
                int u=x[L++];
                for(int i=0; i<deg[u]; ++i)
                {
                        int v=g[u][i];
                        if(cl[v]==0)
                        {
                                x[++R]=v;
                                cl[v]=1;
                                pre[v]=u;
                                depth[v]=depth[u]+1;
                        }
                }
        }

        for(int i=R; i>=L1; --i)
        {
                int u=x[i];
                cnt[u]=1;
                for(int i=1; i<=n; ++i) lt[i]=i;
                child[u]=0;
                int slmax=0;
                for(int j=0; j<deg[u]; ++j)
                {
                        int v=g[u][j];
                        if(pre[v]==u)
                        {
                                cnt[u]+=cnt[v];
                                if(cnt[v]>slmax) slmax=cnt[v], child[u]=v;
                        }
                }
                if(slmax<cnt[u]/2) child[u]=0;
        }

        for(int i=L1; i<=R; ++i)
        {
                int u=x[i];
                if(u==r || child[pre[u]]!=u)
                {
                        xhlt[++m]=u;
                        head[u]=u;
                        pos[u]=m;
                        int v=u;
                        while(child[v])
                        {
                                v=child[v];
                                xhlt[++m]=v;
                                pos[v]=m;
                                head[v]=u;
                        }
                }
        }

        dhlt[r]=0;
        for(int i=L1; i<=R; ++i)
        {
                int u=x[i];
                for(int j=0; j<deg[u]; ++j)
                {
                        int v=g[u][j];
                        if(pre[v]==u && child[u]!=v) dhlt[v]=dhlt[head[u]]+1;
                }
        }
}
void update(int r,int k,int l,int u,int val)
{
        if(u<k || u>l) return;
        if(u<=k && l<=u)
        {
                it[r]=val;
                return;
        }
        int g=(k+l)/2;
        update(2*r,k,g,u,val);
        update(2*r+1,g+1,l,u,val);
        it[r]=it[2*r]+it[2*r+1];
}
int get(int r,int k,int l,int u,int v)
{
        if(v<k || u>l) return 0;
        if(u<=k && l<=v) return it[r];
        int g=(k+l)/2;
        int t1=get(2*r,k,g,u,v);
        int t2=get(2*r+1,g+1,l,u,v);
        return t1+t2;
}
void Change(int i,int val)
{
        update(1,1,n,pos[i],val);
}
int dis(int u,int v)
{
        int kq=0;
        while(dhlt[head[u]]>dhlt[head[v]])
        {
                kq+=get(1,1,n,pos[head[u]],pos[u]);
                u=pre[head[u]];
        }
        while(dhlt[head[v]]>dhlt[head[u]])
        {
                kq+=get(1,1,n,pos[head[v]],pos[v]);
                v=pre[head[v]];
        }
        while(head[u]!=head[v])
        {
                kq+=get(1,1,n,pos[head[u]],pos[u]);
                u=pre[head[u]];
                kq+=get(1,1,n,pos[head[v]],pos[v]);
                v=pre[head[v]];
        }
        if(depth[u]<depth[v]) kq+=get(1,1,n,pos[u],pos[v]);
        else kq+=get(1,1,n,pos[v],pos[u]);

        return kq;
}
int main()
{
        freopen("D:\\C++\\debug\\OTOCI.inp","r",stdin);
        freopen("D:\\C++\\debug\\OTOCI.ans","w",stdout);
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        for(int i=1; i<=n; ++i) lt[i]=i;

        cin>>Q;
        for(int i=1; i<=Q; ++i)
        {
                char s[20];
                int u,v;
                cin>>s;
                cin>>u>>v;
                if(s[0]=='b')
                {
                        query[i]=III(1,II(u,v));
                        xaycau(i,u,v);
                }
                else if(s[0]=='e') query[i]=III(2,II(u,v));
                else query[i]=III(3,II(u,v));
        }

        for(int i=1; i<=n; ++i)
                if(cl[i]==0) HLTExtract(i);

        for(int i=1; i<=n; ++i)
                Change(i,a[i]);

        for(int i=1; i<=n; ++i) lt[i]=i;

        for(int i=1; i<=Q; ++i)
        {
                int id=query[i].fs;
                int u=query[i].sc.fs, v=query[i].sc.sc;
                if(id==1)
                {
                        u=tim(u);
                        v=tim(v);
                        if(u!=v)
                        {
                                lt[u]=v;
                                cout<<"yes\n";
                        }
                        else cout<<"no\n";
                }
                else if(id==2)
                {
                        int u1=tim(u);
                        int v1=tim(v);
                        if(u1==v1) cout<<dis(u,v)<<"\n";
                        else cout<<"impossible\n";
                }
                else Change(u,v);
        }
}
