#include<bits/stdc++.h>
#define maxn 30
#define fs first
#define sc second
#define oo 1000000005
using namespace std;
char s[maxn][maxn];
int n,m,d[maxn][maxn];
typedef pair<int,int> II;
vector<II> e[maxn][maxn];
typedef pair<int,II> III;
void dijkstra()
{
    priority_queue<III> q;
    while(!q.empty()) q.pop();
    for (int x=1; x<=n; x++)
        for (int y=1; y<=m; y++)
            d[x][y]=oo;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (s[i][j]=='S')
            {
                d[i][j]=0;
                q.push(III(0,II(i,j)));
            }
    while(!q.empty())
    {
        int du=-q.top().fs;
        II u=q.top().sc;
        q.pop();
        if (du!=d[u.fs][u.sc])continue;
        if (s[u.fs][u.sc]=='D')
        {
            cout<<d[u.fs][u.sc]<<"\n";
            return;
        }
        for (int i=0; i<(int)e[u.fs][u.sc].size(); i++)
        {
            II v=e[u.fs][u.sc][i];
            if (s[v.fs][v.sc]-'0'>=0&&s[v.fs][v.sc]-'0'<=9&&d[v.fs][v.sc]>d[u.fs][u.sc]+s[v.fs][v.sc]-'0')
            {
                d[v.fs][v.sc]=d[u.fs][u.sc]+s[v.fs][v.sc]-'0';
                q.push(III(-d[v.fs][v.sc],II(v.fs,v.sc)));
            }
            else if (s[v.fs][v.sc]=='D')
            {
                cout<<d[u.fs][u.sc]<<"\n";
                return ;
            }
        }
    }
}
int main()
{
    freopen("shop.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>m>>n)
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                cin>>s[i][j];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                e[i][j].clear();
                if (i>1&&s[i-1][j]!='X') e[i][j].push_back(II(i-1,j));
                if (i<n&&s[i+1][j]!='X') e[i][j].push_back(II(i+1,j));
                if (j>1&&s[i][j-1]!='X') e[i][j].push_back(II(i,j-1));
                if (j<m&&s[i][j+1]!='X') e[i][j].push_back(II(i,j+1));
            }
        dijkstra();
    }
}
