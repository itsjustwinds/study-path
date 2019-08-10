#include<bits/stdc++.h>
#define maxn 105
#define oo 1123456789
using namespace std;
int f[maxn][maxn],a[maxn],n,k,res;
int main()
{
        freopen("ABA12C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                res=oo;
                cin>>n>>k;
                for (int i=0;i<=n;++i)
                        for (int j=0;j<=k;++j)
                        f[i][j]=oo;
                for (int i=1;i<=k;++i)
                        cin>>a[i];
                f[0][0]=0;
                for (int i=1;i<=n;++i)
                {
                        for (int j=1;j<=k;++j)
                        if (a[j]!=-1)
                        {
                                for (int s=0;s<k;++s)
                                if (f[i-1][s]!=oo)
                                {
                                      f[i][s+j]=min(f[i][s+j],f[i-1][s]+a[j]);
                                }
                        }
                        res=min(res,f[i][k]);
                }
                if (res!=oo)cout<<res<<"\n";
                else cout<<-1<<"\n";
        }
        return 0;
}
