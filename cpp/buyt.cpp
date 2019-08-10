#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000007
using namespace std;
int a[maxn],d[5],c[5],n,t,s;
long long f[maxn],x,it[4*maxn];
void findd(int id,int l,int r,int dis,int i)
{
    if (l>i||a[i]-a[r]>=d[dis]) return;
    if (a[i]-a[l]<=d[dis])
    {
        x=min(x,it[id]+c[dis]);
        return;
    }
    int m=(l+r)/2;
    findd(id*2,l,m,dis,i);
    findd(id*2+1,m+1,r,dis,i);
}
void update(int id,int i,int l,int r)
{
    if (l>i||r<i) return;
    if (l==r)
    {
        it[id]=min(f[i],it[id]);
        return;
    }
    int m=(l+r)/2;
    update(id*2,i,l,m);
    update(id*2+1,i,m+1,r);
    it[id]=min(it[id*2],it[id*2+1]);
}
int main()
{
    freopen("buyt.inp","r",stdin);
    freopen("buyt.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=3; i++) cin>>d[i];
    for (int i=1; i<=3; i++) cin>>c[i];
    cin>>t>>s;
    for (int i=2; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) f[i]=oo;
    for (int i=1; i<=4*maxn; i++) it[i]=oo;
    f[t]=0;
    update(1,t,1,n);
    for (int i=t+1; i<=s; i++)
    {
        x=oo;
        findd(1,1,n,1,i);
        f[i]=min(f[i],x);
        x=oo;
        findd(1,1,n,2,i);
        f[i]=min(f[i],x);
        x=oo;
        findd(1,1,n,3,i);
        f[i]=min(f[i],x);
        update(1,i,1,n);
    }
    cout<<f[s];
    return 0;
}
