#include<bits/stdc++.h>
#define maxn 105
#define fs first
#define sc second
using namespace std;
int f[maxn][maxn],n,d[maxn],s,t;
vector<int > e[maxn];
typedef pair<int,int >II;
struct cmp
{
        bool operator ()(II a,II b)
        {
                return a.sc>b.sc;
        }
};
void dijkstra()
{
        priority_queue<II,vector<II>,cmp > q;
        while(!q.empty()) q.pop();
        d[s]=0;
        q.push(II(s,0));
        while(!q.empty())
        {
                int u=q.top().fs;
                int c=q.top().sc;
                q.pop();
                if (c!=d[u]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        int l=f[u][v];
                        if (d[u]+l<d[v])
                        {
                                d[v]=d[u]+l;
                                q.push(II(v,d[v]));
                        }
                }
        }
}
int main()
{
        freopen("TAUDIEN.inp","r",stdin);
        freopen("TAUDIEN.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>s>>t;
        for (int i=1;i<=n;++i)
        {
                int d,u;
                cin>>d;
                for (int j=1;j<=d;++j)
                {
                        cin>>u;
                        if (j==1)
                        {
                                f[i][u]=1;
                        }
                        e[i].push_back(u);
                }
        }
        for (int i=1;i<=n;++i)
                d[i]=1e9;
        dijkstra();
        if (d[t]!=1e9)cout<<d[t];
        else cout<<-1;
        return 0;
}
