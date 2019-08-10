#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
struct data
{
        ll x,x1,x2,y,id;
};
data a[maxn];
ll n,r,c,res[maxn];
vector<data > line;
bool cmp(data a,data b)
{
        return a.y<b.y;
}
int main()
{
        freopen("GARDEN.inp","r",stdin);
        freopen("GARDEN.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>r>>c>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].y;
                a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                ll le=0;
                for (int j=0;j<line.size();++j)
                {
                        ll x1=line[j].x1;
                        ll x2=line[j].x2;
                        if (a[i].x>x2||a[i].x<x1) continue;
                        le=max(le,line[j].y);
                }
                ll R=a[i].y-le;
                res[a[i].id]=2*R;
                ll x1=a[i].x-R;
                ll x2=a[i].x+R;
                ll y=a[i].y+R;
                line.push_back({0,x1,x2,y,0});
        }
        for (int i=1;i<=n;++i)
                cout<<res[i]<<"\n";
}
