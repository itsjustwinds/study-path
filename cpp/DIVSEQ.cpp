#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int dd[maxn],sum,mod,n;
long long res;
int main()
{
        freopen("DIVSEQ.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                memset(dd,0,sizeof(dd));
                cin>>mod>>n;
                sum=0;
                dd[0]=1;
                for(int i=1;i<=n;++i)
                {
                        int x;
                        cin>>x;
                        sum=(sum+x)%mod;
                        res+=dd[sum];
                        dd[sum]++;
                }
                cout<<res<<"\n";
        }
}
