#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll d[maxn][maxn],res[33005][20],maxx;
int n,m,k,s[105],x[105],dd[105];
struct data
{
        int v;
        ll val;
};
vector<data > e[maxn];
struct cmp
{
        bool operator () (const data &a,const data &b)
        {
                return a.val>b.val;
        }
};
void dijks(int tx)
{
        priority_queue<data,vector<data>,cmp >q;
        while(!q.empty()) q.pop();
        d[tx][tx]=0;
        q.push({tx,0});
        while(!q.empty())
        {
                int u=q.top().v;
                ll val=q.top().val;
                q.pop();
                if (d[tx][u]!=val) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        int l=e[u][i].val;
                        if (d[tx][u]+l<d[tx][v])
                        {
                                d[tx][v]=d[tx][u]+l;
                                q.push({v,d[tx][v]});
                        }
                }
        }
}
int getbit(const int &x,const int &k)
{
        return x&(1<<(k-1));
}
int light_out(const int &x,const int &k)
{
        return x^(1<<(k-1));
}
int main()
{
        freopen("TOUR.inp","r",stdin);
        //freopen("TOUR.out","w",stdout);
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=k;++i)
                scanf("%d",&s[i]);
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                scanf("%d%d%d",&u,&v,&c);
                e[u].push_back({v,c});
        }
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                d[i][j]=1e18;
        dijks(1);
        for (int i=1;i<=k;++i)
                dijks(s[i]);
        maxx=(1<<k)-1;
        for (int i=1;i<=maxx;++i)
        for (int j=1;j<=k;++j)
                res[i][j]=1e18;
        for (int i=1;i<=k;++i)
        {
                res[1<<(i-1)][i]=d[1][s[i]];
        }
        for (int i=1;i<=maxx;++i)
        {
                for (int x=1;x<=k;++x)
                {
                        if (!getbit(i,x)) continue;
                        for (int y=1;y<=k;++y)
                        {
                                if (y==x) continue;
                                if (!getbit(i,y)) continue;
                                res[i][x]=min(res[i][x],res[light_out(i,x)][y]+d[s[y]][s[x]]);
                        }
                }
        }
        ll minn=1e18;
        for (int i=1;i<=k;++i)
                minn=min(minn,res[maxx][i]+d[s[i]][1]);
        if (minn==1e18) printf("-1");
        else printf("%lld",minn);
        return 0;
}
