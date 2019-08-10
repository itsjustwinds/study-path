#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int dd[maxn],n,m,ok,now,trc[maxn];
vector<int> e[maxn];
struct data{
            int u,v;
};
data c[200005];
void dfs(int u,int t,int cnt)
{
            if (cnt==2)
            {
                        if (dd[u]!=now)
                        {
                                    dd[u]=now;
                                    trc[u]=t;
                                    return;
                        }
                        if (trc[u]==t) return;
                        ok=1;
                        cout<<now<<" "<<t<<" "<<u<<" "<<trc[u];
                        return;
            }
            for (int i=0;i<(int)e[u].size();++i)
            {
                        int v=e[u][i];
                        if (v==t) continue;
                        dfs(v,u,cnt+1);
            }
}
bool cmp (const data &a,const data &b)
{
            if (a.u!=b.u) return a.u<b.u;
            return a.v<b.v;
}
int main()
{
            freopen("TRAVEL12.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            for (int i=1;i<=m;++i)
            {
                        cin>>c[i].u>>c[i].v;
            }
            sort(c+1,c+m+1,cmp);
            int u=c[1].u;
            int v=c[1].v;
            e[u].push_back(v);
            e[v].push_back(u);
            for (int i=2;i<=m;++i)
            {
                        if (c[i].u==c[i-1].u&&c[i].v==c[i-1].v) continue;
                        u=c[i].u;
                        v=c[i].v;
                        e[u].push_back(v);
                        e[v].push_back(u);
            }
            for (int i=1;i<=n;++i)
            if (!ok)
            {
                        now=i;
                        dfs(i,-1,0);
            }
            else break;
            if (!ok)
            {
                        cout<<-1;
                        return 0;
            }
}
