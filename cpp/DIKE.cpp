#include<bits/stdc++.h>
using namespace std;
int k;
long long n;
bool check(int k)
{
        return (1ll*k*(k+1)*(k+5)/6-1)<=n;
}
int main()
{
        //freopen("DIKE.inp","r",stdin);
        //freopen("DIKE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        int l=1,r=2e6;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        l=m+1;
                        k=m;
                }
                else r=m-1;
        }
        cout<<k;
        return 0;
}
