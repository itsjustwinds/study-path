#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int n;
ll a[maxn],dem,b[maxn],k,c[maxn];
ll __gcd(ll a, ll b)
{
        if (b==0) return a;
        return __gcd(b,a%b);
}
void pt(ll k)
{
        for (int i=2; (ll)i*i<=k; ++i)
                if (k%i==0)
                {
                        b[++dem]=1;
                        while(k%i==0)
                        {
                                b[dem]*=i;
                                k/=i;
                        }
                }
        if (k>1) b[++dem]=k;
        if (dem==0) b[++dem]=1;
}
int main()
{
        freopen("CRYPTKEY.inp","r",stdin);
        freopen("CRYPTKEY.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                for (int i=1; i<=n; ++i)
                        cin>>a[i];
                cin>>k;
                dem=0;
                pt(k);
                int ok=1;
                for (int j=1; j<=dem; ++j)
                {
                        c[j]=0;
                        for (int i=1; i<=n; ++i)
                                if (a[i]%b[j]==0)
                                {
                                        c[j]=__gcd(a[i],c[j]);
                                }
                        if (c[j]==0||k%c[j]!=0)
                        {
                                ok=0;
                                break;
                        }
                }
                if (ok) cout<<"YES\n";
                else cout<<"NO\n";
        }
}
