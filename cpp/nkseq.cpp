#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000000
using namespace std;
int f[maxn*2],a[maxn],n,it[8*maxn],res;
void update(int id,int l,int r)
{
    if (l==r)
    {
        it[id]=f[l];
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m);
    update(id*2+1,m+1,r);
    it[id]=min(it[id*2],it[id*2+1]);
}
int get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i)
    {
        return oo;
    }
    if (l>=i&&r<=j)
    {
        return it[id];
    }
    return min(get(id*2,l,(l+r)/2,i,j),get(id*2+1,(l+r)/2+1,r,i,j));
}
int main()
{
    //freopen("nkseq.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    for (int i=1;i<=n-1;i++)
        f[n+i]=f[n+i-1]+a[i];
    update(1,1,2*n-1);
    for (int i=1;i<=n;i++)
    {
        int k=get(1,1,2*n-1,i,i+n-1);
        if (k>f[i-1]) res++;
    }
    cout<<res;
    return 0;
}
