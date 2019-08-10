#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int st[4*maxn],pos[maxn],chance[maxn],head[maxn],trc[maxn],n,root[2],cnt,d,res[maxn];
long long ans;
vector<int > e[2][maxn];
void hld(int u)
{
        if (!head[cnt]) head[cnt]=u;
        chance[u]=cnt;
        pos[u]=++d;
        int vtx=-1;
        for (int i=0;i<e[0][u].size();++i)
        {
                int v=e[0][u][i];
                vtx=v;
                trc[v]=u;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0;i<e[0][u].size();++i)
        {
                int v=e[0][u][i];
                if (v==vtx) continue;
                ++cnt;
                hld(v);
        }
}
void update(int id,int l,int r,int i,int val)
{
        if (l>i||r<i) return;
        if (l>=i&&r<=i)
        {
                st[id]=val;
                return;
        }
        int m=(l+r)>>1;
        update(id*2,l,m,i,val);
        update(id*2+1,m+1,r,i,val);
        st[id]=st[id*2]+st[id*2+1];
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
int getval(int u,int w)
{
        int res=0;
        while(1)
        {
                int cu=chance[u];
                int cw=chance[w];
                if (cu==cw)
                {
                        res+=get(1,1,n,pos[w],pos[u]);
                        break;
                }
                res+=get(1,1,n,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
        return res;
}
void dfs(int u)
{
        res[u]=getval(u,root[0]);
        update(1,1,n,pos[u],1);
        for (int i=0;i<e[1][u].size();++i)
        {
                int v=e[1][u][i];
                dfs(v);
        }
        update(1,1,n,pos[u],0);
}
int main()
{
        freopen("VIRUS.inp","r",stdin);
        freopen("VIRUS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                if (x==0) root[0]=i;
                e[0][x].push_back(i);
        }
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                if (x==0) root[1]=i;
                e[1][x].push_back(i);
        }
        cnt=1;
        hld(root[0]);
        dfs(root[1]);
        for (int i=1;i<=n;++i)
                ans+=res[i];
        cout<<ans;
        return 0;
}
