#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][maxn][5],a[maxn],n,dx[2],dy[2],res;
char s[maxn];
struct data
{
        int x,y,id,d;
};
void go(int m)
{
        queue<data> q;
        while(!q.empty()) q.pop();
        q.push({m,m,-1,1});
        while(!q.empty())
        {
                int x=q.front().x;
                int y=q.front().y;
                int t=q.front().id;
                int d=q.front().d;
                if (d>n)
                {
                        return;
                }
                q.pop();
                if (t==-1)
                {
                        for (int i=0; i<2; ++i)
                        {
                                int u=(x+dx[i]+n)%n;
                                int v=(y+dy[i]+n)%n;
                                int tmp;
                                if (u!=x) tmp=f[x][y][-t+1]+t*(s[u]=='D');
                                else tmp=f[x][y][-t+1]+t*(s[v]=='D');
                                if (f[u][v][t+1]==-1e9||tmp<f[u][v][t+1])
                                {
                                        f[u][v][t+1]=tmp;
                                        q.push({u,v,-t,d+1});
                                        if (d+1==n)
                                        {
                                                if (f[u][v][t+1]>0&&f[v][u][t+1]>0)
                                                {
                                                        ++res;
                                                        return;
                                                }
                                        }
                                }
                        }
                }
                if (t==1)
                {
                        for (int i=0; i<2; ++i)
                        {
                                int u=(x+dx[i]+n)%n;
                                int v=(y+dy[i]+n)%n;
                                int tmp;
                                if (u!=x) tmp=f[x][y][-t+1]+t*(s[u]=='D');
                                else tmp=f[x][y][-t+1]+t*(s[v]=='D');
                                if (f[u][v][t+1]==-1e9||tmp<f[u][v][t+1])
                                {
                                        f[u][v][t+1]=tmp;
                                        q.push({u,v,-t,d+1});
                                        if (d+1==n)
                                        {
                                                if (f[u][v][t+1]>0&&f[v][u][t+1]>0)
                                                {
                                                        ++res;
                                                        return;
                                                }
                                        }
                                }
                        }
                }
        }
}
int main()
{
        freopen("SELECT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>s;
        n=strlen(s);
        dx[0]=-1;
        dy[0]=0;
        dx[1]=0;
        dy[1]=1;
        for (int i=0; i<n; ++i)
        {
                for (int i=0; i<n; ++i)for (int j=0; j<n; ++j)for (int k=-1; k<=1; ++k)f[i][j][k+1]=-1e9;
                f[i][i][2]=(s[i]=='D');
                go(i);
        }
        cout<<res;
}
