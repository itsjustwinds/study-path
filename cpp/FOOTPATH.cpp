#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        int x,y,p;
};
data a[maxn];
int n,k,p[maxn];
int x[2*maxn];
ll st[9*maxn],f[2*maxn];
bool cmp(data a,data b)
{
        return a.y<b.y;
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=1e18;
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=min(st[id*2],st[id*2+1]);
}
ll get(int id,int l,int r,int i,int j)
{
        if (i>j) return 1e18;
        if (l>j||r<i) return 1e18;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        return min(get(id*2,l,m,i,j),get(id*2+1,m+1,r,i,j));
}
void update(int id,int l,int r,int x,ll val)
{
        if (l>x||r<x) return;
        if (l==r&&l==x)
        {
                st[id]=val;
                return;
        }
        int m=(l+r)>>1;
        update(id*2,l,m,x,val);
        update(id*2+1,m+1,r,x,val);
        st[id]=min(st[id*2],st[id*2+1]);
}
int main()
{
        freopen("FOOTPATH.inp","r",stdin);
        //freopen("FOOTPATH.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        int d=0;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].y>>a[i].p;
                x[++d]=a[i].x;
                x[++d]=a[i].y;
        }
        sort(a+1,a+n+1,cmp);
        sort(x+1,x+2*n+1);
        for (int i=1;i<=n;++i)
        {
                a[i].x=lower_bound(x,x+2*n+1,a[i].x)-x;
                a[i].y=lower_bound(x,x+2*n+1,a[i].y)-x;
        }
        build(1,0,2*n);
        update(1,0,2*n,0,0);
        for (int i=1;i<=2*n;++i)
                f[i]=1e18;
        f[0]=0;
        for (int i=1;i<=n;++i)
        {
                int X=a[i].x;
                int y=a[i].y;
                int p=a[i].p;
                int t=lower_bound(x,x+2*n+1,x[X]-1)-x;
                if (x[t]!=x[X]-1) t=X;
                ll tmp=get(1,0,2*n,t,y);
                if(tmp==1e18) continue;
                f[y]=min(f[y],tmp+p);
                update(1,0,2*n,y,f[y]);
        }
        int l=a[n].y;
        if (f[l]==1e18)
        {
                cout<<-1;
        }
        else cout<<f[l];
        return 0;
}
