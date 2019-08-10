#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        int x,y;
};
data a[maxn];
int n;
ll dt(data a,data b,data c)
{
        return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
}
int main()
{
        freopen("INSIDE.inp","r",stdin);
        //freopen("INSIDE.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].x>>a[i].y;
        int test;
        cin>>test;
        while(test--)
        {
                data p;
                cin>>p.x>>p.y;
                if (dt(a[1],p,a[2])>0)
                {
                        cout<<"Outside\n";
                        continue;
                }
                if (dt(a[1],p,a[n])<0)
                {
                        cout<<"Outside\n";
                        continue;
                }
                int l=2,r=n;
                while(r-l>1)
                {
                        int m=(l+r)>>1;
                        if (dt(a[1],p,a[m])>0)
                        {
                                r=m;
                        }
                        else l=m;
                }
                if (abs(dt(a[1],a[l],p))+abs(dt(a[1],a[r],p))+abs(dt(a[l],a[r],p))==abs(dt(a[1],a[l],a[r])))
                {
                        cout<<"Inside\n";
                }
                else cout<<"Outside\n";
        }

}
