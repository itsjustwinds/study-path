#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod  123456789
using namespace std;
int n,k,l,r;
ll res;
int a[maxn];
int main()
{
        freopen("PRODUCT.inp","r",stdin);
        //freopen("PRODUCT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1);
        l=1,r=n;
        if (k%2)
        {
                res=a[n];
                r--;
        }
        else res=1;
        if (k%2) k--;
        while(k)
        {
                k-=2;
                if (a[l]*a[l+1]>a[r]*a[r-1])
                {
                        res=(1ll*res*a[l])%mod;
                        res=(1ll*res*a[l+1])%mod;
                        l+=2;
                }
                else
                {
                        res=(1ll*res*a[r])%mod;
                        res=(1ll*res*a[r-1])%mod;
                        r-=2;
                }
        }
        cout<<res;
        return 0;
}
