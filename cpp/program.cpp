#include<bits/stdc++.h>
#define maxn 100005
#include<fstream>
#define ll long long
using namespace std;
ifstream fi("program.inp");
ofstream fo("program.out");
ll t[maxn],n,m,d[maxn],res,rem;
vector <int> e[maxn];
ll dfs(int u)
{
    if (d[u]!=0) return d[u];
    ll res=1;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        res=max(res,dfs(v)+t[v]);
    }
    rem=max(rem,res+t[u]-1);
    return res;
}
int main()
{
    //freopen("program.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n>>m;
    for (int i=1;i<=n;i++)
        fi>>t[i];
    for (int i=1;i<=m;i++)
    {
        int x,y;
        fi>>x>>y;
        e[y].push_back(x);
    }
    rem=1;
    for (int i=1;i<=n;i++)
        if (d[i]==0)
        d[i]=dfs(i);
    fo<<rem<<"\n";
    for (int i=1;i<=n;i++)
        fo<<d[i]<<"\n";
    return 0;
}
