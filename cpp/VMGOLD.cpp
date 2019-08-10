#include<bits/stdc++.h>
#define maxn 3005
#define ll long long
#define fs first
#define sc second
using namespace std;
int n,k;
map<ll,int> m;
map<ll,int> ::iterator it;
ll res;
void tinh(ll n)
{
        it=m.find(n);
        if (it==m.end())
        {
                m[n]=1;
                return;
        }
        int s=it->sc;
        m[n]=s+1;
        if (s+1==k)
                res=max(res,n);
}
void solve(ll n)
{
        for (int i=1;(ll)i*i<=n;++i)
        if (n%i==0)
        {
                tinh(i);
                ll tmp=n/i;
                if (tmp==i) continue;
                tinh(tmp);
        }
}
int main()
{
        freopen("VMGOLD.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        res=1;
        for (int i=1;i<=n;++i)
        {
                ll x;
                cin>>x;
                solve(x);
        }
        cout<<res;
        return 0;
}
