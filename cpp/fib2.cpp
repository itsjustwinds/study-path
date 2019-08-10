#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
ll ck,f[maxn],n,mod;
ll a,b;
ll power(ll n)
{
        if (n==0) return 1;
        if (n==1) return a%ck;
        ll tmp=power(n>>1);
        tmp=(tmp*tmp)%ck;
        if (n%2) tmp=(tmp*a)%ck;
        return tmp;
}
int main()
{
        freopen("FIB2.inp","r",stdin);
        freopen("FIB2.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>a>>b>>mod;
                f[0]=0;
                f[1]=1%mod;
                ck=2;
                while(1)
                {
                        f[ck]=(f[ck-1]+f[ck-2])%mod;
                        ++ck;
                        if (f[0]==f[ck-2]&&f[1]==f[ck-1])
                        {
                                ck-=2;
                                break;
                        }
                }
                cout<<f[power(b)]<<"\n";
        }
        return 0;
}
