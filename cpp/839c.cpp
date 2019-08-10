#include<bits/stdc++.h>
#define maxn 100005
#define db double
using namespace std;
vector<int>e[maxn];
int n;
db dfs(int u,int trc)
{
            int d=0;
            db s=0;
            for (int i=0;i<(int)e[u].size();++i)
            {
                        int v=e[u][i];
                        if (v==trc) continue;
                        s+=dfs(v,u);
                        ++d;
            }
            if (!d) return 0;
            return db(1+s/d);
}
int main()
{
            freopen("839C.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1;i<n;++i)
            {
                        int u,v;
                        cin>>u>>v;
                        e[u].push_back(v);
                        e[v].push_back(u);
            }
            cout<<setprecision(6)<<fixed<<dfs(1,-1);
            return 0;
}
