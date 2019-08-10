#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define db double
using namespace std;
struct line
{
        ll a,b,r;
};
line st[4*maxn];
int n,test;
db val(line a,int x)
{
        db tmp=(db)(sqrt(-1ll*x*x+1ll*2*a.a*x-1ll*a.a*a.a+1ll*a.r*a.r));
        db tmp1=tmp+a.b;
        db tmp2=-tmp+a.b;
        return min(abs(tmp1),abs(tmp2));
}
void update(int id,int l,int r,int i,int j,line x)
{
        if (l>j||r<i) return;
        if (l>=i&&r<=j)
        {
                if (val(x,i))
        }
}
int main()
{
        freopen("VPHSTAR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>test;
        for (int i=1;i<=4*maxn;++i)
        {
                st[i].b=1e17;
        }
        for (int i=1;i<=n;++i)
        {
                int x,y,r;
                cin>>x>>y>>r;
                update(1,1,1e5,max(1,x-r),min(1e5,x+r),{x,y,r});
        }
}
