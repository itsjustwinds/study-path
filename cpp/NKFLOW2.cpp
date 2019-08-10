#include <bits/stdc++.h>

using namespace std;

#define N 1010

int m, n, s, t, c[N][N], f[N][N], trace[N];
queue<int> q;
vector<int> e[N];
bool fr[N];

bool bfs(int s, int t) {
    memset(fr, true, sizeof fr);
    fr[s] = false;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for (auto v: e[u]) {
            if (fr[v] && (c[u][v] - f[u][v] > 0)) {
                fr[v] = false;
                trace[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}
int main() {
    freopen("NKFLOW.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>t;
    int u, v, w;
    memset(c, 0, sizeof c);
    for (int i = 0; i<m; i++) {
        cin>>u>>v>>w;
        e[u].push_back(v);
        e[v].push_back(u);
        c[u][v] = w;
    }
    long long ans = 0;
    while (bfs(s, t)) {
        int maxflow = 1e9;
        for (int v = t; v != s;) {
            int u = trace[v];
            maxflow = min(maxflow, c[u][v] - f[u][v]);
            v = u;
        }
        for (int v = t; v != s;) {
            int u = trace[v];
            f[u][v] += maxflow;
            f[v][u] -= maxflow;
            v = u;
        }
        ans += maxflow;
    }
    cout<<ans;
}

