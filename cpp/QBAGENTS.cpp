#include<bits/stdc++.h>
#define maxn 300
#define fs first
#define sc second
#define oo 1123456789
using namespace std;
int f[maxn][maxn][2],n,m,s,t,res;
vector<int > e[maxn];
struct data
{
        int u,v,k;
};
void bfs()
{
        queue<data > q;
        q.push({s,t,0});
        while(!q.empty())
        {
                int u=q.front().u;
                int v=q.front().v;
                int k=q.front().k;
                q.pop();
                if (k==0)
                {
                        for (int i=0; i<e[u].size(); ++i)
                        {
                                int Xu=e[u][i];
                                if (f[Xu][v][1-k]!=oo) continue;
                                f[Xu][v][1-k]=f[u][v][k]+1;
                                q.push({Xu,v,1-k});
                        }
                }
                else
                {
                        for (int i=0; i<e[v].size(); ++i)
                        {
                                int Xv=e[v][i];
                                if (f[u][Xv][1-k]!=oo) continue;
                                f[u][Xv][1-k]=f[u][v][k]+1;
                                if (u==Xv)
                                {
                                        res=f[u][Xv][1-k]>>1;
                                        return ;
                                }
                                q.push({u,Xv,1-k});
                        }
                }
        }
}
int main()
{
        freopen("QBAGENTS.inp","r",stdin);
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        for (int i=1; i<=m; ++i)
        {
                int u,v;
                scanf("%d%d",&u,&v);
                e[u].push_back(v);
        }
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                        for (int k=0; k<=1; ++k)
                                f[i][j][k]=oo;
        f[s][t][0]=0;
        res=oo;
        if (s==t)
        {
                cout<<0;
                return 0;
        }
        bfs();
        if (res!=oo)printf("%d",res);
        else printf("-1");
        return 0;
}
