#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        ll x,y;
};
data a[maxn];
int n;
vector<data > up,down;
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
ll ccw(data a,data b,data c)
{
        return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
}
bool operator < (data a,data b)
{
        if (a.y!=b.y) return a.y<b.y;
        return a.x<b.x;
}
vector<data >CVH;
ll tinh(vector<data >a)
{
        ll res=0;
        a.push_back(a[0]);
        for (int i=0;i<a.size()-1;++i)
                res+=1ll*(a[i+1].x-a[i].x)*(a[i+1].y+a[i].y);
        if(res<0) res=-res;
        return res;
}
int main()
{
        freopen("CONVEXHULL.inp","r",stdin);
        freopen("CONVEXHULL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].x>>a[i].y;
        sort(a+1,a+n+1,cmp);
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
        reverse(CVH.begin(),CVH.end());
        ll maxx=1e9+7;
        data minn={maxx,maxx};
        int pos=0;
        for (int i=0;i<CVH.size();++i)
        {
                if (CVH[i]<minn)
                {
                        minn=CVH[i];
                        pos=i;
                }
        }
        for (int i=0;i<pos;++i)
        {
                CVH.push_back(CVH[0]);
                CVH.erase(CVH.begin());
        }
        cout<<CVH.size()<<"\n";
        ll dt=tinh(CVH);
        cout<<dt/2;
        if (dt%2!=0) cout<<".5\n";
        else cout<<".0\n";
        for (int i=0;i<CVH.size();++i)
                cout<<CVH[i].x<<" "<<CVH[i].y<<"\n";
        return 0;
}
