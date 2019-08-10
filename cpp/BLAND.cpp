#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 404
#define pp pair<int, int>

using namespace std;
long long s[N][N], MIN[N][N][N], MAX[N][N][N], a[N][N], ff[N], gg[N], b[N][N];
int m, n;
long long k;

long long cal(int u, int v)
{
        long long ans = -1e18;
        int start = 1;
        deque<long long> dMin, dMax;
        FOR(last, 1, n)
        {
                while (!dMin.empty() && MIN[last][u][v] <= MIN[dMin.back()][u][v]) dMin.pop_back();
                while (!dMax.empty() && MAX[last][u][v] >= MAX[dMax.back()][u][v]) dMax.pop_back();
                dMin.push_back(last);
                dMax.push_back(last);
                while (!dMin.empty())
                {
                        long long minNow = MIN[dMin.front()][u][v];
                        long long maxNow = MAX[dMax.front()][u][v];
                        if (maxNow - minNow <= k)
                        {
                                ans = max(ans, 1ll * (v - u + 1) * 1ll * (last - start + 1));
                                break;
                        }
                        while (!dMin.empty() && dMin.front() <= start) dMin.pop_front();
                        while (!dMax.empty() && dMax.front() <= start) dMax.pop_front();
                        start++;
                }
        }
        return ans;
}

long long solve()
{
        FOR(i, 1, n)
        {
                FOR(j, 1, m)
                {
                        MAX[i][j][j] = MIN[i][j][j] = a[j][i];
                        FOR(k, j + 1, m)
                        {
                                MAX[i][j][k] = max(MAX[i][j][k - 1], a[k][i]);
                                MIN[i][j][k] = min(MIN[i][j][k - 1], a[k][i]);
                        }
                }
        }
        long long ans = -1e18;
        FOR(i, 1, m) ff[i] = gg[i] = -1e18;
        FOR(i, 1, m)
        {
                FOR(j, i, m)
                {
                        long long f = cal(i, j);
                        ff[j] = max(f, ff[j]);
                        gg[i] = max(gg[i], f);
                }
        }
        FOR(i, 2, m) ff[i] = max(ff[i], ff[i - 1]);
        FORD(i, m - 1, 1) gg[i] = max(gg[i], gg[i + 1]);
        FOR(i, 1, m - 1)
        {
                if (ff[i] != -1e18 && gg[i + 1] != -1e18)
                {
                        ans = max(ans, gg[i + 1] + ff[i]);
                }
        }
        return ans;
}
int main()
{
        freopen("BLAND.inp","r",stdin);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin>>m>>n>>k;
        FOR(i, 1, m) FOR(j, 1, n)
        {
                cin>>a[i][j];
                b[j][i] = a[i][j];
        }
        long long ans = solve();
        swap(n, m);
        FOR(i, 1, m) FOR (j, 1, n) a[i][j] = b[i][j];
        ans = max(ans, solve());
        cout<<ans;
}

