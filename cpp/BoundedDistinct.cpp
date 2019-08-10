#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000000
using namespace std;
int a[maxn],n,l,r,res,f[maxn],ac[maxn],cur[maxn];
vector<int> e[maxn];
int main()
{
    freopen("BoundedDistinct.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>l>>r;
    int dem=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ac[++dem]=a[i];
    }
    sort(ac+1,ac+n+1);
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;
    for (int i=1;i<=n;i++)
        e[a[i]].push_back(i);
    for (int i=1;i<=maxn;i++)
        e[i].push_back(oo);
    memset(cur,-1,sizeof(cur));
    for (int i=1;i<=l;i++)
    {
        cur[a[i]]++;
        f[i]=f[i-1];
        if (cur[a[i]]==0)
        {
            f[i]++;
        }
    }
    int le=2,ri=n-l+1;
    while(le<=ri)
    {
        if (le+r-1<=n)
    }
}
