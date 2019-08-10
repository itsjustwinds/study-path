#include<bits/stdc++.h>
#define maxn 10005
#define fs first
#define mod 1000000000
#define sc second
using namespace std;
typedef pair<int,int> II;
II a[maxn];
int bit[maxn][20],n,k;
long long res;
void update(int u,int h,int val)
{
    while(u<=n)
    {
        bit[u][h]=(bit[u][h]+val)%mod;
        u+=u&(-u);
    }
}
int get(int u,int h)
{
    int kq=0;
    while(u)
    {
        kq=(kq+bit[u][h])%mod;
        u-=u&(-u);
    }
    return kq;
}
int main()
{
    freopen("kinv.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        a[i].sc=i;
        cin>>a[i].fs;
    }
    sort(a+1,a+n+1);
    for (int i=n;i>0;i--)
    {
        update(a[i].sc,1,1);
        for (int j=2;j<=k-1;j++)
        {
            int tmp=get(a[i].sc-1,j-1);
            update(a[i].sc,j,tmp);
        }
        int tmp=get(a[i].sc-1,k-1);
        res=(res+tmp)%mod;
        update(a[i].sc,k,tmp);
    }
    cout<<res;
    return 0;
}
