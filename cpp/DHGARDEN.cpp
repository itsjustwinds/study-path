#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
struct data
{
        int x,y;
};
int n,r,ans;
db d,cv;
data a[50];
typedef vector<data > II;
II ZERO;
int cw(data a,data b,data c)
{
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
db dis(data a,data b)
{
        db dxa=a.x-b.x;
        db dxb=a.y-b.y;
        return (db)sqrt(dxa*dxa+dxb*dxb);
}
void check(II a)
{
        if (a.size()==0) return;
        vector<data > up,down;
        up.clear();
        down.clear();
        data p1=a[0];
        data pn=a[a.size()-1];
        up.push_back(p1);
        down.push_back(p1);
        for (int i=1; i<a.size(); ++i)
        {
                if (i==a.size()-1||cw(p1,a[i],pn)<=0)
                {
                        while(up.size()>1&&cw(up[up.size()-2],up[up.size()-1],a[i])>0)
                                up.pop_back();
                        up.push_back(a[i]);
                }
                if (i==a.size()-1||cw(p1,a[i],pn)>=0)
                {
                        while(down.size()>1&&cw(down[down.size()-2],down[down.size()-1],a[i])<0)
                                down.pop_back();
                        down.push_back(a[i]);
                }
        }
        vector<data >res;
        res.clear();
        for (int i=0;i<up.size();++i)
                res.push_back(up[i]);
        for (int i=down.size()-2;i>0;--i)
                res.push_back(down[i]);
        db tmp=0;
        res.push_back(p1);
        for (int i=0;i<res.size()-1;++i)
                tmp=tmp+dis(res[i],res[i+1]);
        if (tmp+cv<=d)
        {
                int x=a.size();
                ans=max(ans,x);
        }
}
void dfs(int i,II vx)
{
        if (i==n+1)
        {
                check(vx);
                return;
        }
        dfs(i+1,vx);
        vx.push_back(a[i]);
        dfs(i+1,vx);
}
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
int main()
{
        freopen("DHGARDEN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>d>>n>>r;
                for (int i=1; i<=n; ++i)
                        cin>>a[i].x>>a[i].y;
                sort(a+1,a+n+1,cmp);
                cv=(db)2*r*3.1416;
                ans=0;
                dfs(1,ZERO);
                cout<<ans<<"\n";
        }
}
