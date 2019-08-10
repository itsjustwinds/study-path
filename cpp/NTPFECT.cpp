#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,res,dd[maxn];
vector<int> e[maxn];
void dfs(int u,int trc)
{
    if (dd[u]) return;
    int ok=0;
    dd[u]=1;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i];
        if (v==trc) continue;
        ok=1;
        dfs(v,u);
    }
    if (ok) res++;
}
int main()
{
    freopen("NTPFECT.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n)
    {
        if (n==0)
        {
            return 0;
        }
        memset(dd,0,sizeof(dd));
        for (int i=1;i<=n;i++)
            e[i].clear();
        for (int i=1; i<n; i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (n<=2)
        {
            cout<<1;
            continue;
        }
        dfs(1,-1);
        if (e[1].size()==1) res--;
        cout<<res<<"\n";
    }
    return 0;
}
