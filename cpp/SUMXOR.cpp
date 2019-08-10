#include<bits/stdc++.h>
#define maxn 1000006
#define ll long long
using namespace std;
int a[maxn],n,bit[33][2];
ll res;
int getbit(int n,int k)
{
    return (n>>(k-1))&1;
}
int main()
{
    freopen("SUMXOR.inp","r",stdin);
    freopen("SUMXOR.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=32;j++)
        {
            int tmp=1-getbit(a[i],j);
            res+=(ll)bit[j][tmp]*(1<<(j-1));
        }
        for (int j=1;j<=32;j++)
        {
            int tmp=getbit(a[i],j);
            bit[j][tmp]++;
        }
    }
    cout<<res;
}
