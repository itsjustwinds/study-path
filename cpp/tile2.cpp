
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

const int f[] = {1, 1, 1, 2, 3, 4, 5, 7, 10, 14, 19, 26, 36, 50, 69, 95, 131, 181, 250, 345, 476, 657, 907, 1252, 1728, 2385, 3292, 4544, 6272, 8657, 11949, 16493, 22765, 31422, 43371, 59864, 82629, 114051, 157422, 217286};
const int N = 5e5 + 50;

int n;
bool isprime[N];
vector <int> prime;

void sieve() {
    FOR(i, 2, N)
        if (!isprime[i]) {
            prime.push_back(i);
            FOR(j, 2, N / i)
                isprime[i * j] = 1;
        }
}

int main() {
    freopen("TILE.INP", "r", stdin);
    //freopen("TILE.OUT", "w", stdout);

    sieve();
    int test; scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        int now = f[n - 1];
        int l = 0, r = prime.size() - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (prime[mid] <= now) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        printf("%d\n", (ans != -1) ? ans + 1 : 0);
    }

    return 0;
}
