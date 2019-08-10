#include<bits/stdc++.h>
#define maxn 4005
#define ll long long
using namespace std;
int a[maxn][maxn],sum[maxn][maxn];
char s[maxn];
int n,k;
int get(int ux,int uy,int vx,int vy)
{
        return sum[vx][vy]-sum[ux-1][vy]-sum[vx][uy-1]+sum[ux-1][uy-1];
}
ll tinh(int m)
{
        ll res=0;
        for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
                int now=n+1;
                for (int k=j;k<=n;++k)
                {
                        while(now-1>=i&&get(i,j,now-1,k)>=m) now--;
                        res+=n-now+1;
                }
        }
        return res;
}
int main()
{
        freopen("MATRIX.inp","r",stdin);
        freopen("MATRIX.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>k;
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                a[i][j]=(s[i]-'0')*(s[j]-'0');
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        cout<<tinh(k)-tinh(k+1);

}
