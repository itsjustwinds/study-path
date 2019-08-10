#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100005
#define ll long long
using namespace std;
vector<int> e[maxn];
int a[maxn],bit[maxn],n,maxx,bit2[maxn];
int get(int u)
{
    int kq=0;
    while(u)
    {
        kq=(kq+bit[u])%mod;
        u-=u&(-u);
    }
    return kq;
}
void update(int u,int val)
{
    while(u<=maxx)
    {
        bit[u]=(bit[u]+val)%mod;
        u+=u&(-u);
    }
}
int dmcd(int u)
{
    int kq=0;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        update2(v,bit[v]);
        bit[v]=bit2[v];
    }
    return kq;
}
int main()
{
    freopen("803e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    for (int i=2;i*i<=maxx;i++)
    {
        e[i*i].push_back(i);
        for (int j=i+1;j<=maxx/i;j++)
        {
            e[i*j].push_back(i);
            e[i*j].push_back(j);
        }
    }
    for (int i=1;i<=n;i++)
    {
        bit[a[i]]++;
        int tmp=get(a[i]-1);
        tmp=((ll)tmp+mod-dmcd(a[i]))%mod;
        update(1,tmp);
    }
    cout<<get(1);
    return 0;
}
