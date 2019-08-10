#include<bits/stdc++.h>
#define maxn 505
using namespace std;
int n,a[maxn][maxn],m,now,dd1[maxn][maxn],dd2[maxn][maxn];
int dxA[5],dyA[5],dxB[5],dyB[5];
struct data
{
        int x,y,d;
};
queue<data > q1,q2;
bool check(int i,int j)
{
        return i>=1&&i<=n&&j>=1&&j<=n;
}
void bfs2()
{
        while(!q2.empty())
        {
                int x=q2.front().x;
                int y=q2.front().y;
                int d=q2.front().d;
                if (d==now) return;
                q2.pop();
                for (int i=1;i<=3;++i)
                {
                        int u=x+dxB[i];
                        int v=y+dyB[i];
                        if (!check(u,v)) continue;
                        if (dd2[u][v]==now) continue;
                        if (a[u][v]==1) continue;
                        q2.push({u,v,d+1});
                        dd2[u][v]=now;
                }
        }
}
void bfs1()
{
        while(!q1.empty())
        {
                int x=q1.front().x;
                int y=q1.front().y;
                int d=q1.front().d;
                if (d==now)
                {
                        ++now;
                        bfs2();
                }
                q1.pop();
                for (int i=1;i<=3;++i)
                {
                        int u=x+dxA[i];
                        int v=y+dyA[i];
                        if (!check(u,v)) continue;
                        if (a[u][v]) continue;
                        if (dd1[u][v]==now) continue;
                        dd1[u][v]=now;
                        q1.push({u,v,now});
                        if (dd2[u][v]==now)
                        {
                                cout<<d+1;
                                return;
                        }
                }
        }
}
int main()
{
        freopen("ROBOCON.inp","r",stdin);
        freopen("ROBOCON.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        dxA[1]=0;dyA[1]=1;
        dxA[2]=1;dyA[2]=1;
        dxA[3]=1;dyA[3]=0;
        dxB[1]=0;dyB[1]=-1;
        dxB[2]=1;dyB[2]=-1;
        dxB[3]=1;dyB[3]=0;
        for (int i=1;i<=m;++i)
        {
                int x,y;
                cin>>x>>y;
                a[x][y]=1;
        }
        if (n==1)
        {
                cout<<0;
                return 0;
        }
        q1.push({1,1,0});
        q2.push({1,n,0});
        bfs1();
        return 0;
}
