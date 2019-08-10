#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d,x,y,r;
void GCD(ll a,ll b)
{
        ll xa=1,ya=0;
        ll xb=0,yb=1;
        ll r,xr,yr;
        ll p;
        while(b)
        {
                p=a/b;
                r=a-p*b;a=b;b=r;
                xr=xa-p*xb;xa=xb;xb=xr;
                yr=ya-p*yb;ya=yb;yb=yr;
        }
        d=a;
        x=xa;
        y=ya;
}
int main()
{
        freopen("7C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>a>>b>>c;
        GCD(a,b);
        c=-c;
        if (c%d)
        {
                cout<<-1;
                return 0;
        }
        x*=c/d;
        y*=c/d;
        cout<<x<<" "<<y;
        return 0;
}
