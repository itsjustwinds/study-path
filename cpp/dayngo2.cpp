#include <bits/stdc++.h>
#define maxn 100005
#define oo 1000000000
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
    tr[id]=min(tr[id*2],tr[id*2+1]);
}
int get(int id,int l,int r,int i,int j)
{
    if (i>r||j<l) return oo;
    if (i<=l&&j>=r)
    {
        return tr[id];
    }
    int m=(l+r)/2;
    int c=get(id*2,l,m,i,j);
    int d=get(id*2+1,m+1,r,i,j);
        return min(c,d);
}
int main()
{
    freopen("dayngo2.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        char q;
        cin>>q;
        int x;
        if (q=='(') x=1;
        else x=-1;
        a[i]=a[i-1]+x;
    }
    update(1,1,n);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if (a[v]-a[u-1]==0&&get(1,1,n,u,v)>=a[u-1]) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
