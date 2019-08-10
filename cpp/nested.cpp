#include<bits/stdc++.h>
#define maxn 105
#define fs first
#define sc second
#define ll long long
using namespace std;
int n,res;
typedef pair<int,int> II;
typedef pair<II,II> III;
III a[maxn];
int f[maxn];
bool cmp(const III &a, const III &b)
{
    ll tmp1=abs(a.fs.fs-a.sc.fs)*abs(a.fs.sc-a.sc.sc);
    ll tmp2=abs(b.fs.fs-b.sc.fs)*abs(b.fs.sc-b.sc.sc);
    if (tmp1<tmp2) return 1;
    return 0;
}
int main()
{
    freopen("nested.inp","r",stdin);
    freopen("nested.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs.fs>>a[i].fs.sc>>a[i].sc.fs>>a[i].sc.sc;
    sort(a+1,a+n+1,cmp);
    f[1]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=i-1;j++)
        if (a[i].fs.fs<=a[j].fs.fs&&a[i].sc.fs>=a[j].sc.fs&&a[i].fs.sc<=a[j].fs.sc&&a[i].sc.sc>=a[j].sc.sc)
            f[i]=max(f[i],f[j]+1);
    }
    int res=0;
    for (int i=1;i<=n;i++)
    {
        res=max(res,f[i]);
    }
    cout<<res;
    return 0;
}
