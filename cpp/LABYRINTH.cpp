#include <bits/stdc++.h>
#define maxn 1005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
char s[maxn][maxn],res[maxn];
II trace[maxn][maxn];
int n,m,x1,x2,x3,x4,dem,ok;
void try1(int x,int y)
{
    if (s[x][y]=='#') return;
    if (ok==1) return;
    s[x][y]='#';
    if (x==1||y==1||x==n||y==m)
    {
        ok=1;
        x3=x;
        x4=y;
        return;
    }
    if (s[x-1][y]!='#')
    {
        trace[x-1][y]=II(x,y);
        try1(x-1,y);
    }
    if (s[x][y+1]!='#')
    {
        trace[x][y+1]=II(x,y);
        try1(x,y+1);
    }
    if (s[x+1][y]!='#')
    {
        trace[x+1][y]=II(x,y);
        try1(x+1,y);
    }
    if (s[x][y-1]!='#')
    {
        trace[x][y-1]=II(x,y);
        try1(x,y-1);
    }
}
int main()
{
    freopen("labyrinth.inp","r",stdin);
    freopen("labyrinth.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            cin>>s[i][j];
            if (s[i][j]=='*')
            {
                x1=i;
                x2=j;
            }
        }
    try1(x1,x2);
    int x=x3,y=x4;
    while (x!=x1||y!=x2)
    {
        int a=trace[x][y].fs,b=trace[x][y].sc;
        dem++;
        if (x==a-1) res[dem]='N';
        if (x==a+1) res[dem]='S';
        if (y==b-1) res[dem]='W';
        if (y==b+1) res[dem]='E';
        x=a;y=b;
    }
    for (int i=dem;i>=1;i--)
        cout<<res[i];
    return 0;
}
