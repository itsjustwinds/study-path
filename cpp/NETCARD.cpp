#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int dd[maxn],n,k;
struct data
{
        int u,v,c;
};
vector<data >edge;
int main()
{
        freopen("NETCARD.inp","r",stdin);
        freopen("NETCARD.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                dd[i]=2;
        for (int i=1;i<=k;++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                if (c==1)
                {
                        dd[u]=1;
                        dd[v]=1;
                }
                edge.push_back({u,v,c});
        }
        for (int i=0;i<edge.size();++i)
        {
                int u=edge[i].u;
                int v=edge[i].v;
                int c=edge[i].c;
                if (c==1) continue;
                if (dd[u]==1)
                {
                      dd[v]=0;
                      continue;
                }
                if (dd[v]==1)
                {
                        dd[u]=0;
                        continue;
                }
        }
        for (int i=1;i<=n;++i)
                cout<<dd[i]<<" ";
}
