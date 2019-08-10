#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int a[maxn],n,res;
int main()
{
    //freopen("ezsort.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    res=n;
    for (int i=n;i>=1;i--)
        if (a[i]==res) res--;
    cout<<res;
}
