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
#define INF 1e9+7
#define PI 3.14159265358979323846
#define long long long

typedef pair <int, int> ii;

const int N = 1e5 + 10;

int n, m, par[N];

int anc(int p) { return par[p] == p ? p : (par[p] = anc(par[p])); }
void join(int p, int q) { par[anc(p)] = anc(q); }

int main() {
    freopen("SINGERS.INP", "r", stdin);
    //freopen("SINGERS.OUT", "w", stdout);

    scanf("%d%d", &n, &m);
    FOR(i, 1, n) par[i] = i;
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        join(u, v);
    }
    FOR(i, 1, n) par[i] = anc(par[i]);
    sort(par + 1, par + n + 1);
    vector <int> a;
    for (int i = 1; i <= n; ) {
        int j = i;
        while (par[i] == par[j] && j <= n) j++;
        a.push_back(j - i);
      //  cout << i << " " << j << "\n";
        i = j;
    }
    long ans = 0;
    if (sz(a) == 1) {
        puts("0");
        return 0;
    }
    long sum = 0;
    REP(i, sz(a)) {
        ans += sum * a[i];
        sum += a[i];
    }
    printf("%lld", ans);

    return 0;
}

