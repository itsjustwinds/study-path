#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll f[maxn][20],n,a[20],k,maxx;
int get(int x,int i)
{
        return (x>>(i-1))&1;
}
int setbit(int x,int i)
{
        return x^(1<<(i-1));
}
int main()
{
        freopen("MIXUP2.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        maxx=(1<<n)-1;
        for (int i=1;i<=n;++i)
                f[1<<(i-1)][i]=1;
        for (int x=3;x<=maxx;++x)
        {
                for (int i=1;i<=n;++i)
                {
                        if (!get(x,i)) continue;
                        int y=setbit(x,i);
                        for (int j=1;j<=n;++j)
                        {
                                if (!get(y,j)) continue;
                                if (abs(a[i]-a[j])<=k) continue;
                                f[x][i]+=f[y][j];
                        }
                }
        }
        ll res=0;
        for (int i=1;i<=n;++i)
                res+=f[maxx][i];
        cout<<res;
        return 0;
}
