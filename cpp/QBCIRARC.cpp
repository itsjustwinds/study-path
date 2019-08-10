#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,c[maxn][maxn],check[maxn],dd[maxn],ok,pre[maxn];
struct data
{
        int u,v;
};
vector<int > e[maxn];
vector<data > res,E,edge;
void dfs(int u,data x)
{
        dd[u]=1;
        check[u]=1;
        for (int i=0; i<e[u].size(); ++i)
        {
                if (ok) return;
                int v=e[u][i];
                data tmp;
                tmp.u=u;
                tmp.v=v;
                if (tmp.u==x.u&&tmp.v==x.v) continue;
                if (check[v])
                {
                        ok=1;
                        if (x.u!=-1||x.v!=-1) continue;
                        E.push_back({u,v});
                        int Ux=u;
                        while(Ux!=v)
                        {
                                E.push_back({pre[Ux],Ux});
                                Ux=pre[Ux];
                        }
                        return;
                }
                if (ok) return;
                if (dd[v]) continue;
                pre[v]=u;
                dfs(v,x);
        }
        check[u]=0;
}
bool cmp(data a,data b)
{
        if (a.u!=b.u) return a.u<b.u;
        return a.v<b.v;
}
int main()
{
        freopen("QBCIRARC.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1; i<=m; ++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                edge.push_back({u,v});
                c[u][v]++;
        }
        for (int i=1; i<=n; ++i)
                if (!dd[i])
                {
                        dfs(i, {-1,-1});
                        if (ok) break;
                }
        int st=E.size();
        for (int i=0;i<st;++i)
        {
                if (c[E[i].u][E[i].v]>1) continue;
                memset(dd,0,sizeof dd);
                memset(check,0,sizeof check);
                ok=0;
                for (int j=1;j<=n;++j)
                        if (!dd[j])
                {
                        dfs(j,{E[i].u,E[i].v});
                        if (ok) break;
                }
                if (!ok) res.push_back({E[i].u,E[i].v});
        }
        if (res.size()==0)
        {
                cout<<-1;
                return 0;
        }
        cout<<res.size()<<"\n";
        sort(res.begin(),res.end(),cmp);
        for (int i=0;i<res.size();++i)
                cout<<res[i].u<<" "<<res[i].v<<"\n";
        return 0;
}
