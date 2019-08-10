#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
II a[maxn],ac[maxn];
int n,dem,bit[maxn],res;
bool cmp(II a,II b)
{
    if (a.fs!=b.fs)return a.fs<b.fs;
    return a.sc>b.sc;
}
int main()
{
    freopen("phanmay.inp","r",stdin);
    freopen("phanmay.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs>>a[i].sc;
        ac[++dem].fs=a[i].fs;
        ac[dem].sc=1;
        ac[++dem].fs=a[i].sc;
        ac[dem].sc=2;
    }
    sort(ac+1,ac+dem+1,cmp);
    int d=0;
    for (int i=1;i<=dem;++i)
    {
        if (ac[i].sc==1) ++d;
        else --d;
        res=max(res,d);
    }
    cout<<res;
    return 0;
}
