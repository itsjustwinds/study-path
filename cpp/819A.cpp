#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int a[maxn];
int n,res,cnt;
int main()
{
        //freopen("819A.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                if (a[i]==1) ++cnt;
        }
        if (cnt)
        {
                cout<<n-cnt;
                return 0;
        }
        int minn=1e9;
        for (int i=1;i<=n;++i)
        {
                int now=a[i];
                for (int j=i+1;j<=n;++j)
                {
                        now=__gcd(now,a[j]);
                        if (now==1)
                        {
                                minn=min(minn,j-i);
                                break;
                        }
                }
        }
        if (minn==1e9) cout<<-1;
        else cout<<minn+n-1;
        return 0;
}
