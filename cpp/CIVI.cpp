#include<bits/stdc++.h>
#define maxn 300005
#define fs first
#define sc second
using namespace std;
int n,m,pos[maxn],test,val[maxn],dd[maxn],cnt,mark[maxn],root[maxn];
vector<int > e[maxn];
typedef pair<int,int >II;
void dfs(int u)
{
        pos[u]=cnt;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (pos[v]) continue;
                dfs(v);
        }
}
int getroot(int u)
{
        if (root[u]==u) return u;
        root[u]=getroot(root[u]);
        return root[u];
}
void bfs(int U)
{
        queue<II > q;
        while(!q.empty()) q.pop();
        q.push(II(U,0));
        memset(mark,0,sizeof mark);
        mark[U]=1;
        int Ux=U;
        int k=0;
        while(!q.empty())
        {
                int u=q.front().fs;
                int dtmp=q.front().sc;
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (mark[v]) continue;
                        mark[v]=1;
                        if (dtmp+1>k)
                        {
                                k=dtmp+1;
                                Ux=v;
                        }
                        q.push(II(v,dtmp+1));
                }
        }
        memset(mark,0,sizeof mark);
        q.push(II(Ux,0));
        k=0;
        while(!q.empty())
        {
                int u=q.front().fs;
                int dtmp=q.front().sc;
                q.pop();
                for (int i=0;i<e[u].size();++i)
                {
                        int v=e[u][i];
                        if (mark[v]) continue;
                        mark[v]=1;
                        if (dtmp+1>k) k=dtmp+1;
                        q.push(II(v,dtmp+1));
                }
        }
        val[pos[U]]=k;
}
int main()
{
        freopen("CIVI.inp","r",stdin);
        freopen("CIVI.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>test;
        for (int i=1;i<=m;++i)
        {
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
        }
        for (int i=1;i<=n;++i)
        if (!pos[i])
        {
                ++cnt;
                dfs(i);
        }
        for (int i=1;i<=n;++i)
        if (!val[pos[i]]) bfs(i);
        for (int i=1;i<=cnt;++i) root[i]=i;
        while(test--)
        {
                int x,y,u,v;
                cin>>x;
                if (x==1)
                {
                        cin>>u;
                        cout<<val[getroot(pos[u])]<<"\n";
                        continue;
                }
                cin>>u>>v;
                u=getroot(pos[u]);
                v=getroot(pos[v]);
                if (u==v) continue;
                root[v]=u;
                x=(val[u]+1)/2;
                y=(val[v]+1)/2;
                val[u]=max(x+y+1,max(val[u],val[v]));
        }
        return 0;
}
