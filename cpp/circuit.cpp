#include<bits/stdc++.h>
#include<fstream>
#define fs first
#define sc second
#define maxn 100005
using namespace std;
ifstream fi("circuit.inp");
ofstream fo("circuit.out");
int dd[maxn],n,m,fr[maxn],ok;
typedef pair<int,int> II;
vector<II> e[maxn];
II trace[maxn];
void dfs(int u)
{
    if (ok==1) return;
    dd[u]=1;
    if (fr[u]==1)
    {
        fo<<"YES\n";
        int ok1=0;
        int v=u;
        while(ok1==0)
        {
            fo<<trace[u].sc<<" ";
            u=trace[u].fs;
            if (v==u) ok1=1;
        }
        ok=1;
    }
    fr[u]=1;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        II v=e[u][i];
        trace[u]=II(v.fs,v.sc);
        dfs(v.fs);
        if (ok==1) return;
    }
    fr[u]=0;
}
int main()
{
    //freopen("circuit.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        fi>>u>>v;
        e[u].push_back(II(v,i));
    }
    for (int i=1; i<=n; i++)
        if (dd[i]==0)
        {
            dfs(i);
            if (ok==1) return 0;
        }
    fo<<"NO";
    return 0;
}
