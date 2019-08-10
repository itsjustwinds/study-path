#include<bits/stdc++.h>
using namespace std;
int f[50],n,dd[10000000];
void sangnt()
{
    for (int i=2;i*i<=f[40];i++)
        if (!dd[i])
    {
        for (int j=i*i;j<=f[40];j+=i)
        {
            dd[j]=1;
        }
    }
}
int main()
{
    freopen("tile.inp","r",stdin);
    freopen("tile.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[1]=1;f[2]=1;f[3]=1;f[4]=2;
    for (int i=5;i<=40;i++)
        f[i]=f[i-4]+f[i-1];
    sangnt();
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n;
        int res=0;
        for (int i=2;i<=f[n];i++)
            if (!dd[i]) res++;
        cout<<res<<"\n";
    }
    return 0;
}
