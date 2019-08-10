#include<bits/stdc++.h>
#define maxn 405
#define fs first
#define sc second
using namespace std;
int a[maxn][maxn];
typedef pair<int,int> II;
int n,dd[maxn][maxn],cnt;
vector<II > P[maxn*maxn];
void mark(int Sl,int Sr)
{
    for (int i=Sl;i<=Sl+n-1;++i)
        for (int j=Sr;j<=Sr+n-1;++j)
    {
        P[cnt].push_back(II(i,j));
        dd[i][j]=cnt;
    }
}
bool check(int i,int j,int k)
{
    int pos=dd[i][j];
    for (int h=1;h<=n*n;++h)
    {
        if (a[h][j]==k||a[i][h]==k) return 0;
    }
    for (int i=0;i<P[pos].size();++i)
    {
        int u=P[pos][i].fs;
        int v=P[pos][i].sc;
        if (a[u][v]==k) return 0;
    }
    return 1;
}
int main()
{
    freopen("SUDOKU.inp","r",stdin);
    freopen("SUDOKU.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n*n;++i)
        for (int j=1;j<=n*n;++j)
        cin>>a[i][j];
    for (int i=1;i<=n*n;++i)
        for (int j=1;j<=n*n;++j)
        if (!dd[i][j])
        {
            ++cnt;
            mark(i,j);
        }
    for (int i=1;i<=n*n;++i)
        for (int j=1;j<=n*n;++j)
    {
        if (a[i][j]) continue;
        for (int k=1;k<=n*n;++k)
        if (check(i,j,k))
        {
            a[i][j]=k;
            break;
        }
    }
    for (int i=1;i<=n*n;++i)
    {
        for (int j=1;j<=n*n;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
