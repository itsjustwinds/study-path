#include <bits/stdc++.h>
using namespace std;
int a[101][101],f[101][101],dem[101],lh[101][101],vt[101];
int dd[101],chosen[101][101],maxn;
int n,m,d;
void find(int k)
{
    for (int i=2; i<=n; i++)
        if (dd[i]==1&&chosen[i][k]==1)
        {
            dd[i]=0;
            dem[d]++;
            lh[d][dem[d]]=i;
            vt[i]=d;
            find(i);
        }
}
void result(int t)
{
    if (t<maxn) maxn=t;
}
void try1(int i,int t)
{
    if (t>maxn) return;
    for (int j=1; j<=n; j++)
        if (dd[j]==0)
            for(int m=1; m<=n; m++)
                if (dd[m]==1 && chosen[j][m]==0)
                {
                    for (int s=1; s<=dem[vt[m]]; s++)
                        dd[lh[vt[m]][s]]=0;
                    if (i==d) result(t+a[j][m]);
                    else try1(i+1,t+a[j][m]);
                    for (int s=1; s<=dem[vt[m]]; s++)
                        dd[lh[vt[m]][s]]=1;
                }
}
int main()
{
    freopen("network.inp","r",stdin);
    freopen("network.out","w",stdout);
    std::ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        chosen[x][y]=1;
        chosen[y][x]=1;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if (chosen[i][j]) f[i][j]=a[i][j];
        }
    for(int i=1; i<=n; i++)
        dd[i]=1;
    for (int i=1; i<=n; i++)
        if (dd[i]==1)
        {
            d++;
            dd[i]=0;
            dem[d]++;
            lh[d][dem[d]]=i;
            vt[i]=d;
            find(i);
        }
    for(int i=1; i<=n; i++)
        dd[i]=1;
    if (d==1) cout<<0;
    else
    {
        for (int i=1; i<=dem[1]; i++)
            dd[lh[1][i]]=0;
        maxn=1000000000;
        try1(2,0);
        cout<<maxn;
    }
}
