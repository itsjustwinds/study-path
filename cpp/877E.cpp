#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
ll lazy[4*maxn];
int head[maxn],tail[maxn],n,test,st[4*maxn],a[maxn],cnt,pos[maxn];
int le[maxn],ri[maxn];
vector<int >e[maxn];
void swap_node(int id)
{
        st[id]=ri[id]-le[id]+1-st[id];
}
void dfs(int u)
{
        head[u]=++cnt;
        pos[cnt]=u;
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i];
                dfs(v);
        }
        tail[u]=cnt;
}
void build(int id,int l,int r)
{
        le[id]=l;
        ri[id]=r;
        if (l==r)
        {
                st[id]=a[pos[l]];
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=st[id*2]+st[id*2+1];
}
void down(int id)
{
        int t=lazy[id];
        lazy[id]=0;
        if (!t) return;
        lazy[id*2]^=1;
        lazy[id*2+1]^=1;
        swap_node(id*2);
        swap_node(id*2+1);
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        down(id);
        return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
void update(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return;
        if (l>=i&&r<=j)
        {
                swap_node(id);
                lazy[id]^=1;
                return;
        }
        int m=(l+r)>>1;
        down(id);
        update(id*2,l,m,i,j);
        update(id*2+1,m+1,r,i,j);
        st[id]=st[id*2]+st[id*2+1];
}
int main()
{
        freopen("877E.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2; i<=n; ++i)
        {
                int x;
                cin>>x;
                e[x].push_back(i);
        }
        for (int i=1; i<=n; ++i)
                cin>>a[i];
        dfs(1);
        build(1,1,n);
        cin>>test;
        while(test--)
        {
                int x;
                string c;
                cin>>c>>x;
                if (c[0]=='g')
                {
                        cout<<get(1,1,n,head[x],tail[x])<<"\n";
                        continue;
                }
                update(1,1,n,head[x],tail[x]);
        }
}
