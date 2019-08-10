#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
int n;
ll k,f[100][maxn],gt[100],sum[100];
ll tinh(int n,ll k)
{
        if (f[n][k]!=-1) return f[n][k];
        if (n==1&&k!=0)
        {
                f[n][k]=0;
                return f[n][k];
        }
        if (k==0)
        {
                f[n][k]=gt[n];
                return f[n][k];
        }
        f[n][k]=0;
        for (int i=2;i<=n;++i)
        {
                if (sum[i-1]<=k) f[n][k]+=tinh(n-i,k-sum[i-1]);
                else break;
        }
        return f[n][k];
}
int main()
{
        freopen("QBCOND.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        memset(f,-1,sizeof f);
        gt[0]=1;
        for (int i=1;i<=11;++i)
        {
                gt[i]=gt[i-1]*i;
                sum[i]=sum[i-1]+i;
        }
        f[0][0]=1;
        f[2][1]=1;
        while(1)
        {
                cin>>n;
                if (n==-1)break;
                cin>>k;
                cout<<tinh(n,k)<<"\n";
        }
        return 0;
}
