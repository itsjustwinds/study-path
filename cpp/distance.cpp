#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,deg[maxn];
vector <int> w[maxn];
long long res;
int main()
{
    freopen("distance.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        w[u].push_back(v);
        w[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        w[i].push_back(maxn);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<deg[i];j++)
        {
            int k=w[i][j];
            for (int h=0;h<deg[k];h++)
            {
                //int it;
                int l=w[k][h];
                vector<int>::iterator it;
                it=find(w[i].begin(),w[i].end(),l);
                    int g=it[0];
                if (it!=w[i].end()) res++;
            }
        }
    }
    cout<<res;
    return 0;
}
