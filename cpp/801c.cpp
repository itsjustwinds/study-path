#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn],n,p;
double res,s;
int check(double m)
{
    double tmp=0;
    for (int i=1;i<=n;i++)
        tmp+=max(a[i]*m-b[i],double(0));
    if (tmp<(double)m*p) return 1;
    return 0;
}
int main()
{
    freopen("801c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        s+=a[i];
    }
    if (s<=p)
    {
        cout<<-1;
        return 0;
    }
    res=0;
    double l=0,r=1e14;
    while(r-l>=1e-4)
    {
        double m=(l+r)/2;
        if (check(m))
        {
            res=m;
            l=m;
        }
        else r=m;
    }
    cout<<fixed<<setprecision(10)<<res;
    return 0;
}
