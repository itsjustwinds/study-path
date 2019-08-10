#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define sc second
using namespace std;
int c[maxn][maxn],n,trc[maxn],h[maxn],head[maxn],chain[maxn],cnt,a[maxn],dem,pos[maxn],st[5*maxn],res,lazy[5*maxn];
typedef pair<int,int> II;
II edge[maxn];
vector<int>e[maxn];
void hld(int u)
{
          if (head[cnt]==0) head[cnt]=u;
          a[++dem]=u;
          chain[u]=cnt;
          pos[u]=dem;
          int vmtx=-1;
          for (int i=0; i<(int)e[u].size(); i++)
          {
                    int v=e[u][i];
                    if (v==trc[u]) continue;
                    if (vmtx==-1) vmtx=v;
          }
          if (vmtx!=-1)
          {
                    trc[vmtx]=u;
                    hld(vmtx);
          }
          for (int i=0; i<(int)e[u].size(); i++)
          {
                    int v=e[u][i];
                    if (v==vmtx||v==trc[u]) continue;
                    cnt++;
                    h[cnt]=h[chain[u]]+1;
                    trc[v]=u;
                    hld(v);
          }
}
void build(int id,int l,int r)
{
          if (l==r)
          {
                    st[id]=c[a[l]][trc[a[l]]];
                    return;
          }
          int m=(l+r)>>1;
          build(id*2,l,m);
          build(id*2+1,m+1,r);
          st[id]=max(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int i,int val)
{
          if (l>i||r<i) return;
          if (l==r&&l==i)
          {
                    st[id]=val;
                    return;
          }
          int m=(l+r)>>1;
          update(id*2,l,m,i,val);
          update(id*2+1,m+1,r,i,val);
          st[id]=max(st[id*2],st[id*2+1]);
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
int getmax(int id,int l,int r,int i,int j)
{
          if (l>r) return 0;
          if (l>j||r<i) return 0;
          if (l>=i&&r<=j)
          {
                    return st[id];
          }
          int m=(l+r)>>1;
          return max(getmax(id*2,l,m,i,j),getmax(id*2+1,m+1,r,i,j));
}
void get(int u,int w)
{
          while(1)
          {
                    if (chain[u]==chain[w])
                    {
                              res=max(res,getmax(1,1,n,pos[w]+1,pos[u]));
                              break;
                    }
                    res=max(res,getmax(1,1,n,pos[head[chain[u]]],pos[u]));
                    u=trc[head[chain[u]]];
          }
}
int main()
{
          freopen("QTREE.inp","r",stdin);
          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          int test;
          cin>>test;
          while(test--)
          {
                    cin>>n;
                    dem=0;
                    cnt=1;
                    memset(head,0,sizeof(head));
                    for (int i=1; i<=n; i++)
                              e[i].clear();
                    for (int i=1; i<=n; i++)
                              trc[i]=0;
                    for (int i=1; i<n; i++)
                    {
                              int u,v,val;
                              cin>>u>>v>>val;
                              e[u].push_back(v);
                              e[v].push_back(u);
                              c[u][v]=val;
                              edge[i]=II(u,v);
                              c[v][u]=val;
                    }
                    hld(1);
                    build(1,1,n);
                    char s[10];
                    while(1)
                    {
                              cin>>(s+1);
                              if (s[1]=='D') break;
                              if (s[1]=='C')
                              {
                                        int ik;
                                        int val;
                                        cin>>ik>>val;
                                        II tmp=edge[ik];
                                        if (trc[tmp.fs]==tmp.sc) update(1,1,n,pos[tmp.fs],val);
                                        else update(1,1,n,pos[tmp.sc],val);
                                        continue;
                              }
                              if (s[1]=='Q')
                              {
                                        int u,v;
                                        res=0;
                                        cin>>u>>v;
                                        int w=lca(u,v);
                                        get(u,w);
                                        get(v,w);
                                        cout<<res<<"\n";
                              }
                    }
          }
          return 0;
}
