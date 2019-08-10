#include<bits/stdc++.h>
#define maxn 1505
#define oo 1000000005
using namespace std;
int n,m,dd[maxn][maxn],f[maxn][maxn],c[maxn][maxn],dx[5],dy[5];
struct data
{
        int x,y,c;
};
data S[2];
char s[maxn][maxn];
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.c>b.c;
        }
};
bool check(int x,int y)
{
        return (x>=1&&x<=n&&y>=1&&y<=m);
}
void bfs()
{
        queue<data> q;
        while(!q.empty()) q.pop();
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        if (s[i][j]!='X')
                        {
                                dd[i][j]=1;
                                q.push({i,j,0});
                        }
        while(!q.empty())
        {
                int x=q.front().x;
                int y=q.front().y;
                q.pop();
                for (int i=1; i<=4; ++i)
                {
                        int Ux=x+dx[i];
                        int Uy=y+dy[i];
                        if (dd[Ux][Uy]) continue;
                        if (!check(Ux,Uy)) continue;
                        c[Ux][Uy]=c[x][y]+1;
                        dd[Ux][Uy]=1;
                        q.push({Ux,Uy,0});
                }
        }
}
void dijkstra()
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        q.push({S[1].x,S[1].y,0});
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                        f[i][j]=oo;
        f[S[1].x][S[1].y]=0;
        while(!q.empty())
        {
                int x=q.top().x;
                int y=q.top().y;
                q.pop();
                if (x==S[2].x&&y==S[2].y)
                {
                        break;
                }
                for (int i=1; i<=4; ++i)
                {
                        int Ux=x+dx[i];
                        int Uy=y+dy[i];
                        if (!check(Ux,Uy)) continue;
                        if (max(f[x][y],c[Ux][Uy])<f[Ux][Uy])
                        {
                                f[Ux][Uy]=max(f[x][y],c[Ux][Uy]);
                                q.push({Ux,Uy,f[Ux][Uy]});
                        }
                }
        }
}
int main()
{
        freopen("LABUDOVI.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        int cnt=0;
        dx[1]=-1;
        dy[1]=0;
        dx[2]=0;
        dy[2]=1;
        dx[3]=1;
        dy[3]=0;
        dx[4]=0;
        dy[4]=-1;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        cin>>s[i][j];
                        if (s[i][j]=='L')
                        {
                                ++cnt;
                                S[cnt].x=i;
                                S[cnt].y=j;
                        }
                }
        bfs();
        dijkstra();
        cout<<f[S[2].x][S[2].y];
        return 0;
}
