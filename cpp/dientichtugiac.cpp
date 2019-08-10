#include <bits/stdc++.h>
using namespace std;
int toadox[1000000],toadoy[1000000];
float dientich(int n)
{
    int i;
    float kq;
    kq=0;
    toadox[n+1]=toadox[1];
    toadoy[n+1]=toadoy[1];
    for (i=2;i<=n+1;i++)
        kq=kq+(toadox[i]-toadox[i-1])*(toadoy[i]+toadoy[i-1]);
    return abs(kq)/2;
}
int main()
{
    freopen("dientichtugiac.inp","r",stdin);
    freopen("dientichtugiac.out","w",stdout);
    std::ios_base::sync_with_stdio;
    int x,y,i,n;
    float s;
    n=3;
    for (i=1;i<=n;i++)
    {
        cin>>x>>y;
        toadox[i]=x;
        toadoy[i]=y;
    }
    s=dientich(n);
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
