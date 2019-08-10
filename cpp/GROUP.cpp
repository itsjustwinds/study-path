#include<bits/stdc++.h>
#define maxn 1005
#define mod 1000000007
using namespace std;
int f[maxn][maxn];
int main()
{
        freopen("GROUP.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        for (int i=1;i<maxn;++i)
                f[i][i]=1;
        for (int i=1;i<maxn;++i)
        for (int j=i-1;j>=2;--j)
        f[i][j]=(f[i][j+1]+f[i-j][j])%mod;
        int test;
        int k=2;
        cin>>test;
        while(test--)
        {
                int x;
                cin>>x;
                cout<<f[x][k]<<"\n";
        }
}
