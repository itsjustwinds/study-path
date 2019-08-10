#include <bits/stdc++.h>
using namespace std;
int a[200001],n;
int main()
{
    //freopen("395b.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    if (n%2==0)
    {
        for (int i=1; i<=n/2; i++)
        {
            if (i%2==1) cout<<a[n-i+1]<<" ";
            else cout<<a[i]<<" ";
        }
        if (n%2==1) cout<<a[(n+1)/2]<<" ";
        for (int i=(n+1)/2+1; i<=n; i++)
        {
            if (i%2==0) cout<<a[n-i+1]<<" ";
            else cout<<a[i]<<" ";
        }
    }
    else
    {
        for (int i=1; i<=n/2; i++)
        {
            if (i%2==1) cout<<a[n-i+1]<<" ";
            else cout<<a[i]<<" ";
        }
        if (n%2==1) cout<<a[(n+1)/2]<<" ";
        for (int i=(n+1)/2+1; i<=n; i++)
        {
            if (i%2==1) cout<<a[n-i+1]<<" ";
            else cout<<a[i]<<" ";
        }
    }
    return 0;
}
