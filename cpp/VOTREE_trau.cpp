#include<bits/stdc++.h>

#define maxN 70001

using namespace std;
vector<int> DSK[maxN]; int level[maxN],P[maxN],Pa[maxN][18],n,q,IT[5*maxN];

int log2(int x){ return (long)(log(x)/log(2)); }

void DFS(int x)
{
    for (int i=0; i<DSK[x].size(); i++)
    {
        int y=DSK[x][i];
        if (level[y]>-1) continue;
        level[y]=level[x]+1;
        P[y]=x;
        DFS(y);
    }
}

void init()
{
    for (int i=2; i<=n; i++) level[i]=-1; level[1]=0;
    DFS(1);
    for (int i=1; i<=n; i++) Pa[i][0]=P[i];
    for (int j=1; j<=log2(n); j++) for (int i=1; i<=n; i++) if (level[i]>=(1<<j))
        Pa[i][j]=Pa[Pa[i][j-1]][j-1];
}

int LCA(int u,int v)
{
    if (u==0) return v;
    if (v==0) return u;
    if (level[u]<level[v]) swap(u,v);
    while (level[u]>level[v])
    {
        int tmp=log2(level[u]-level[v]);
        u=Pa[u][tmp];
    }
    if (u==v) return u;
    while (Pa[u][0]!=Pa[v][0])
    {
        for (int i=log2(n); i>=0; i--) if (Pa[u][i]!=Pa[v][i])
        {
            u=Pa[u][i]; v=Pa[v][i]; break;
        }
    }
    return Pa[u][0];
}

void build(int k,int l,int r)
{
    if (r==l)
    {
        IT[k]=l; return;
    }
    else
    {
        int mid=(l+r)/2;
        build(k*2,l,mid);
        build(k*2+1,mid+1,r);
        IT[k]=LCA(IT[k*2],IT[k*2+1]);
    }
}

int get(int k,int l,int r,int u,int v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return IT[k];
    int mid=(l+r)/2;
    return LCA(get(k*2,l,mid,u,v),get(k*2+1,mid+1,r,u,v));
}

int main()
{
    freopen("D:\\C++\\huy\\VOTREE.inp","r",stdin);
    //freopen("D:\\C++\\huy\\VOTREE.ans","w",stdout);
    int u,v;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1; i<n; i++)
    {
        cin>>u>>v;
        DSK[u].push_back(v);
        DSK[v].push_back(u);
    }
    init();
    build(1,1,n);
    while (q--)
    {
        cin>>u>>v;
        cout<<get(1,1,n,u,v)<<'\n';
    }
    return 0;
}
