#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int a[maxn],n;
ll s[maxn],dm;
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int findd(int l,int r,ll x)
{
    while(l<=r)
    {
        int m=(l+r)/2;
        if (s[m]<x) l=m+1;
        if (s[m]>x) r=m-1;
        if (s[m]==x) return m;
    }
    return 0;
}
int main()
{
    freopen("808d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    if (s[n]%2)
    {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        int k=findd(1,i-1,s[n]/2-a[i]);
        if (k)
        {
            cout<<"YES";
            return 0;
        }
        k=findd(i+1,n,s[n]/2+a[i]);
        if (k)
        {
            cout<<"YES";
            return 0;
        }
    }
    for (int i=1;i<=n;i++)
        if (s[i]==s[n]/2)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}
