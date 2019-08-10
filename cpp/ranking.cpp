#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
int a[32677],n,m,bit[1000001],ranking[32677];
int get(int u)
{
    int res=0;
    while (u)
    {
        res+=bit[u];
        u-=u&(-u);
    }
    return res;
}
void update(int u,int val)
{
    while (u<=maxn)
    {
        bit[u]+=val;
        u+=u&(-u);
    }
}
int main()
{
    freopen("ranking.inp","r",stdin);
    //freopen("ranking.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        ranking[i]=i-get(a[i]-1);
        update(a[i],1);
    }
    for (int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        cout<<ranking[x]<<"\n";
    }
    return 0;
}
