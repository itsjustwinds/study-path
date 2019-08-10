#include<bits/stdc++.h>
#define maxn 100005
#define db double
using namespace std;
struct data
{
        db x,y,val;
};
data a[maxn],X;
int n;
db res;
db dis(data a,data b)
{
        db dx=a.x-b.x;
        db dy=a.y-b.y;
        return (db)sqrt((db)dx*dx+(db)dy*dy);
}
bool cmp(const data &a,const data &b)
{
        return a.val<b.val;
}
int main()
{
        freopen("NEAREST.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        res=1e18;
        X= {-1e8,-1e8};
        for (int i=1; i<=n; ++i)
        {
                cin>>a[i].x>>a[i].y;
                X={max(X.x,a[i].x),max(X.y,a[i].y)};
        }
        X.x++;
        X.y++;
        for (int i=1;i<=n;++i)
        {
                a[i].val=dis(a[i],X);
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                if (i!=1)
                {
                        res=min(res,dis(a[i],a[i-1]));
                }
                for (int j=i+1;j<=min(n,i+20);++j)
                {
                        res=min(res,dis(a[i],a[j]));
                }
        }
        cout<<fixed<<setprecision(3)<<res;
        return 0;
}
