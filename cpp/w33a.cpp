#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,b[maxn],minn1[maxn],minn2[maxn],res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    res=1000000000;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    minn1[0]=1000000000;
    for (int i=1;i<=n;i++)
        minn1[i]=min(b[i],minn1[i-1]);
    minn2[n+1]=1000000000;
    for (int i=n;i>=1;i--)
        minn2[i]=min(minn2[i+1],b[i]);
    for (int i=1;i<=n;i++)
        res=min(res,a[i]+min(minn1[i-1],minn2[i+1]));
    cout<<res;
    return 0;
}
