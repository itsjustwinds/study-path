#include<bits/stdc++.h>
#define maxn 3005
#define db double
#define ll long long
using namespace std;
struct data
{
        int x,y;
};
data a[maxn];
int n;
double res;
vector<data > up,down,CVH;
double dt(data a,data b,data c)
{
        double res=1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
        if (res<0) res=-res;
        res/=2;
        return res;
}
bool cmp(data a,data b)
{
        if (a.y!=b.y) return a.y<b.y;
        return a.x<b.x;
}
ll ccw(data a,data b,data c)
{
        return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
}
bool operator !=(data a,data b)
{
        return a.x!=b.x||a.y!=b.y;
}
int main()
{
        freopen("TRILAND.inp","r",stdin);
        freopen("TRILAND.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].x>>a[i].y;
        sort(a+1,a+n+1,cmp);
        if (n<=500)
        {
                for (int k=n;k>=1;--k)
                for (int i=1;i<k;++i)
                for (int j=1;j<i;++j)
                res=max(res,dt(a[k],a[i],a[j]));
                cout<<fixed<<setprecision(1)<<res;
                return 0;
        }
        data p1=a[1];
        data pn=a[n];
        up.push_back(p1);
        down.push_back(p1);
        for (int i=2;i<=n;++i)
        {
                if (i==n||ccw(p1,a[i],pn)<0)
                {
                        while(up.size()>=2&&ccw(up[up.size()-2],up[up.size()-1],a[i])>=0)
                                up.pop_back();
                        up.push_back(a[i]);
                }
                if (i==n||ccw(p1,a[i],pn)>0)
                {
                        while(down.size()>=2&&ccw(down[down.size()-2],down[down.size()-1],a[i])<=0)
                                down.pop_back();
                        down.push_back(a[i]);
                }
        }
        for (int i=1;i<up.size()-1;++i)
                CVH.push_back(up[i]);
        for (int j=down.size()-1;j>=0;--j)
                CVH.push_back(down[j]);
        n=CVH.size();
        for (int i=0;i<n;++i)
                CVH.push_back(CVH[i]);
        for (int i=0;i<n;++i)
        {
                int now=i+1;
                db dientich=0;
                for (int j=i+1;j<=i+n-1;++j)
                {
                        while(a[now+1]!=a[i]&&dt(CVH[i],CVH[j],CVH[now+1])>dientich)
                        {
                                ++now;
                                dientich=dt(CVH[i],CVH[j],CVH[now]);
                        }
                        res=max(res,dientich);
                }
        }
        cout<<setprecision(1)<<fixed<<res;
}
