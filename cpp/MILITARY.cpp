#include<bits/stdc++.h>
#define maxn 4005
using namespace std;
struct pnt
{
        int x,y,pos;
};
pnt a[maxn];
int dd[maxn],n,res,dem;
bool cmp(pnt a,pnt b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
int ccw(pnt a,pnt b,pnt c)
{
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
int main()
{
        freopen("MILITARY.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].y;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
                a[i].pos=i;
        dem=n;
        while(dem>=3)
        {
                vector<pnt >h;
                h.clear();
                for (int i=1;i<=n;++i)
                if (!dd[i]) h.push_back(a[i]);
                vector<pnt > up,down;
                up.clear();
                down.clear();
                pnt p1=h[0];
                pnt p2=h.back();
                up.push_back(p1);
                down.push_back(p1);
                for (int i=1;i<h.size();++i)
                {
                        if (i==h.size()-1||ccw(p1,h[i],p2)<=0)
                        {
                                while(up.size()>=2&&ccw(up[up.size()-2],up[up.size()-1],h[i])>0)
                                        up.pop_back();
                                up.push_back(h[i]);
                        }
                        if (i==h.size()-1||ccw(p1,h[i],p2)>=0)
                        {
                                while(down.size()>=2&&ccw(down[down.size()-2],down[down.size()-1],h[i])<0)
                                        down.pop_back();
                                down.push_back(h[i]);
                        }
                }
                vector<pnt> ans;
                ans.clear();
                int cnt=0;
                for (int i=0;i<up.size();++i)
                {
                        ans.push_back(up[i]);
                        dd[up[i].pos]=1;
                        ++cnt;
                }
                for (int i=down.size()-2;i>0;--i)
                {
                        ans.push_back(down[i]);
                        dd[down[i].pos]=1;
                        ++cnt;
                }
                if (cnt<=2) break;
                ++res;
                dem-=cnt;
        }
        cout<<res;
        return 0;
}
