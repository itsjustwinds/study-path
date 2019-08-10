#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],bit[maxn],n,maxx,dd[maxn],ans[maxn];
void update(int u)
{
    while(u)
    {
        bit[u]++;
        u-=u&(-u);
    }
}
int get(int u)
{
    int res=0;
    while(u<maxn)
    {
        res+=bit[u];
        u+=u&(-u);
    }
    return res;
}
int main()
{
    //freopen("900C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n==1)
    {
        cout<<1;
        return 0;
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        int k=get(a[i]);
        if (k==0)
        {
            maxx=a[i];
            dd[i]=1;
        }
        if (k==1)
        {
            ans[maxx]++;
        }
        update(a[i]);
    }
    int M=-1e9;
    int res=0;
    for (int i=1;i<=n;++i)
    {
        int tmp=ans[a[i]]-dd[i];
        if (tmp>M)
        {
            M=tmp;
            res=a[i];
        }
        if (tmp==M&&a[i]<res) res=a[i];
    }
    cout<<res;
    return 0;
}
