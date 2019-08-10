#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
int a[2*maxn],n,maxx;
ll k;
int main()
{
        //freopen("879B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                maxx=max(maxx,a[i]);
        }
        if (k>=n-1)
        {
                cout<<maxx;
                return 0;
        }
        for (int i=1;i<=n;++i)
                a[i+n]=a[i];
        for (int i=1;i<=n;++i)
        {
                int ok=1;
                for (int j=i+1;j<=i+k;++j)
                if (a[i]<a[j]) ok=0;
                if (ok)
                {
                        cout<<a[i];
                        return 0;
                }
        }
        return 0;
}
