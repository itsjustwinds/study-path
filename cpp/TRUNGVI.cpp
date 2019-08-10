#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int suml[2*maxn],sumc[2*maxn],n,a[maxn],sum[maxn],m,now;
long long res;
int main()
{
        freopen("D:\\c++\\TRUNGVI.inp","r",stdin);
        freopen("D:\\c++\\TRUNGVI.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        sumc[maxn]++;
        for (int i=1;i<=n;++i)
        {
                sum[i]=sum[i-1];
                if (a[i]>m) sum[i]++;
                if (a[i]<m) sum[i]--;
                if (a[i]==m) now=i;
                if (now) continue;
                if (i%2) suml[maxn+sum[i]]++;
                else sumc[maxn+sum[i]]++;
        }
        for (int i=now;i<=n;++i)
        {
                if (i%2) res+=sumc[maxn+sum[i]];
                else res+=suml[maxn+sum[i]];
        }
        cout<<res;
}
