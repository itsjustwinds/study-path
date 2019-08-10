#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        int v;
        ll h,t;
};
int n,m,s,t;
ll maxx;
vector<vector<ll> > f;
vector<data > e[maxn];
vector<vector<data> > trc;
vector<int > res;
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.h<b.h;
        }
};
void dijks(int s)
{
        priority_queue<data,vector<data>,cmp > q;
        q.push({s,maxx,0});
        f[s][maxx]=0;
        while(!q.empty())
        {
                int u=q.top().v;
                ll hu=q.top().h;
                ll tu=q.top().t;
                q.pop();
                if(tu!=f[u][hu]) continue;
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i].v;
                        ll hv=min(hu,e[u][i].h);
                        ll tv=e[u][i].t;
                        if (f[u][hu]+tv<f[v][hv])
                        {
                                f[v][hv]=f[u][hu]+tv;
                                q.push({v,hv,f[v][hv]});
                                trc[v][hv]={u,hu,0};
                        }
                }
        }
}
int main()
{
        freopen("HEIGHT.inp","r",stdin);
        freopen("HEIGHT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>s>>t;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                ll h,d;
                cin>>u>>v>>h>>d;
                e[u].push_back({v,h,d});
                e[v].push_back({u,h,d});
                maxx=max(maxx,h);
        }
        f.resize(n+1);
        trc.resize(n+1);
        for (int i=1;i<=n;++i)
        {
                f[i].resize(maxx+1);
                trc[i].resize(maxx+1);
        }
        for (int i=1;i<=n;++i)
                for (int j=0;j<=maxx;++j)
                f[i][j]=1e18;
        dijks(s);
        for (int i=maxx;i>=1;--i)
        if (f[t][i]!=1e18)
        {
                int u=t,hu=i;
                res.push_back(u);
                //cout<<f[u][hu]<<"\n";
                while(u!=s)
                {
                        data tmp=trc[u][hu];
                        u=tmp.v;
                        hu=tmp.h;
                        res.push_back(u);
                //cout<<f[u][hu]<<"\n";
                }
                cout<<res.size()<<"\n";
                for (int i=res.size()-1;i>=0;--i)
                        cout<<res[i]<<" ";
                return 0;
        }
}
