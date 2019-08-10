#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int a[maxn],dd[maxn],trc[maxn],n,dm[maxn],dem,now,res[maxn],m;
int findd(int x)
{
    int ans=0;
    int l=1,r=dem;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if (dm[m]>x)
        {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
int main()
{
    //freopen("COMBINATIONGEN.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
        dd[a[i]]=1;
    }
    for (int i=1;i<=n;i++)
        if (!dd[i])
    {
        dm[++dem]=i;
    }
    int ok=0;
    for (int i=m;i>=1;i--)
    {
        if (ok)
        {
            res[i]=a[i];
            continue;
        }
        int tmp=findd(a[i]);
        if (tmp)
        {
            res[i]=dm[tmp];
            ok=1;
        }
        else res[i]=a[i];
    }
    for (int i=1;i<=m;i++)
        cout<<res[i]<<" ";
    return 0;
}
