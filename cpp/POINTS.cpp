#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],b[maxn],n,m,ac[2*maxn],dem,bit[2*maxn];
long long res;
void update(int u)
{
        while(u<=2*maxn)
        {
                bit[u]++;
                u+=u&(-u);
        }
}
void get(int u)
{
        while(u)
        {
                res+=bit[u];
                u-=u&(-u);
        }
}
int main()
{
        freopen("POINTS.inp","r",stdin);
        freopen("POINTS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                ac[++dem]=a[i];
        }
        for (int i=1;i<=m;++i)
        {
                cin>>b[i];
                ac[++dem]=b[i];
        }
        sort(ac+1,ac+dem+1);
        for (int i=1;i<=n;++i)
                a[i]=lower_bound(ac+1,ac+dem+1,a[i])-ac;
        for (int i=1;i<=m;++i)
                b[i]=lower_bound(ac+1,ac+dem+1,b[i])-ac;
        for (int i=1;i<=m;++i)
        {
                update(b[i]);
        }
        for (int i=1;i<=n;++i)
                get(a[i]-1);
        cout<<res;
        return 0;
}
