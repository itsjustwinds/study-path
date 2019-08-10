#include<bits/stdc++.h>
#define maxn 1000005
#include <fstream>
#define ll long long
#define fs first
#define sc second
using namespace std;
ifstream fi("legacy.inp");
ofstream fo("legacy.out");
ll n,a[maxn],sum;
typedef pair<int,int> II;
int dd[maxn];
II t[maxn];
vector<int> e[maxn];
ll f[maxn],res;
ll dfs(int u)
{
    if (dd[u]==1) return f[u];
    dd[u]=1;
    int re=a[u];
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        f[v]=dfs(v);
        re+=f[v];
    }
    return re;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n;
    for (int i=1;i<=n;i++)
    {
        fi>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n-1;i++)
    {
        fi>>t[i].fs>>t[i].sc;
        e[t[i].fs].push_back(t[i].sc);
        e[t[i].sc].push_back(t[i].fs);
    }
    for (int i=1;i<=n;i++)
    if (dd[i]==0)
        f[i]=dfs(i);
    res=1000000000000LL;
    for (int i=1;i<=n-1;i++)
    {
        res=min(abs(sum-2*f[t[i].fs]),min(res,abs(sum-2*f[t[i].sc])));
    }
    fo<<res;
    fi.close();
    return 0;
}
