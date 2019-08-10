#include <bits/stdc++.h>
using namespace std;
int a[4],b[4];
double pow(double a,double b)
{
    double res=1;
    for (int i=1; i<=b; i++)
        res*=a;
    return res;
}
int main()
{
    freopen("formular.inp","r",stdin);
    freopen("formular.out","w",stdout);
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double r,rtinh;
    for (int i=1; i<=3; i++)
        cin>>a[i]>>b[i];
    cin>>r;
    double c[4];
    for (int i=2; i<=3; i++)
    {
        c[i]=sqrt(pow(a[i]-a[i-1],2)+pow(b[i]-b[i-1],2));
    }
    c[1]=sqrt(pow(a[1]-a[3],2)+pow(b[1]-b[3],2));
    double tmp;
    tmp=(1/4)*sqrt(4*pow(c[1],2)*pow(c[2],2)-pow((pow(c[1],2)+pow(c[2],2)-pow(c[3],2)),2));
    rtinh=tmp/((c[1]+c[2]+c[3])/2);
    double rtmp=(r-rtinh)/rtinh;
    if (rtmp==0) cout<<0;
    if (rtmp>0) cout<<fixed<<setprecision(3)<<"+"<<rtmp;
    if (rtmp<0) cout<<fixed<<setprecision(3)<<"-"<<rtmp;
    return 0;
}
