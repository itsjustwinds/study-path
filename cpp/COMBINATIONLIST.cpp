#include<bits/stdc++.h>
#define maxn 10004
using namespace std;
int n,m,k,f[maxn],res[maxn],bit[maxn],power[maxn],dd[maxn],ok;
void update(int u)
{
    while(u<=maxn)
    {
        bit[u]+=1;
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
int c(int k,int n)
{
    return power[n]/power[n-k];
}
int main()
{
    freopen("COMBINATIONLIST.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    power[0]=1;
    for (int i=1; i<=10; i++)
        power[i]=power[i-1]*i;
    f[m]=1;
    for (int i=n-m+1;i<=n;i++)
    {
        f[m]*=i;
        if (f[m]>10000)
        {
            f[m]=-1;
            break;
        }

    }
    for (int i=m-1; i>=1; i--)
    {
        if (f[i+1]==-1)
        {
            f[i]=f[i+1];
            continue;
        }
        if(f[i+1]*(i+1)<=maxn)
        {
            f[i]=f[i+1]*(i+1);
        }
        else f[i]=-1;
    }
    for (int i=1; i<m; i++)
    {
        if (f[i+1]==-1)
        {
            int tmp=get(1);
            tmp+=1;
            update(tmp+1);
            res[i]=tmp;
            continue;
        }
        int tmp=k/f[i+1]+1;
        k%=f[i+1];
        int tmp1=get(tmp+i-1);
        tmp+=tmp1;
        res[i]=tmp;
        if (k==0)
        {
            ok=1;
            int dem=i;
            for (int j=1; j<=n; j++)
            {
                if (!dd[j])
                    res[++dem]=j;
                if (dem==n) break;
            }
            break;
        }
    }
    if (!ok)
    {
        int dem=0;
        for (int j=1; j<=n; j++)
        {
            if (!dd[j])
                dem++;
            if (dem==k+1)
            {
                res[m]=j;
                break;
            }
        }
    }
    for (int i=1; i<=m; i++)
        cout<<res[i]<<" ";
    return 0;
}
