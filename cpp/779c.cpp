#include <bits/stdc++.h>
#define maxn 200005
#define fs first
#define sc second
using namespace std;
int n,k;
typedef pair<int,int> II;
typedef pair<int,II> III;
III a[maxn];
long long res;
int main()
{
    //freopen("779c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i].sc.fs;
    for (int i=1;i<=n;i++)
        cin>>a[i].sc.sc;
    for (int i=1;i<=n;i++)
        a[i].fs=a[i].sc.fs-a[i].sc.sc;
    sort(a+1,a+n+1);
    for (int i=1;i<=k;i++)
        res+=a[i].sc.fs;
    int m=k+1;
    for (int i=m;i<=n;i++)
        if (a[i].fs<0)
    {
        res+=a[i].sc.fs;
        m+=1;
    }
    else break;
    for (int i=m;i<=n;i++)
        res+=a[i].sc.sc;
    cout<<res;
    return 0;
}
