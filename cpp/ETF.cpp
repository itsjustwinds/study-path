#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int ngto[maxn],dd[maxn+1],n,d,res;
void solve()
{
            int tmp=n;
            for (int i=1;i<=d;++i)
            {
                        if (n%ngto[i]==0)
                        {
                                    res-=tmp/ngto[i];
                                    while(n%ngto[i]==0)
                                    {
                                                n/=ngto[i];
                                    }
                        }
                        if (n!=1&&dd[n]==0)
                        {
                                    res-=tmp/n;
                                    return;
                        }
                        if (n==1) return;
            }
}
int main()
{
            freopen("ETF.inp","r",stdin);
            int test;
            scanf("%d",&test);
            for (int i=2;i*i<=maxn;++i)
            if (!dd[i])
            {
                        for (int j=i*i;j<=maxn;j+=i)
                        dd[j]=1;
            }
            for (int i=2;i<=maxn;++i)
                        if (!dd[i]) ngto[++d]=i;
            while(test--)
            {
                        scanf("%d",&n);
                        res=n;
                        solve();
                        printf("%d\n",res);
            }
            return 0;
}
