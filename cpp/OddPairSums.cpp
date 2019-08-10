#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,dd[2];
int main()
{
    freopen("OddPairSums.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=2;
    }
    for (int i=1;i<=n;i++)
    {
            dd[!(a[i])]=max(dd[!(a[i])],dd[a[i]]+1);
    }
    cout<<n-max(dd[0],dd[1]);
    return 0;
}
