#include<bits/stdc++.h>
#define maxn 200005
#define mod 1000000007
#define fs first
#define sc second
using namespace std;
vector<int > tplt[maxn];
vector<int > e[maxn],edge[maxn];
typedef pair<int,int> II;
vector<II > cau;
int n,m,dinh,low[maxn],num[maxn],cnt,pos[maxn],ans,res;
stack<int > s;
void dfs(int u,int trc)
{
        num[u]=++cnt;
        low[u]=cnt;
        s.push(u);
        for (int i=0;i<edge[u].size();++i)
        {
                int v=edge[u][i];
                if (v==trc) continue;
                if (num[v]) low[u]=min(low[u],num[v]);
                else
                {
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                }
                if (low[v]>num[u])
                {
                        cau.push_back(II(u,v));
                }
        }
        if (low[u]>=num[u])
        {
                ++dinh;
                int x=-1;
                while(x!=u)
                {
                        x=s.top();
                        s.pop();
                        pos[x]=dinh;
                        tplt[dinh].push_back(x);
                }
        }
}
int main()
{
        freopen("DATA.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                edge[u].push_back(v);
                edge[v].push_back(u);
        }
        dfs(1,-1);
        for (int i=0;i<cau.size();++i)
        {
                int u=cau[i].fs;
                int v=cau[i].sc;
                u=pos[u];
                v=pos[v];
                e[u].push_back(v);
                e[v].push_back(u);
        }
        res=1;
        for (int i=1;i<=dinh;++i)
        if (e[i].size()<=1)
        {
              ++ans;
              res=(1ll*res*tplt[i].size())%mod;
        }
        cout<<ans<<" "<<res;
        return 0;
}
