#include<bits/stdc++.h>
#define maxn 105
#define ll long long
#define fs first
#define sc second
using namespace std;
int f[1005][2*maxn][2*maxn],n,m;
int dd[2*maxn][2*maxn],x[1005],y[1005];
int dx[5],dy[5];
ll res;
bool check(int i,int j)
{
        return i>=-100&&i<=100&&j>=-100&&j<=100&&dd[i+maxn][j+maxn]==0;
}
typedef pair<int,int> II;
void bfs(int i,int j,int k)
{
        queue<II> q;
        while(!q.empty()) q.pop();
        q.push(II(x[k],y[k]));
        f[k][x[k]+maxn][y[k]+maxn]=0;
        while(!q.empty())
        {
                int x=q.front().fs;
                int y=q.front().sc;
                q.pop();
                for (int i=1;i<=4;++i)
                {
                        int u=x+dx[i];
                        int v=y+dy[i];
                        if (!check(u,v)||f[k][u+maxn][v+maxn]!=1e9) continue;
                        f[k][u+maxn][v+maxn]=f[k][x+maxn][y+maxn]+1;
                        q.push(II(u,v));
                }
        }
}
bool cmp1(II a,II b)
{
        return a.fs<b.fs;
}
bool cmp2(II a,II b)
{
        return a.sc<b.sc;
}
void sub2()
{
        II a[1005];
        long long res=0;
        for (int i=1;i<=n;++i)
        a[i]=II(x[i],y[i]);
        sort(a+1,a+n+1,cmp1);
        int X=a[(n+1)/2].fs;
        sort(a+1,a+n+1,cmp2);
        int Y=a[(n+1)/2].sc;
        for (int i=1;i<=n;++i)
        res+=abs(a[i].fs-X)+abs(a[i].sc-Y);
        cout<<res;
}
int main()
{
        freopen("BALLGAME.inp","r",stdin);
        freopen("BALLGAME.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>m;
        int maxx=0;
        for (int i=1;i<=m;++i)
        {
                int X,Y;
                cin>>X>>Y;
                dd[X+maxn][Y+maxn]=1;
                maxx=max(maxx,max(abs(X),abs(Y)));
        }
        cin>>n;
        dx[1]=-1;dy[1]=0;
        dx[2]=0;dy[2]=1;
        dx[3]=1;dy[3]=0;
        dx[4]=0;dy[4]=-1;
        for (int i=1;i<=n;++i)
        {
                cin>>x[i]>>y[i];
                maxx=max(maxx,max(abs(x[i]),abs(y[i])));
        }
        for (int i=1;i<=n;++i)
        for (int j=-100;j<=100;++j)
        for (int k=-100;k<=100;++k)
        f[i][j+maxn][k+maxn]=1e9;
        if (maxx>100)
        {
                sub2();
                return 0;
        }
        for (int i=1;i<=n;++i)
                bfs(x[i],y[i],i);
        ll res=1e18;
        for (int i=-100;i<=100;++i)
                for (int j=-100;j<=100;++j)
        {
                if (dd[i+maxn][j+maxn]) continue;
                ll tmp=0;
                for (int k=1;k<=n;++k)
                        tmp+=f[k][i+maxn][j+maxn];
                res=min(res,tmp);
        }
        if (res!=1e18)cout<<res;
        else cout<<-1;
        return 0;
}
