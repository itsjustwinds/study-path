#include <bits/stdc++.h>
#define maxn 55
using namespace std;
int deg[maxn],deg1[maxn],n,m,res[maxn],dem,dd[maxn][maxn],dd1[maxn][maxn],demm;
vector <int> w[maxn],w1[maxn];
int main()
{
    freopen("socnet.inp","r",stdin);
    freopen("socnet.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        w[u].push_back(v);
        dd[u][v]=1;
        dd[v][u]=1;
        w[v].push_back(u);
    }
    for (int i=1; i<=n; i++) dd[i][i]=1;
    while (true)
    {
        dem++;
        demm=0;
        for (int i=1; i<=n; i++) deg1[i]=deg[i];
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dd1[i][j]=dd[i][j];
        for (int i=1; i<=n; i++) w1[i]=w[i];

        for (int i=1; i<=n; i++)
        {
            int k=deg[i];
            for (int j=0; j<k; j++)
            {
                int d=w[i][j];
                int h=deg[w[i][j]];
                for (int f=0; f<h; f++)
                    if(dd[i][w[d][f]]==0)
                    {
                        int u=w[d][f];
                        deg1[i]++;
                        deg1[u]++;
                        w1[i].push_back(u);
                        w1[u].push_back(i);
                        dd1[i][u]=1;
                        dd[i][u]=1;
                        dd[u][i]=1;
                        dd1[u][i]=1;
                        demm++;
                    }
            }
        }

        if (demm!=0)
        {
            for (int i=1; i<=n; i++) deg[i]=deg1[i];
            for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dd[i][j]=dd1[i][j];
            for (int i=1; i<=n; i++) w[i]=w1[i];
            res[dem]=demm;
        }
        else
        {
            dem--;
            break;
        }
    }
    cout<<dem<<"\n";
    for (int i=1; i<=dem; i++)
        cout<<res[i]<<"\n";
    return 0;
}
