#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],n,num[maxn],pos[maxn],cnt,dd[maxn],f[maxn],res;
vector<int> e[maxn];
void dfs(int u)
{
    if (dd[u]==1) return;
    dd[u]=1;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v);
    }
    num[u]=cnt;
    pos[cnt]=u;
    cnt--;
}
int find1(int l,int r,int x)
{
    int res=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (a[m]>x) r=m-1;
        else if (a[m]<x) l=m+1;
        else
        {
            res=m;
            r=m-1;
        }
    }
    return res;
}
int find2(int l,int r,int x)
{
    int res=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (a[m]>x) r=m-1;
        else if (a[m]<x) l=m+1;
        else
        {
            res=m;
            l=m+1;
        }
    }
    return res;
}
int main()
{
    freopen("nkjump.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=3;i<=n;i++)
        for (int j=i-1;j>=2;j--)
    {
        int tmp1=lower_bound(a+1,a+j+1,a[i]-a[j])-a;
        int tmp2=upper_bound(a+1,a+j+1,a[i]-a[j])-a;
        if (tmp1==0||tmp2==0) continue;
        e[j].push_back(i);
        for (int k=tmp1;k<=tmp2;k++)
            e[k].push_back(i);
    }
    cnt=n;
    for (int i=1;i<=n;i++)
        if (!dd[i])
        dfs(i);
    for (int i=1;i<=n;i++)
        f[i]=1;
    for (int i=n-1;i>=1;i--)
    {
        int u=pos[i];
        for (int j=0;j<(int)e[u].size();j++)
        {
            int v=e[u][j];
            f[i]=max(f[i],f[num[v]]+1);
        }
        res=max(res,f[i]);
    }
    cout<<res;
    return 0;
}
