#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
using namespace std;
int a[maxn],n,d;
ll sum[maxn],res;
int main()
{
        freopen("446C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                sum[i]=sum[i-1]+a[i];
        }
        if (sum[n]%3||n<=2)
        {
                cout<<0;
                return 0;
        }
        ll tmp2=(sum[n]/3)*2;
        ll tmp1=sum[n]/3;
        for (int i=1;i<n;++i)
                if (sum[i]==tmp2)++d;
        int j=1;
        for (int i=1;i<=n-2;++i)
        if (sum[i]==tmp1)
        {
                while(j<=i)
                {
                        if (sum[j]==tmp2) d--;
                        j++;
                }
                res+=d;
        }
        cout<<res;
        return 0;
}
