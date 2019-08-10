#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,k,res;
vector<int> e[maxn];
int dfs(int u)
{
            int d=1;
            for (int i=0;i<(int)e[u].size();++i)
            {
                        int v=e[u][i];
                        d+=dfs(v);
            }
            if (d>=k)
            {
                        ++res;
                        return 0;
            }
            return d;
}
int main()
{
            freopen("V8ORG.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>k;
            cin>>n;
            for (int i=2;i<=n;++i)
            {
                        int v;
                        cin>>v;
                        e[v].push_back(i);
            }
            dfs(1);
            cout<<res;
            return 0;
}
