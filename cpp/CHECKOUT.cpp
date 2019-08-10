#include<bits/stdc++.h>
#define db double
using namespace std;
db d,a2,a1,v,t,t1,t2,t3,esp,res;
bool check(db m)
{
        t1=m;
        t2=max((db)0,(d+a2*t3/2-a1*t1*t1/2)/v);
        if (t2>=t) {
                res=t1+t2+t3;
                        return 1;
        }
        return 0;
}
bool check2(db u)
{
        db tmp=0;
        tmp=u*u/(2*a1)+t*u+u*u/(2*a2);
        if (tmp<=d) return 1;
        return 0;
}
int main()
{
        freopen("CHECKOUT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>d>>a1>>a2>>v>>t;
        db l=0,r=15;
        esp=1e-8;
        t3=v/a2;
        res=-1;
        while(r-l>esp)
        {
                db m=(l+r)/2;
                if (check(m))
                {
                        l=m;
                }
                else r=m;
        }
        if (res!=-1)
        {
                cout<<fixed<<setprecision(12)<<res;
                return 0;
        }
        l=0,r=v;
        while(r-l>esp)
        {
                db m=(l+r)/2;
                if (check2(m))
                {
                        l=m;

                }
                else r=m;
        }
}
