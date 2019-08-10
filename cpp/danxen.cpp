#include <bits/stdc++.h>
#define maxn 1000005
#define fs first
#define sc second
#define oo 100000000
using namespace std;
int n;
typedef pair<int,int> II;
II a[maxn],f[maxn];
int main()
{
    freopen("danxen.inp","r",stdin);
    freopen("danxen.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int maxx=-oo;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs;
        if (a[i].fs>maxx) maxx=a[i].fs;
    }
    if (maxx<0)
    {
        cout<<maxx;
        return 0;
    }
    for (int i=1;i<=n;i++)
        cin>>a[i].sc;
    for (int i=1;i<=n;i++)
    {
        f[i].fs=-oo;
        f[i].sc=-oo;
    }
    f[0].fs=0;
    f[0].sc=0;
    for (int i=1;i<=n;i++)
    {
        f[i].fs=f[i-1].fs;
        f[i].sc=f[i-1].sc;
        if (a[i].sc==1)
        {
            f[i].fs=max(f[i-1].fs,f[i-1].sc+a[i].fs);
        }
       else f[i].sc=max(f[i-1].sc,f[i-1].fs+a[i].fs);
    }
    cout<<max(f[n].fs,f[n].sc);
    return 0;
}
