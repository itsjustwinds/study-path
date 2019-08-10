#include<bits/stdc++.h>
using namespace std;
double a[1000];
int n;
int main()
{
    freopen("under.inp","r",stdin);
    freopen("under.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for (int l=1;l<=test;l++)
    {
        cin>>n;
        for (int i=1;i<=2*n;i++)
            cin>>a[i];
        sort(a+1,a+2*n+1);
        double res=1;
        for (int i=1;i<=n;i++)
        {
            double tmp=a[i]*a[2*n-i+1];
            if (tmp!=0) res*=(1-tmp);
        }
        cout<<"Case #"<<l<<": ";
        cout<<fixed<<setprecision(6)<<res<<"\n";
    }
    return 0;
}
