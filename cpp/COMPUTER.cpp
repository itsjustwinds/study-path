#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int x,y,b,a,n,sum[maxn*maxn],res,f[maxn][maxn],g[maxn][maxn];
bool check(int m)
{
        memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        for (int i=0; i<=x; ++i)
                for (int j=0; j<=y; ++j)
                {
                        if (f[i][j]>=n) return 1;
                        if (i<x)
                        {
                                int tmp=f[i][j];
                                int k=g[i][j]+a;
                                if (k>=m)
                                {
                                        k=0;
                                        tmp++;
                                }
                                if (tmp>f[i+1][j])
                                {
                                        f[i+1][j]=tmp;
                                        g[i+1][j]=k;
                                }
                                else if (tmp==f[i+1][j]&&k>g[i+1][j]) g[i+1][j]=k;
                        }
                        if (j<y)
                        {
                                int tmp=f[i][j];
                                int k=g[i][j]+b;
                                if (k>=m)
                                {
                                        k=0;
                                        tmp++;
                                }
                                if (tmp>f[i][j+1])
                                {
                                        f[i][j+1]=tmp;
                                        g[i][j+1]=k;
                                }
                                else if(tmp==f[i][j+1]&&k>g[i][j+1]) g[i][j+1]=k;
                        }
                }
        return f[x][y]>=n;
}
int main()
{
        freopen("COMPUTER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test=2;
        while(test--)
        {
                cin>>x>>a>>y>>b>>n;
                int now=0;
                for (int i=0; i<=x; ++i)
                        for (int j=0; j<=y; ++j)
                                sum[++now]=a*i+b*j;
                sort(sum+1,sum+now+1);
                res=0;
                int l=1,r=now;
                while(l<=r)
                {
                        int m=(l+r)>>1;
                        if (check(sum[m]))
                        {
                                res=sum[m];
                                l=m+1;
                        }
                        else r=m-1;
                }
                cout<<res<<"\n";
        }
}
