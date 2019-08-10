#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int f[2][maxn][maxn][2],dx[2][10],dy[2][10];
char s[maxn][maxn];
int n,m;
struct data
{
        int x,y,r;
};
data M,T;
bool check(int i,int j)
{
        return i>0&&i<=n&&j>0&&j<=m&&s[i][j]!='#';
}
void bfs(int tx)
{
        queue<data > q;
        while(!q.empty()) q.pop();
        if (tx==0)
        {
                q.push({M.x,M.y,1});
                f[tx][M.x][M.y][1]=0;
        }
        else{
                q.push({T.x,T.y,1});
                f[tx][T.x][T.y][1]=0;
        }
        while(!q.empty())
        {
                data tmp=q.front();
                q.pop();
                int t=tmp.r;
                int x=tmp.x;
                int y=tmp.y;
                for (int i=1;i<=8;++i)
                {
                        int u=x+dx[tx][i];
                        int v=y+dy[tx][i];
                        if (check(u,v)==0||f[tx][x][y][t]+1>=f[tx][u][v][1-t])
                                continue;
                        f[tx][u][v][1-t]=f[tx][x][y][t]+1;
                        q.push({u,v,1-t});
                }
        }
}
int main()
{
        freopen("MATOT.inp","r",stdin);
        freopen("MATOT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        dx[0][1]=-2;dy[0][1]=-1;
        dx[0][2]=-2;dy[0][2]=1;
        dx[0][3]=-1;dy[0][3]=2;
        dx[0][4]=1;dy[0][4]=2;
        dx[0][5]=2;dy[0][5]=1;
        dx[0][6]=2;dy[0][6]=-1;
        dx[0][7]=1;dy[0][7]=-2;
        dx[0][8]=-1;dy[0][8]=-2;
        dx[1][1]=-1;dy[1][1]=-1;
        dx[1][2]=-1;
        dx[1][3]=-1;dy[1][3]=1;
        dy[1][4]=1;
        dx[1][5]=1;dy[1][5]=1;
        dx[1][6]=1;
        dx[1][7]=1;dy[1][7]=-1;
        dy[1][8]=-1;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
        {
                cin>>s[i][j];
                if (s[i][j]=='M') M={i,j,0};
                if (s[i][j]=='T') T={i,j,0};
        }
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                for (int k=0;k<=1;++k)
        {
                f[0][i][j][k]=1e9;
                f[1][i][j][k]=1e9;
        }
        bfs(0);
        bfs(1);
        int res=1e9;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
        {
                res=min(res,max(f[0][i][j][1],f[1][i][j][1]));
                res=min(res,max(f[0][i][j][0],f[1][i][j][0]));
        }
        if (res!=1e9)cout<<res;
        else cout<<-1;
        return 0;
}
