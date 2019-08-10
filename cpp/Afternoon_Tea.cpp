
#include<bits/stdc++.h>
#define maxn 100005
#define db long double
#define ll long long
using namespace std;
ll n;
char s[maxn];
db t,m;
db resT,resM,one;
int main()
{
        freopen("Afternoon_Tea.inp","r",stdin);
        //ios::sync_with_stdio(0);
        //cin.tie(0);
        //cout.tie(0);
        cin>>n;
        cin>>(s+1);
        db esp=1e-20;
        one =1.00000000000000000000;
        t=0.50000000000000000000;
        m=0.50000000000000000000;
        resT=0.00000000000000000000;
        resM=0.00000000000000000000;
        for (int i=1;i<=n;++i)
        {
                resT=resT+t/2;
                resM=resM+m/2;
                if (s[i]=='H')
                {
                        t/=2;
                        m/=2;
                        db tmp=t+m;
                        tmp=one-tmp;
                        t=t+tmp;
                }
                else
                {
                        t/=2;
                        m/=2;
                        db tmp=t+m;
                        tmp=one-tmp;
                        m=m+tmp;
                }
        }
        //cout<<fixed<<setprecision(20)<<resT<<"\n";
        //cout<<fixed<<setprecision(20)<<resM<<"\n";
        //cout<<fixed<<setprecision(20)<<resT-resM<<"\n";
        //cout<<fixed<<setprecision(20)<<resM-resT<<"\n";
        if (resT-resM>=(db)0.00000000000000000000)
        {
                cout<<"H";
        }
        if (resM-resT>=(db)0.00000000000000000000)
        {
                cout<<"M";
        }
        return 0;
}
