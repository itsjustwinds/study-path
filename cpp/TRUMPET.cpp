#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int now,n,a[maxn],d;
int main()
{
        freopen("TRUMPET.inp","r",stdin);
        freopen("TRUMPET.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>d;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        now=1;
        int res=0;
        int tmp=1;
        while(now<n)
        {
                int trc=now;
                for (;tmp<=trc+d;++tmp)
                if (a[tmp]==1) now=tmp;
                if (now==trc)
                {
                        ++res;
                        now+=d;
                }
        }
        cout<<res;
        return 0;
}
