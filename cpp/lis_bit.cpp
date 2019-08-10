#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
int a[maxn],ac[maxn],n,bit[maxn];
int get(int u)
{
    int kq=0;
    while(u)
    {
        kq=max(kq,bit[u]);
        u-=u&(-u);
    }
    return kq;
}
void update(int u,int val)
{
    while(u<=maxn)
    {
        bit[u]=max(val,bit[u]);
        u+=u&(-u);
    }
}
int main()
{
    freopen("lis.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        ac[i]=a[i];
    sort(ac+1,ac+n+1);
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;
    for (int i=1;i<=n;i++)
    {
        int tmp=get(a[i]-1);
        update(a[i],tmp+1);
    }
    int tmp=get(n);
    cout<<tmp;
    return 0;
}
