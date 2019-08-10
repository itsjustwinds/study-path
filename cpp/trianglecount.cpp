#include<bits/stdc++.h>
using namespace std;
int a[1000],n;
int res;
int main()
{
    //freopen("trianglecount.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n-2;i++)
        for (int j=i+1;j<=n-1;j++)
    {
        int tmp=a[i]+a[j];
        for (int k=j+1;k<=n;k++)
            if (a[k]<tmp) res++;
    }
    cout<<res;
    return 0;
}
