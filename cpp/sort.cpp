#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int a[maxn][105],f[maxn],n,m,k,s;
typedef pair<int,int> II;
bool cmp(II a,II b)
{
    if (a.fs<b.fs) return 1;
    return 0;
}
int main()
{
    freopen("sort.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=1;i<=s;i++)
    {
        cin>>k;
        II tmp[maxn];
        for (int i=1;i<=n;i++)
            tmp[i]=II(a[f[i]][k],f[i]);
        sort(tmp+1,tmp+n+1,cmp);
        for (int i=1;i<=n;i++)
            f[i]=tmp[i].sc;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        cout<<a[f[i]][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
