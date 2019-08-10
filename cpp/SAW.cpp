#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
        double x,y;
};
data yy,xx;
vector<data > h,a,CVH;
int n,k;
double res;
double ccw(data a,data b,data c)
{
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
double tinh(data u1,data u2)
{
        double y1=u1.y,y2=u2.y;
        double x1=u1.x,x2=u2.x;
        double b=y1*(x2/x1)-y2;
        double a=(y1-b)/x1;
        data p1={0,b};
        data p2={-b/a,0};
        double res=p1.y*p2.x;
        if (res<0) res=-res;
        return res;
}
void read(int &n)
{
        n=0;
        char c=getchar();
        int neg=0;
        if (c=='-')
        {
                neg=1;
                c=getchar();
        }
        for (;c>='0'&&c<='9';c=getchar())
        {
                n=n*10+(c-'0');
        }
        if (neg) n*=-1;
}
int main()
{
        freopen("SAW.inp","r",stdin);
        freopen("SAW.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        read(k);
        yy.x=0,yy.y=1e9+7;
        xx.x=1e9+7,xx.y=0;
        for (int i=1;i<=k;++i)
        {
                read(n);
                for (int j=0;j<=n;++j)
                {
                        int x,y;
                        read(x);
                        read(y);
                        x=abs(x);
                        y=abs(y);
                        h.push_back({(double)x,(double)y});
                        if (x==0)
                        {
                                if (y<yy.y) yy.y=y;
                        }
                        if (y==0)
                        {
                                if (x<xx.x) xx.x=x;
                        }
                }
        }
        for (int i=0;i<h.size();++i)
        {
                if (ccw(yy,h[i],xx)<=0) continue;
                a.push_back(h[i]);
        }
        sort(a.begin(),a.end(),cmp);
        a.push_back(xx);
        CVH.push_back(yy);
        for (int i=0;i<a.size();++i)
        {
                while(CVH.size()>=2&&ccw(CVH[CVH.size()-2],CVH[CVH.size()-1],a[i])<=0)
                        CVH.pop_back();
                CVH.push_back(a[i]);
        }
        for (int i=0;i<CVH.size()-1;++i)
        {
                res=max(res,tinh(CVH[i],CVH[i+1]));
        }
        cout<<setprecision(6)<<fixed<<res;
}
