#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
using namespace std;
typedef pair<ll,ll> II;
typedef pair<ll,II> III;
ll n,w[500],f[500][500],dem,root[500],h[500],res,trace[500];
III e[500*500];
int ok;
ll get(ll u)
{
    while (root[u]!=u) u=root[u];
    return u;
}
void unionn(ll ru,ll rv)
{
    if (h[ru]>h[rv])
    {
        root[rv]=ru;
    }
    else
    {
        root[ru]=rv;
        h[rv]=max(h[ru]+1,h[rv]);
    }
}
int main()
{
    freopen("fwater.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            ll x;
            cin>>x;
            e[++dem]=III(x,II(0,i));
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            ll x;
            cin>>x;
            f[i][j]=x;
            if (i!=j)
            {
                e[++dem]=III(x,II(i,j));
            }
        }
    sort(e+1,e+dem+1);
    for (int i=0; i<=n; i++)
        root[i]=i;
    for (int i=0; i<=n; i++)
        h[i]=1;
    int i=0,j=1;;
    while(i<n)
    {
        ll u=e[j].sc.fs,v=e[j].sc.sc;
        ll s=e[j].fs;
        ll ru=get(u);
        ll rv=get(v);
        if (ru!=rv)
        {
            unionn(ru,rv);
            res+=s;
            i++;
        }
        j++;
    }
    cout<<res;
    return 0;
}
