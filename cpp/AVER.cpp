#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int a[maxn],n,k;
int res;
bool check(int m)
{
        ll sum=0;
        for (int i=1;i<=m;++i)
                sum+=a[i];
        if (sum/m>=k) return 1;
        for (int i=m+1;i<=n;++i)
        {
                sum-=a[i-m];
                sum+=a[i];
                if (sum/m>=k) return 1;
        }
        return 0;
}
int main()
{
        freopen("AVER.inp","r",stdin);
        freopen("AVER.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=n;i>=1;--i)
        {
                if (check(i))
                {res=i;
                        break;
                }
        }
        cout<<res;
}
