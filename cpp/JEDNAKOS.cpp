#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
char str[maxn],s[maxn];
int f[maxn][maxn],sum,n;
void update(int i,int k,int tmp)
{
        for (int j=sum-tmp; j>=0; --j)if (f[k][j])
                {
                        if (f[i][j+tmp]) f[i][j+tmp]=min(f[i][j+tmp],f[k][j]+1);
                        else f[i][j+tmp]=f[k][j]+1;
                }
}
int main()
{
        freopen("JEDNAKOS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(str+1);
        n=strlen(str+1);
        for (int i=n; i>=1; --i)
        {
                if (str[i]=='=')
                {
                        for (int j=i+1; j<=n; ++j)
                                sum=sum*10+(str[j]-'0');
                        n=i-1;
                        break;
                }
        }
        f[0][0]=1;
        int m=0;
        int d=0;
        for (int i=1; i<=n; ++i)
        {
                if (str[i]=='0') ++d;
                else d=0;
                if (d==3)
                {
                        d=0;
                        m-=2;
                        continue;
                }
                s[++m]=str[i];
        }
        n=m;
        f[0][0]=1;
        for (int i=1; i<=n; ++i)
        {
                int tmp=0;
                int base=1;
                for (int k=1;; ++k)
                {
                        if (i-k<0) break;
                        if (s[i-k+1]!='0'&&k>=5) break;
                        tmp=(s[i-k+1]-'0')*base+tmp;
                        base*=10;
                        for (int j=sum-tmp; j>=0; --j)if (f[i-k][j])
                                {
                                        if (f[i][j+tmp]) f[i][j+tmp]=min(f[i][j+tmp],f[i-k][j]+1);
                                        else f[i][j+tmp]=f[i-k][j]+1;
                                }
                }
        }
        if (f[n][sum])cout<<f[n][sum]-2;
        else cout<<999999999;
        return 0;
}
