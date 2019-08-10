#include <bits/stdc++.h>
using namespace std;
int f1[7],f2[7],n,res;
int main()
{
    //freopen("779a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f1[x]++;
    }
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f2[x]++;
    }
    for (int i=1;i<=5;i++)
    if (abs(f1[i]-f2[i])%2==0)
    {
        res+=abs(f1[i]-f2[i])/2;
    }
    else {
        cout<<-1;
        return 0;
    }
    cout<<res/2;
    return 0;
}
