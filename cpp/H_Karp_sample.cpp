
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

struct HopcroftKarp
{
        const int NIL = 0;
        const int inf = 1e9;
        int n, m;
        vector<int> d, match;
        vector<vector<int> > e;

        void enter()
        {
                cin>>n>>m;
                d.resize(n + m + 1);
                match.resize(n + m + 1);
                e.resize(n + m + 1);
                int u, v;
                FOR(i, 1, m + n) match[i] = 0;
                while (cin>>u>>v)
                {
                        //if (u == 0) return;
                        v += n;
                        e[u].push_back(v);
                        e[v].push_back(u);
                }
        }

        int getMaxMatching()
        {
                int matching = 0;
                while (bfs())
                {
                        FOR(i, 1, n)
                        {
                                if (match[i] == NIL && dfs(i))
                                        matching++;
                        }
                }
                return matching;
        }

        void traceEdge()
        {
                FOR(i, 1, n)
                {
                        if (match[i] != NIL)
                        {
                                cout<<i<<' '<<match[i] - n<<endl;
                        }
                }
        }
private:
        bool bfs()
        {
                queue<int> q;
                FOR(i, 1, n)
                {
                        if (match[i] == NIL)
                        {
                                d[i] = 0;
                                q.push(i);
                        }
                        else d[i] = inf;
                }
                d[NIL] = inf;
                while (!q.empty() && d[NIL] == inf)
                {
                        int u = q.front();
                        q.pop();
                        for (int v: e[u])
                        {
                                if (d[match[v]] == inf)
                                {
                                        d[match[v]] = d[u] + 1;
                                        q.push(match[v]);
                                }
                        }
                }
                return d[NIL] != inf;
        }

        bool dfs(int u)
        {
                if (u != NIL)
                {
                        for (int v : e[u])
                        {
                                if (d[match[v]] == d[u] + 1)
                                {
                                        if (dfs(match[v]))
                                        {
                                                match[v] = u;
                                                match[u] = v;
                                                return true;
                                        }
                                }
                        }
                        d[u] = inf;
                        return false;
                }
                return true;
        }

} HK;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        HK.enter();
        cout<<HK.getMaxMatching()<<endl;
        HK.traceEdge();
}
