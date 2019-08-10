#include<bits/stdc++.h>
#define maxn 100005
#define oo 111111111
using namespace std;
int a[maxn],chain[maxn],head[maxn],pos[maxn],cnt,dem,trc[maxn],h[maxn],st[5*maxn],res,n;
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
                h[v]=h[u]+1;
                if (vtx==-1) vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0;i<(int)e[u].size();i++)
        {
                int v=e[u][i];
                if (v==trc[u]||v==vtx) continue;
                cnt++;
                hld(v);
        }
}
void update(int id,int l,int r,int i)
{
        if (l>i||r<i) return;
        if (l==r&&l==i)
        {
                if (st[id]!=0) st[id]=0;
                else
                {
                        st[id]=a[i];
                }
                return;
        }
        int m=(l+r)>>1;
        update(id*2,l,m,i);
        update(id*2+1,m+1,r,i);
        int u=st[id*2],v=st[id*2+1];
        if (h[u]<h[v]) st[id]=u;
        else st[id]=v;
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        int tmp1=get(id*2,l,m,i,j);
        int tmp2=get(id*2+1,m+1,r,i,j);
        if (h[tmp1]<h[tmp2]) return tmp1;
        else return tmp2;
}
void getrekt(int u,int w)
{
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        int tmp=get(1,1,dem,pos[w],pos[u]);
                        if (h[res]>h[tmp]) res=tmp;
                        break;
                }
                int tmp=get(1,1,dem,pos[head[cu]],pos[u]);
                if (h[res]>h[tmp]) res=tmp;
                u=trc[head[chain[u]]];
        }
}
int main()
{
        freopen("QTREE3.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>n>>test;
        cnt=1;
        for (int i=1;i<n;i++)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        hld(1);
        h[0]=oo;
        while(test--)
        {
                int x;
                cin>>x;
                if (x==0)
                {
                        int u;
                        cin>>u;
                        update(1,1,n,pos[u]);
                        continue;
                }
                if (x==1)
                {
                        int u;
                        cin>>u;
                        res=0;
                        getrekt(u,1);

                        if (res!=0&&res!=oo)cout<<res<<"\n";
                        else cout<<"-1\n";
                }
        }
        return 0;
}
