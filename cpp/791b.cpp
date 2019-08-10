#include<bits/stdc++.h>
#define maxn 150005
using namespace std;
int n,m,dd[maxn],dem,ok,dd2[maxn];
vector<int> e[maxn];
vector<int> q;
void dfs(int u)
{
        if (dd[u]==1) return;
    dd[u]=1;
    for (int i=0;i<int(e[u].size());i++)
    {
        int v=e[u][i];
        if (dd2[v]!=0) dd2[u]++;
        else{
            dd2[u]++;
            q.push_back(v);
        }
        dfs(v);
    }
}
int main()
{
    //freopen("791b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (ok==1) return 0;
    else if (dd[i]==0)
    {
        q.push_back(i);
        dfs(i);
        int k=int(q.size());
        for (int i=0;i<int(q.size());i++)
            if (dd2[q[i]]!=k-1)
        {
            ok=1;
            cout<<"NO";
            break;
        }
        q.clear();
    }
    cout<<"YES";
    return 0;
}
