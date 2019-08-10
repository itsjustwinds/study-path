#include<bits/stdc++.h>
#define maxn 1005
#define db double
using namespace std;
db d[maxn][20],res;
int n,m,k;
struct data
{
        int v,k;
        db val;
};
vector<data > e[maxn];
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.val>b.val;
        }
};
void dijkstra()
{
        priority_queue<data,vector<data>,cmp > q;
        d[1][0]=0;
        q.push({1,0,0});
        while(!q.empty())
        {
                data tmp=q.top();
                int u=q.top().v;
                int t=q.top().k;
                q.pop();
                if (tmp.val!=d[u][t]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        db c=e[u][i].val;
                        c*=2;
                        for (int j=t;j<=k;++j)
                        {
                                c/=2;
                                if (d[u][t]+c<d[v][j])
                                {
                                        d[v][j]=d[u][t]+c;
                                        q.push({v,j,d[v][j]});
                                }
                        }
                }
        }
}
int main()
{
        freopen("NETACCEL.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                e[u].push_back({v,0,(db)c});
                e[v].push_back({u,0,(db)c});
        }
        for (int i=1;i<=n;++i)
                for (int j=0;j<=k;++j)
                d[i][j]=1e18;
        dijkstra();
        res=1e18;
        for (int i=0;i<=k;++i)
                res=min(res,d[n][k]);
        cout<<setprecision(2)<<fixed<<res;
        return 0;
}
