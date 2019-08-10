#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,res;
void dfs(int i,int l,int d)
{
    if (d==m)
    {
        res++;
        return;
    }
    if (i+l<=n) dfs(i+l,l,d+1);
}
int main()
{
    freopen("cut.inp","r",stdin);
    freopen("cut.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if (m==1)
    {
        cout<<n;
        return 0;
    }
    for (int i=1;i<=n-m+1;i++)
        for (int j=1;j<=n;j++)
    {
        ll now=res;
        dfs(i,j,1);
        if(now==res) break;
    }
    cout<<res;
    return 0;
}
