#include <bits/stdc++.h>
#define maxn 10005
#define maxk 15
#define fs first
#define sc second
#define mod 1000000000
using namespace std;
typedef pair <int,int> II;
II ac[maxn];
int n,a[maxn],bit[maxn][maxk],k,f[maxn][maxk];
long long res;
int get(int u,int h)
{
    int kq=0;
    while (u)
    {
        kq=(kq+bit[u][h])% mod;
        u-=u&(-u);
    }
    return kq;
}
void update(int u,int h,int val)
{
    while (u<=maxn)
    {
        bit[u][h]=(bit[u][h]+val)% mod;
        u+=u&(-u);
    }
}
int main()
{
    //freopen("kinv.inp","r",stdin);
    //freopen("kinv.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>ac[i].fs;
        ac[i].sc=i;
    }
    sort(ac+1,ac+n+1);
    int u=0;
    for (int i=1;i<=n;i++)
    {
        if (ac[i].fs!=ac[i-1].fs)
            u++;
        a[ac[i].sc]=u;
    }
    for (int i=n;i>0;i--)
    {
        f[i][1]=1;
        update(a[i],1,1);
        for (int j=2;j<=k;j++)
        {
            f[i][j]=get(a[i]-1,j-1);
            update(a[i],j,f[i][j]);
        }
        res=(res+f[i][k])% mod;
    }
    cout<<res;
    return 0;
}
