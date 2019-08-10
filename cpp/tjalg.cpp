#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,m,low[maxn],num[maxn],dem,res;
stack<int> s;
vector <int> e[maxn];
void visit(int u)
{
    low[u]=num[u]=++dem;
    s.push(u);
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i];
        if (num[v])
            low[u]=min(low[u], num[v]);
        else
        {
            visit(v);
            low[u]=min(low[u], low[v]);
        }
    }
    if (num[u]==low[u])
    {
        res++;
        int v;
        while(v!=u)
        {
            v=s.top(); s.pop();
            num[v]=low[v]=100000000;
           cout<<v<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    freopen("tjalg.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
        if (!num[i])
            visit(i);
    cout<<res;
    return 0;
}

