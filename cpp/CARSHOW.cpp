#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
multiset<ll> s;
multiset<ll> :: iterator it;
int a[maxn],v[maxn],n,t;
int main()
{
        //freopen("CARSHOW.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>t;
        for (int i=1;i<=n;++i)
                cin>>a[i]>>v[i];
        s.insert(a[n]+t*v[n]);
        for (int i=n-1;i>=1;--i)
        {
                it=s.upper_bound(a[i]+t*v[i]);
                if(it!=s.end())
                {
                        s.erase(it);
                }
                s.insert(a[i]+t*v[i]);
        }
        cout<<s.size();
        return 0;
}
