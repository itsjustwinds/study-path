#include<bits/stdc++.h>
#define maxn 1000005
#define fs first
#define ll long long
#define sc second
using namespace std;
ll bit[maxn],n,a[maxn],dem,now,m,ans[maxn];
typedef pair<ll,ll> II;
II ac[2*maxn],b[maxn];
bool cmp(const II &a,const II &b)
{
    return a.fs<b.fs;
}
void update(ll u)
{
    while(u<=maxn)
    {
        bit[u]++;
        u+=u&(-u);
    }
}
ll get(ll u)
{
    ll res=0;
    while(u)
    {
        res+=bit[u];
        u-=u&(-u);
    }
    return res;
}
int main()
{
    //freopen("smaller.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
    {
        cin>>b[i].fs;
        b[i].sc=i;
    }
    for (int i=1;i<=n;i++)
        ac[++dem]=II(a[i],i);
    for (int i=1;i<=m;i++)
        ac[++dem]=II(b[i].fs,i+n);
    sort(ac+1,ac+dem+1,cmp);
    for (int i=1;i<=dem;i++)
    {
        if (ac[i].fs!=ac[i-1].fs) now++;
        if (ac[i].sc<=n) a[ac[i].sc]=now;
        else b[ac[i].sc-n].fs=now;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    now=1;
    for (int i=1;i<=m;i++)
    {
        while(a[now]<b[i].fs)
        {
            if (now>n) break;
            update(a[now]);
            now++;
        }
        ll k=get(b[i].fs-1);
        ans[b[i].sc]=k;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
