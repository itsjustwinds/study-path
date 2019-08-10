#include<bits/stdc++.h>
using namespace std;
long long n,a[50],res,m;
void dfs(int i,long long s)
{
    if (i==n+1) return;
    dfs(i+1,s);
    if (s+a[i]<=m)
    {
        res++;
        dfs(i+1,s+a[i]);
    }
}
int main()
{
    freopen("festival.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
        dfs(1,0);
    cout<<res;
    return 0;
}
