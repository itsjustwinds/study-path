#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int tr[4*maxn],a[maxn],n,m;
void update(int id,int l,int r)
{
    if (l==r)
    {
        tr[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m);
    update(id*2+1,m+1,r);
    tr[id]=max(tr[id*2],tr[id*2+1]);
}
void up(int id,int l,int r,int i,int j,int v)
{
    if (i>r||j<l) return;
    if (l==r)
    {
        tr[id]=v;
        return;
    }
    int m=(l+r)/2;
    up(id*2,l,m,i,j,v);
    up(id*2+1,m+1,r,i,j,v);
    tr[id]=max(tr[id*2],tr[id*2+1]);
}
int get(int id,int l,int r,int i,int j)
{
    if(i>r||j<l) return 0;
    if (i<=l&&j>=r)
        return tr[id];
    int m=(l+r)/2;
    int c=get(id*2,l,m,i,j);
    int d=get(id*2+1,m+1,r,i,j);
    return max(c,d);
}
int main()
{
    freopen("games.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    update(1,1,n);
    for (int i=1;i<=m;i++)
    {
        int u,v,k;
        cin>>u>>v;
        k=get(1,1,n,u,u+v-1);
        up(1,1,n,u,u+v-1,k+1);
        cout<<k+1<<"\n";
    }
    return 0;
}
