#include <bits/stdc++.h>
#define maxn 1005
#define oo 1000000005
using namespace std;
int IT[4*maxn],a[maxn],n,t[maxn],s,dem,res[maxn],trace[maxn];
long long f[maxn];
void update(int id,int l,int r)
{
    if (l==r)
    {
        IT[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m);
    update(id*2+1,m+1,r);
    IT[id]=max(IT[2*id],IT[2*id+1]);

}
int get(int id,int l,int r, int i,int j)
{
    if (l>j||r<i) return -oo;
    if (i<=l&&j>=r)
    {
        return IT[id];
    }
    return max(get(id*2,l,(l+r)/2,i,j),get(id*2+1,(l+r)/2+1,r,i,j));
}
int main()
{
    freopen("mterchef.inp","r",stdin);
    //freopen("mterchef.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[i]=t[i-1]+a[i];
    }
    update(1,1,n);
    for (int i=1;i<=n;i++)
    {
        f[i]=oo;
        trace[i]=i;
        for (int j=i;j>=0;j--)
        if (t[i]-t[j-1]<=s)
        {
            int x=get(1,1,n,j,i);
            if (f[i]>f[j-1]+x)
            {
                f[i]=f[j-1]+x;
                trace[i]=j;
            }
        }
    }
    cout<<f[n]<<"\n";
    int i=n;
    while (i!=0)
    {
        for (int j=i;j>=trace[i];j--)
        {
            dem++;
            res[dem]=j;
        }
        dem++;
        res[dem]=0;
        i=trace[i]-1;
    }
    for (int i=dem-1;i>=0;i--)
        if(res[i]!=0) cout<<res[i]<<" ";
    else cout<<"\n";
    return 0;

}

