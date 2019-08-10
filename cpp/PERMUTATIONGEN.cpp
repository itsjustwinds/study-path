#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int a[maxn],n,res[maxn],ok,deg[maxn];
int main()
{
    freopen("PERMUTATIONGEN.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
         cin>>a[i];
    a[0]=10000000;
    for (int i=1;i<=n;i++)
    {
        deg[i]=i;
        while(a[i]<a[deg[i]-1]) deg[i]=deg[deg[i]-1];
    }
    for (int i=n;i>=2;i++)
    {
        if (deg[i]!=0)
        {
            ok=1;
            for (int i=1;i<=n;i++)
                res[i]=a[i];
            swap(res[deg[i]-1],res[i]);
            sort(res+deg[i],res+n+1);
            break;
        }
    }
    if (ok)
    {
        for (int i=1;i<=n;i++)
            cout<<res[i]<<" ";
    }
    else cout<<-1;
    return 0;
}
