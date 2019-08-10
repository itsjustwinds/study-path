#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPD(i, n) for (int i = n - 1; i >= 0; --i)
#define FORE(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(v) (int) v.size()
#define all(v) (v).begin(), (v).end()

#define EPS 1e-9
#define INF 1e18+7
#define PI 3.14159265358979323846
#define long long long

const int N = 444;

int n, m;
long c[N][N];

int main() {
    freopen("TOUR.INP", "r", stdin);
    //freopen("TOUR.OUT", "w", stdout);

    scanf("%d%d", &n, &m);
    FOR(i, 1, n)
        FOR(j, 1, m) c[i][j] = INF;

    while (m--) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        c[u][v] = w;
    }
    FOR(k, 1, n)
        FOR(i, 1, n)
            FOR(j, 1, n)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        if (c[u][v] > 1e9)
            puts("-1");
        else
            printf("%lld\n", c[u][v]);
    }

    return 0;
}

