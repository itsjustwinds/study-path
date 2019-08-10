#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int a[maxn],n,bit[35][2];
ll res;
int getbit(int n,int k)
{
    return (n>>(k-1))&1;
}
int main()
{
    freopen("PANDS.inp","r",stdin);
    freopen("PANDS.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=32;j++)
        {
            int tmp=getbit(a[i],j);
            if (!tmp) continue;
            res+=(ll)bit[j][tmp]*(1<<(j-1));
            bit[j][tmp]++;
        }
    }
    cout<<res;
    return 0;
}
