#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll a,b,x,y,n,c[maxn],f[50][maxn];
bool cmp(const int &a,const int &b)
{
        return a>b;
}
int main()
{
        freopen("799D.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>a>>b>>x>>y>>n;
        for (int i=1;i<=n;++i)
                cin>>c[i];
        sort(c+1,c+n+1,cmp);
        if (x>=a&&y>=b)
        {
                cout<<0;
                return 0;
        }
        f[0][x]=y;
        for (int i=0;i<=40;++i)
        for (ll w=1;w<maxn;++w)if (f[i][w])
        {
                if ((w>=a&&f[i][w]>=b)||(w>=b&&f[i][w]>=a))
                {
                        cout<<i;
                        return 0;
                }
                f[i+1][min(1LL*maxn-1,1LL*w*c[i+1])]=max(1LL*f[i][w],1LL*f[i+1][min(1LL*maxn,1LL*w*c[i+1])]);
                f[i+1][w]=max(1LL*f[i][w]*c[i+1],1LL*f[i+1][w]);
        }
        cout<<-1;
        return 0;
}
