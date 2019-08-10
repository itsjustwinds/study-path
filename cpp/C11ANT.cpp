#include<bits/stdc++.h>
#define maxn 100005
#define db double
using namespace std;
int a[maxn],v[maxn],n;
db tinh(db t)
{
        db minn=(db)a[1]+(db)t*v[1];
        db maxx=(db)a[1]+(db)t*v[1];
        for (int i=2;i<=n;++i)
        {
                minn=min(minn,(db)a[i]+(db)t*v[i]);
                maxx=max(maxx,(db)a[i]+(db)t*v[i]);
        }
        return (db)(maxx-minn)/2;
}
int main()
{
        freopen("C11ANT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
                cin>>v[i];
        db l=0;
        db r=1e10;
        db esp=1e-15;
        while(r-l>esp)
        {
                db m1=l+(db)4*(r-l)/9;
                db m2=r-(db)4*(r-l)/9;
                db c1=tinh(m1);
                db c2=tinh(m2);
                if (c1>c2) l=m1;
                else r=m2;
        }
        db res=tinh(l);
        cout<<fixed<<setprecision(3)<<res;
        return 0;
}
