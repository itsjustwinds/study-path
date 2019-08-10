#include <bits/stdc++.h>
#define fs first
#define sc second
#define maxn 10005
using namespace std;
int n,f[maxn];
typedef pair <int,int> II;
II a[maxn];
int finf(int l,int r,int x)
{
    if (l>r) return 0;
    int m=(l+r)/2;
    if (a[m].fs>x) return finf(l,m-1,x);
    return (max(f[m],finf(m+1,r,x)));
}
int main()
{
    freopen("nkrez.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].sc>>a[i].fs;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        //int k=finf(1,i-1,a[i].sc);
        int k=0;
        for (int j=1;j<=i-1;j++)
        if (a[j].fs<=a[i].sc) k=f[j];
        f[i]=max(f[i-1],k+a[i].fs-a[i].sc);
    }
    cout<<f[n];
    return 0;
}
