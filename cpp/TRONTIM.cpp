#include<bits/stdc++.h>
#define maxn 105
#define oo 100000000
using namespace std;
int dem,tplt[maxn*maxn],a[maxn][maxn],start,fin[3],d,n,m,dd[maxn*maxn][maxn*maxn];
typedef pair<int,int> II;
vector<II> e[maxn*maxn];
int mv[4][3];
void dfs(int i,int j)
{
    for (int k=1; k<=4; k++)
    {
        int u=i+mv[k][1],v=j+mv[k][2];
        if (u<=0||u>n||v<=0||v>m) continue;
        if (a[u][v]==oo)
        {
            fin[++d]=dem;
            a[u][v]=dem;
            dfs(u,v);
            continue;
        }
        if (a[u][v]!=0) continue;
        a[u][v]=dem;
        dfs(u,v);
    }
}
int main()
{
    freopen("TRONTIM.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mv[1][1]=-1;
    mv[1][2]=0;
    mv[2][1]=0;
    mv[2][2]=1;
    mv[3][1]=1;
    mv[3][2]=0;
    mv[4][1]=0;
    mv[4][2]=-1;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            char s;
            cin>>s;
            if (s=='*') a[i][j]=-1;
            if (s=='$') a[i][j]=oo;
            if (s=='#') a[i][j]=oo+1;
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]!=-1&&a[i][j]!=oo+1)
            {
                dem++;
                dfs(i,j);
            }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            {
                dfs2(i,j);
            }
}
