#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
#define mod 1000000007
using namespace std;
ll f[maxn][maxn],dd[maxn];
int n,d;
int main()
{
        freopen("DAY.inp","r",stdin);
        freopen("DAY.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>d>>n;
        dd[1]=1;
        dd[0]=1;
        for (int i=2; i<=n; ++i)
        {
                for (int k=d; k>=1; --k)
                {
                        f[i][k]=(f[i][k]+dd[k-1])%mod;
                        dd[k]=(dd[k]+f[i][k])%mod;
                }
        }
        cout<<dd[d];
        return 0;

}

