#include<bits/stdc++.h>
#define maxn 1000005
#define db double
using namespace std;
db f[maxn],R;
int l,h,res;
int main()
{
        freopen("NTRIVIAL.inp","r",stdin);
        freopen("NTRIVIAL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>l>>h;
        for (int i=2;i*i<=h;++i)
        {
                f[i*i]+=i;
                for (int j=i+1;j<=h/i;++j)
                {
                        f[i*j]+=i+j;
                }
        }
        R=1e18;
        if (l==1)
        {
                cout<<l;
                return 0;
        }
        for (int i=l;i<=h;++i)
        {
                f[i]++;
                if (((db)f[i]/i)<R)
                {
                        res=i;
                        R=(db)f[i]/i;
                }
        }
        cout<<res;
        return 0;
}
