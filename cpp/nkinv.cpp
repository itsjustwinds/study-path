#include <bits/stdc++.h>
using namespace std;
int bit[60001],a[60001],n;
long long res;
int get(int u)
{
    int kq=0;
    while(u)
    {
        kq+=bit[u];
        u-=u&(-u);
    }
    return kq;
}
void update(int u,int val)
{
    while (u<=60000)
    {
        bit[u]+=val;
        u+=u&(-u);
    }
}
int main()
{
    freopen("nkinv.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>0;i--)
    {
        res+=get(a[i]-1);
        update(a[i],1);
    }
    cout<<res;
    return 0;
}
