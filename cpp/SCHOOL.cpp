#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int d[maxn][65],f[2][maxn];
int n,m,k;
struct data
{
        int v,let,xe,val,t;
};
vector<data> e[maxn],ngc[maxn];
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.val>b.val;
        }
};
void dijks(int tx)
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        for (int i=1;i<=n;++i)
                f[tx][i]=1e9;
        if (tx==0)
        {
                f[tx][k]=0;
                q.push({k,0,0,0,0});
        }
        else
        {
                f[tx][n]=0;
                q.push({n,0,0,0,0});
        }
        while(!q.empty())
        {
                int u=q.top().v;
                int val=q.top().val;
                q.pop();
                if (val!=f[tx][u]) continue;
                for (int i=0;i<ngc[u].size();++i)
                {
                        int v=ngc[u][i].v;
                        int t;
                        if (tx==0) t=ngc[u][i].let;
                        else t=ngc[u][i].xe;
                        if (f[tx][u]+t<f[tx][v])
                        {
                                f[tx][v]=f[tx][u]+t;
                                q.push({v,0,0,f[tx][v],0});
                        }
                }
        }
}
void dijkstra()
{
        for (int i=1;i<=n;++i)
                for (int j=0;j<=59;++j)
                d[i][j]=1e9;
        d[1][0]=0;
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        q.push({1,0,0,0,0});
        while(!q.empty())
        {
                int u=q.top().v;
                int t=q.top().t;
                int val=q.top().val;
                q.pop();
                if (val!=d[u][t]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        int l=e[u][i].xe;
                        if (t+l>59) continue;
                        if (d[u][t]+l<d[v][t+l])
                        {
                                d[v][t+l]=d[u][t]+l;
                                q.push({v,0,0,d[v][t+l],t+l});
                        }
                }
        }
}
int main()
{
        freopen("SCHOOL.inp","r",stdin);
        freopen("SCHOOL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        for (int i=1;i<=m;++i)
        {
                int u,v,let,xe;
                cin>>u>>v>>let>>xe;
                e[u].push_back({v,let,xe,0,0});
                ngc[v].push_back({u,let,xe,0,0});
        }
        dijks(0);
        dijks(1);
        dijkstra();
        int res=1e9;
        for (int i=1;i<=n;++i)
        {
                int tmp=1e9;
                int x=f[0][i];
                for (int j=0;j<=59-x;++j)
                        tmp=min(tmp,d[i][j]+f[1][i]);
                res=min(res,tmp);
        }
        cout<<res;
        return 0;
}
