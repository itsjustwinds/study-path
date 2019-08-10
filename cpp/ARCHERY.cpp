#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
struct data
{
        int x,y;
};
data a[maxn],ZERO;
int n,dd[20];
ll dis(data a)
{
        return a.x*a.x+a.y*a.y;
}
bool operator ==(data a,data b)
{
        return a.x==b.x&&a.y==b.y;
}
int main()
{
        freopen("ARCHERY.inp","r",stdin);
        freopen("ARCHERY.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        int t=0;
        for (int i=1;i<=10;++i)
        {
                t+=20;
                dd[i]=t*t;
        }
        cin>>test;
        while(test--)
        {
                cin>>n;
                for (int i=1;i<=n;++i)
                        cin>>a[i].x>>a[i].y;
                ll res=0;
                for (int i=1;i<=n;++i)
                {
                        ll x=dis(a[i]);
                        int tmp=0;
                        for (int j=1;j<=10;++j)
                        if (x<=dd[j]&&tmp==0) tmp=11-j;
                        res+=tmp;
                }
                cout<<res<<"\n";
        }
        return 0;
}
