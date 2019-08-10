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

const int base = 1e9 + 7;

long n;
long a[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
long b[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

void mul(long f[3][3], long g[3][3]) {
    long c[3][3];
    REP(i, 3)
        REP(j, 3) {
            c[i][j] = 0;
            REP(k, 3)
                c[i][j] = (c[i][j] + f[i][k] * g[k][j]) % base;
        }
    REP(i, 3)
        REP(j, 3)
            f[i][j] = c[i][j];
}

long calc(long a[3][3], long n) {
    if (n == 1) return (4 * a[0][0] + 2 * a[0][1] + a[0][2]) % base;
    calc(a, n >> 1);
    mul(a, a);
    if (n & 1)
        mul(a, b);
    return (4 * a[0][0] + 2 * a[0][1] + a[0][2]) % base;
}

int main() {
    freopen("forever.inp", "r", stdin);

    cin >> n;
    //mul(a, a);
    //REP(i, 2) {REP(j, 2) cout << a[i][j] << " "; puts("");} /*
    if (n <= 3) cout << ((n == 3) ? 4 : ((n == 2) ? 2 : 1));
    else
        cout << calc(a, n - 3);

    return 0;
}

