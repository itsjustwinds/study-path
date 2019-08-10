#include<bits/stdc++.h>
#define maxn 60005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
II a[maxn];
int n,f[maxn];
int main()
{
    freopen("nktick.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs;
    for (int i=1;i<=n-1;i++)
        cin>>a[i].sc;
    a[n].sc=100000000;
    f[1]=a[1].fs;
    for (int i=2;i<=n;i++)
        f[i]=min(f[i-1]+a[i].fs,f[i-2]+a[i-1].sc);
    cout<<f[n];
    return 0;
}
