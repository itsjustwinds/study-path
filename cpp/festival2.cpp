
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

template <class T> int GetBit(T x, int k) { return (x >> (k - 1)) & 1; }
template <class T> T OnBit(T x, int k) { return x | (T(1) << (k - 1)); }

const int N = 44;

int n, k;
long m, a[N], f[1 << 20], ans;

int main() {
    freopen("FESTIVAL.INP", "r", stdin);
    //freopen("FESTIVAL.OUT", "w", stdout);

    scanf("%d%lld", &n, &m);
    FOR(i, 1, n) scanf("%lld", &a[i]);
    k = n - (n >> 1);
    REP(mask, 1 << (n >> 1)) {
        if (!mask) continue;
        FOR(i, 1, n >> 1)
            if (GetBit(mask, i))
                f[mask] += a[i];
        ans += f[mask] <= m;
    }
    sort(f, f + (1 << (n >> 1)));
    REP(mask, 1 << (k)) {
        if (!mask) continue;
        long sum = 0;
        FOR(i, (n >> 1) + 1, n)
            if (GetBit(mask, i - (n >> 1)))
                sum += a[i];
        int l = 0, r = (1 << (n >> 1)) - 1, now = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (f[mid] + sum <= m) {
                now = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        ans += (now != -1) * (now + 1);
    }
    printf("%lld", ans);
    return 0;
}
