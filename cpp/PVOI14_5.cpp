#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],e[maxn][100],n,ngto[maxn],dd[maxn+1],dem;
long long res,ans;
void pt(int x)
{
    for (int i=1;i<=dem;i++)
    {
        int k=0;
        while(x%ngto[i]==0)
        {
            x/=ngto[i];
            k++;
        }
        e[i][k]++;
    }
}
void tinh(int k)
{
    int tmp1=1000000;
    int tmp2;
    for (int i=0;i<=50;i++)
    {
        int t=0;
        for (int j=0;j<=50;j++)
            t+=abs(j-i)*e[k][j];
        if (tmp1>t)
        {
            tmp1=t;
            tmp2=i;
        }
    }
    res+=tmp1;
    for (int i=1;i<=tmp2;i++)
        ans*=ngto[k];
}
int main()
{
    freopen("D:\\C++\\huy\\PVOI14_5.inp", "r", stdin);
    freopen("D:\\C++\\huy\\PVOI14_5.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=2;i*i<=10000;i++)
        if (!dd[i])
    {
        for (int j=i*i;j<=10000;j+=i)
        {
            dd[j]=1;
        }
    }
    for (int i=2;i<=10000;i++)
        if (!dd[i])
    {
        ngto[++dem]=i;
    }
    for (int i=1;i<=n;i++)
        pt(a[i]);
    ans=1;
    for (int i=1;i<=dem;i++)
        tinh(i);
    cout<<res<<" "<<ans;
    return 0;
}
