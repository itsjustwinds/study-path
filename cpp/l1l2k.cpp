#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,k,pos[maxn],bit[maxn],ss[maxn],res,f[1005][1005],dem;
vector<int> e[maxn];
void update(int u,int val)
{
    while(u<=maxn)
    {
        bit[u]=max(bit[u],val);
        u+=u&(-u);
    }
}
int get(int u)
{
    int kq=0;
    while(u)
    {
        kq=max(kq,bit[u]);
        u-=u&(-u);
    }
    return kq;
}
void sub1()
{
    for (int i=1; i<=n; i++)
        a[i]=pos[a[i]];
    for (int i=1; i<=n; i++)
    {
        int tmp=get(a[i]-1);
        update(a[i],tmp+1);
    }
    cout<<get(n);
    return ;
}
void sub2()
{
    for (int i=1; i<=n; i++)
        ss[i]=i;
    for (int i=1; i<=n; i++)
        if (abs(ss[i]-a[1])<=k)
        {
            f[i][1]=1;
        }
        else f[i][1]=f[i-1][1];
    for (int i=1; i<=n; i++)
        if (abs(ss[1]-a[i])<=k)
        {
            f[1][i]=1;
        }
        else f[1][i]=f[1][i-1];
    for (int i=2; i<=n; i++)
        for (int j=2; j<=n; j++)
        {
            if (abs(ss[i]-a[j])<=k)
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            f[i][j]=max(f[i-1][j],f[i][j]);
            f[i][j]=max(f[i][j-1],f[i][j]);
            res=max(res,f[i][j]);
        }
    cout<<res;
}
void sub3()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<(int)e[a[i]].size();j++)
        {
            int h=e[a[i]][j];
            if (h>n||h<1) continue;
            ss[++dem]=h;
        }
    }
    for (int i=1;i<=dem;i++)
    {
        int tmp=get(ss[i]-1);
        update(ss[i],tmp+1);
    }
    cout<<get(dem);
}
int main()
{
    freopen("l1l2k.inp","r",stdin);
    freopen("l1l2k.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
        for (int j=a[i]+k;j>=a[i]-k;j--)
            e[a[i]].push_back(j);
    }
    if (n<=1000) sub2();
    else sub3();
    return 0;
}
