#include<bits/stdc++.h>
#define fs first
#define sc second
#define maxn 100000
#define ll long long
#define oo 10000000000000LL
using namespace std;
typedef pair<ll,ll> II;
ll n,m,d[maxn],res[maxn];
vector<II> e[maxn];
struct cmp{
bool operator() (II a,II b) {return a.sc<b.sc;}
};
void dijk()
{
    res[1]=1;
    priority_queue<II,vector<II>,cmp > q;
    for (int i=1;i<=n;i++)
        d[i]=oo;
    d[1]=0;
    q.push(II(1,0));
    while(!q.empty())
    {
        ll u=q.top().fs;
        ll du=-q.top().sc;
        q.pop();
        if (d[u]!=du) continue;
        if (u==n)
        {
            cout<<d[u]<<" "<<res[u];
            return;
        }
        for (int i=0;i<(int)e[u].size();i++)
        {
            ll v=e[u][i].fs;
            ll l=e[u][i].sc;
            if (d[v]>d[u]+l)
            {
                d[v]=d[u]+l;
                res[v]=res[u];
                q.push(II(v,-d[v]));
            }
            else if (d[v]==d[u]+l)
            {
                res[v]+=res[u];
            }
        }
    }
}
int main()
{
    freopen("qbschool.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        ll k,u,v,l;
        cin>>k>>u>>v>>l;
        e[u].push_back(II(v,l));
        if (k==2) e[v].push_back(II(u,l));
    }
    dijk();
}
