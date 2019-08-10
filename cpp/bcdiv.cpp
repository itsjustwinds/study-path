#include<bits/stdc++.h>
#define maxn 30
#define ll long long
using namespace std;
ll f[maxn][maxn];
int n,k;
int main()
{
        freopen("BCDIV.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        f[0][0]=1;
        for(int j=1;j<=25;++j)
                for (int i=1;i<=25;++i)
                f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
        while(test--)
        {
                cin>>n>>k;
                cout<<f[n][k]<<"\n";
        }
        return 0;
}
