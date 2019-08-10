#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
        int u,v,id;
        ll val;
};
int n,m,O,s,t;
ll d[maxn];
data edge[maxn];
vector<data > e[maxn];
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.val>b.val;
        }
};
void dijks()
{
        for (int i=1;i<=m;++i)
                d[i]=1e18;
        priority_queue<data,vector<data>,cmp > q;
        for (int i=0;i<e[s].size();++i)
        {
                data tmp=e[s][i];
                int id=tmp.id;
                d[id]=tmp.val;
                q.push({s,tmp.v,id,d[id]});
        }
        while(!q.empty())
        {
                data tmp=q.top();
                q.pop();
                if (tmp.val!=d[tmp.id]) continue;
                int v=tmp.v;
                for (int i=0;i<e[v].size();++i)
                {
                        data T=e[v][i];
                        int id=T.id;
                        int val=T.val;
                        if (d[tmp.id]+val+tmp.id*O+id<d[id])
                        {
                                d[id]=d[tmp.id]+tmp.id*O+id+val;
                                q.push({T.u,T.v,id,d[id]});
                        }
                }
        }
}
int main()
{
        freopen("METRO.inp","r",stdin);
        freopen("METRO.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>s>>t>>O;
        for (int i=1;i<=m;++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                edge[i]={u,v,i,c};
                e[u].push_back(edge[i]);
        }
        dijks();
        ll res=1e18;
        for (int i=1;i<=m;++i)
        if (edge[i].v==t)
        {
                res=min(res,d[i]);
        }
        if (res==1e18) cout<<-1;
        else cout<<res;
        return 0;
}
