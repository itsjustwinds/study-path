#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
#define fs first
#define sc second
#define oo 1111111111
using namespace std;
int n,m;
int d[maxn];
typedef pair<int,int> II;
vector<II> e[maxn];
void dijkstra(int s)
{
        priority_queue <II, vector<II>, greater<II> > q;
        while(!q.empty()) q.pop();
        q.push(II(0,s));
        int dem=0;
        int ok=0;
        while(!q.empty())
        {
                II tmp=q.top();
                q.pop();
                int u=tmp.sc;
                int du=tmp.fs;
                if (dem)if (du!=d[u]) continue;
                if (u==s&&d[u]!=oo) return;
                for (int i=0; i<(int)e[u].size(); i++)
                {
                        int len=e[u][i].fs;
                        int v=e[u][i].sc;
                        if (d[v]>du+len)
                        {
                                d[v]=du+len;
                                q.push(II(d[v],v));
                        }
                }
                ++dem;
        }
}
int main()
{
        freopen("TOURS13.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        int test;
        scanf("%d",&test);
        while(test--)
        {
                scanf("%d %d",&n,&m);
                for (int i=1; i<=n; i++)e[i].clear();
                for (int i=1; i<=m; i++)
                {
                        int u,v,c;
                        scanf("%d %d %d",&u,&v,&c);
                        e[u].push_back(II(c,v));
                }
                for (int i=1; i<=n; i++)
                {
                        for (int j=1; j<=n; j++)d[j]=oo;
                        dijkstra(i);
                        if (d[i]!=oo) printf("%d \n",d[i]);
                        else printf("-1\n");
                }
        }
        return 0;
}
