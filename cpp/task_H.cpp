#include<bits/stdc++.h>
#define maxn 15
using namespace std;
int n,k,m,E[maxn],P[maxn],f[256][105][105],M;
int bit(int mask,int i)
{
        return mask&(1<<(i-1));
}
int light(int mask,int i)
{
        return mask|(1<<(i-1));
}
void solve()
{
        cin>>k>>m;
        cin>>n;
        for (int i=1;i<=n;++i)
        cin>>E[i];
        for (int i=1;i<=n;++i)
        cin>>P[i];
        memset(f,-1,sizeof f);
        f[0][100][0]=0;
        int M=(1<<n)-1;
        int res=0;
        for (int mask=0;mask<=M;++mask)
        {
                for (int i=100;i>=0;--i)
                        for (int j=100;j>=0;--j)
                {
                        res=max(res,f[mask][i][j]);
                        if (mask==1&&i==70&&j==10)
                        {
                                int ok=1;
                        }
                        if (f[mask][i][j]==-1) continue;
                        if (i>k)
                        {
                                int x=i-k;
                                int y=max(0,j-m);
                                f[mask][x][y]=max(f[mask][x][y],f[mask][i][j]+1);
                                for (int h=1;h<=n;++h)
                                {
                                        if (bit(mask,h)) continue;
                                        if (y+P[h]>=100) continue;
                                        int MASK=light(mask,h);
                                        int X=min(100,x+E[h]);
                                        int Y=y+P[h];
                                        f[MASK][X][Y]=max(f[MASK][X][Y],f[mask][i][j]+1);
                                }
                        }
                }
        }
        cout<<res<<"\n";
}
int main()
{
        freopen("task_H.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--) solve();
}
