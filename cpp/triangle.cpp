#include <bits/stdc++.h>
using namespace std;
int a[1001],b[1001],c[1001];
/*int sort(int a[1001],int l,int r)
{
    int u=l;
    int v=r;
    int x=a[int((l+r)/2)];
    while (u<=v)
    {
        while (a[u]<x) u++;
        while (a[v]>x) v--;
        if (u<=v)
        {
            int t;
            t=a[u];
            a[u]=a[v];
            a[v]=t;
            u++;
            v--;
        }
    }
    if (l<=v) sort(a,l,v);
    if (u<=v) sort(a,u,r);
    return 0;
}*/
int findmin(int a[1001],int x,int l,int r,int n1)
{
    if (l>r) return 1002;
    int vt=int((l+r)/2);
    int tmp=a[vt];
    if (tmp>=x) return (findmin(a,x,l,vt-1,n1));
    if (tmp<x && (x-n1)>=(tmp+n1)) return (findmin(a,x,vt+1,r,n1));
    if (tmp<x && n1>=(tmp+x-n1)) return (findmin(a,x,vt+1,r,n1));
    return (min(vt,findmin(a,x,l,vt-1,n1)));
}
int pow(int x,int k)
{
    int res=1;
    for (int i=1; i<=k; i++)
        res*=x;
    return res;
}
int findmax(int a[1001],int x,int l,int r,int n1)
{
    if (l>r) return 0;
    int  vt=int((l+r)/2);
    int tmp=a[vt];
    if (tmp>=x) return(findmax(a,x,l,vt-1,n1));
    if (tmp<x && (x-n1)>=(tmp+n1)) return(findmax(a,x,vt+1,r,n1));
    if (tmp<x && n1>=(tmp+x-n1)) return(findmax(a,x,vt+1,r,n1));
    return(max(vt,findmax(a,x,vt+1,r,n1)));
}
int finddel(int a[1001],int x,int l,int r)
{
    if (l>r) return 0;
    int vt=int ((l+r)/2);
    int tmp=a[vt];
    if (x>tmp) return(finddel(a,x,vt+1,r));
    if (x<tmp) return(finddel(a,x,l,vt-1));
    if (x==tmp) return(1+finddel(a,x,vt+1,r)+finddel(a,x,vt+1,r));
    return 0;
}
int main()
{
    freopen("triangle.inp","r",stdin);
    freopen("triangle.out","w",stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int i=1; i<=n; i++)
        cin>>c[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    int res=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int vtmax=findmax(c,a[i]+b[j],1,n,a[i]);
            int vtmin=findmin(c,a[i]+b[j],1,n,a[i]);
            if (vtmax!=0 && vtmin!=1002)
            {
                res+=vtmax-vtmin+1;
                if (int(sqrt(pow(a[i],2)+pow(b[j],2)))==sqrt(pow(a[i],2)+pow(b[j],2)))
                {
                    int q=finddel(c,int(sqrt(pow(a[i],2)+pow(b[j],2))),vtmin,vtmax);
                    res-=q;
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (int(sqrt(pow(b[i],2)+pow(c[j],2)))==sqrt(pow(b[i],2)+pow(c[j],2)))
            {
                int q=finddel(a,int(sqrt(pow(b[i],2)+pow(c[j],2))),1,n);
                res-=q;
            }
        }
    cout<<res;
    return 0;
}
