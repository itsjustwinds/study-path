#include<bits/stdc++.h>
using namespace std;
int f[55],n,k,dem;
int res[55];
int main()
{
    //freopen("791c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n-k+1;i++)
    {
        string s;
        cin>>s;
        if (s=="NO") f[i]=-1;
        else f[i]=1;
    }
   for (int i=1;i+k-1<=n;i++)
    if(f[i]==-1)
    {
        if (res[i]==0)
        {
            res[i]=++dem;
            res[i+k-1]=dem;
        }
        else
        {
            res[i+k-1]=res[i-k+1];
        }
    }
    else if (res[i]==0) res[i]=++dem;

    for (int i=n-k+2;i<=n-1;i++)
        if (res[i]==0)
        res[i]=++dem;
        if(res[n]==0) res[n]=++dem;
    for (int i=1;i<=n;i++)
        cout<<char(res[i]/10+65)<<char(res[i]%10+97)<<" ";
    return 0;
}
