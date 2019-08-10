#include<bits/stdc++.h>
#define maxn 105
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
char s[maxn][maxn];
int n,m,dd[maxn*maxn][maxn*maxn],visited[maxn*maxn],a[maxn*maxn],cnt,num[maxn][maxn],low[maxn][maxn],dem,pos[maxn][maxn],id,res;
int loc[maxn*maxn],vis[maxn*maxn],f[maxn*maxn],check[maxn*maxn];
stack<II> q;
vector<II> e[maxn][maxn];
vector<int> edge[maxn*maxn];
void visit(int x,int y)
{
    cnt++;
    num[x][y]=cnt;
    low[x][y]=cnt;
    q.push(II(x,y));
    for (int i=0; i<(int)e[x][y].size(); i++)
    {
        II v=e[x][y][i];
        if (num[v.fs][v.sc]>0)
        {
            low[x][y]=min(low[x][y],num[v.fs][v.sc]);
        }
        else
        {
            visit(v.fs,v.sc);
            low[x][y]=min(low[x][y],low[v.fs][v.sc]);
        }
    }
    if (num[x][y]==low[x][y])
    {
        II v=II(0,0);
        dem++;
        while(v!=II(x,y))
        {
            v=q.top();
            q.pop();
            pos[v.fs][v.sc]=dem;
            low[v.fs][v.sc]=num[v.fs][v.sc]=1000000005;
            if (s[v.fs][v.sc]-'0'>=0&&s[v.fs][v.sc]-'0'<=9)
                a[dem]+=int(s[v.fs][v.sc]-'0');
        }
    }
}
void dfs(int u)
{
    if (check[u]) return;
    check[u]=1;
    for (int i=0; i<(int)edge[u].size(); i++)
    {
        int v=edge[u][i];
        dfs(v);
    }
    vis[u]=id;
    loc[id]=u;
    id--;
}
int main()
{
    freopen("kcollect.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>s[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (s[i][j]!='#')
            {
                if (j+1<=m&&s[i][j+1]!='#') e[i][j].push_back(II(i,j+1));
                if (i+1<=n&&s[i+1][j]!='#') e[i][j].push_back(II(i+1,j));
                if (s[i][j]=='W'&&j-1>=1&&s[i][j-1]!='#') e[i][j].push_back(II(i,j-1));
                if (s[i][j]=='N'&&i-1>=1&&s[i-1][j]!='#') e[i][j].push_back(II(i-1,j));
            }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (!num[i][j])
                visit(i,j);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            int tmp1=pos[i][j];
            for (int k=0; k<(int)e[i][j].size(); k++)
            {
                II v=e[i][j][k];
                int tmp2=pos[v.fs][v.sc];
                if (tmp1==tmp2||dd[tmp1][tmp2]) continue;
                dd[tmp1][tmp2]=1;
                edge[tmp1].push_back(tmp2);
            }
        }
    id=dem;
    for (int i=1; i<=dem; i++)
        if (check[i]==0) dfs(i);
    f[dem]=a[loc[dem]];
    for (int i=dem-1; i>=1; i--)
    {
        int u=loc[i];
        f[i]=a[loc[i]];
        for (int j=0; j<int(edge[u].size()); j++)
        {
            int v=edge[u][j];
            f[i]=max(f[i],f[vis[v]]+a[loc[i]]);
        }
        res=max(res,f[i]);
    }
    cout<<res;
    return 0;
}
