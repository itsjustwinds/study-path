#include<bits/stdc++.h>
using namespace std;
int n,a[maxn],ac[maxn];
int main()
{
    freopen("barcode.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ac[i]=a[i];
    }
    sort(ac+1,ac+n+1);
    while(test--)
    {
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
            a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;

    }
}
