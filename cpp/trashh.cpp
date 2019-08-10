#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int deg[maxn],f[maxn],n,trace[maxn],maxx,k;
vector <int> w[maxn];
int main()
{
    freopen("trashh.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        w[u].push_back(v);
        w[v].push_back(u);
    }
    for (int i=0; i<=n; i++)
        trace[i]=-1;
    for (int i=n-1; i>=0; i--)
    {
        for (int j=0; j<deg[i]; j++)
            if (f[w[i][j]]+1>f[i])
            {
                int t=w[i][j];
                f[i]=f[t]+1;
                trace[i]=t;
                for (int q=0; q<deg[i]; q++)
                {
                    int m=w[i][q];
                    if (m==trace[t])
                    {
                        f[t]++;
                        trace[t]=i;
                    }
                }
            }
        if (f[i]>=f[k])
        {
            k=i;
        }
    }
    cout<<k<<" "<<f[k];
    return 0;
}
