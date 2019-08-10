#include<bits/stdc++.h>
#define maxn 105
using namespace std;
typedef int bignum;
int n,k;
bignum s,res,c[105][105];
int a[maxn],res[maxn],dd[maxn];
int get(int k)
{
            int dem=0;
            for (int i=1;i<=n;++i)
            {
                        if (dd[i]) continue;
                        ++dem;
                        if (dem==k)
                        {
                                    dd[i]=1;
                                    return i;
                        }
            }
            return n;
}
int main()
{
            freopen("SHCH.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>k;
            cin>>s;
            for  (int i=1;i<=n;++i) cin>>a[i];
            for (int i=1;i<=100;++i)
                        c[0][i]=1;
            for (int i=1;i<=100;++i)
                        for (int j=i;j<=100;++j)
                        c[i][j]=c[i-1][j-1]+c[i][j-1];
            for (int i=1;i<=k;++i)
            {
                        int tmp=((s-1)/c[k-i][n-i])+1;
                        res[i]=get(tmp);

            }
}
