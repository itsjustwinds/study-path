#include<bits/stdc++.h>
using namespace std;
int a[100],n;
long long sum;
int main()
{
    freopen("array_size.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sum=1;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum*=x;
    }
    sum*=4;
    sum/=1024;
    cout<<sum;
    return 0;
}
