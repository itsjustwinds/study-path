#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORE(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)
#define long long long

template <class T> T GetBit(T x, int k) { return x >> k & 1; }
template <class T> T OnBit(T x, int k) { return x | (T(1) << k); }
template <class T> T OffBit(T x, int k) { return x & (~(T(1) << k)); }

const int base = 1e9+7, MaxV = 3e7+5, N = 1e5+10;

int n, c;
vector <int> prime;
int f[MaxV], num[MaxV], Pw[N], PwC[N], a[MaxV];

void Sieve() {
    FOR(i, 2, MaxV) {
        if (!f[i]) {
            f[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= f[i] && prime[j] * i <= MaxV; ++j)
            f[i * prime[j]] = prime[j];
    }
}

void Process() {
    scanf("%d%d", &n, &c);
    Pw[0] = PwC[0] = 1;

    FOR(i, 1, N - 1) {
        Pw[i] = Pw[i-1] * 2 % base;
        PwC[i] = PwC[i-1] * 1ll * (c - 1) % base;
    }

    REP(love, n) {
        int x; scanf("%d", &x);
        vector <int> pr;
        while (x > 1) {
            int y = f[x];
            pr.push_back(y);
            while (x % y == 0)
                x /= y;
        }
        int tichm[512];
        tichm[0] = 1; a[1]++;
        FOR(mask, 1, (1 << pr.size()) - 1)
          REP(i, pr.size())
            if (GetBit(mask, i)) {
                int x = OffBit(mask, i);
                tichm[mask] = tichm[OffBit(mask, i)] * pr[i];
                a[tichm[mask]]++;
                num[tichm[mask]] = __builtin_popcount(mask);
                break;
            }
    }

    long res = 0;
    FOR(i, 1, MaxV - 1)
      if (a[i]) {
        long C = (Pw[a[i]] + base - 1) * 1ll * PwC[num[i]] % base;
        res = res + C - (res + C >= base) * base;
      }
    printf("%lld", res);
}

int main() {
        freopen("D:\\c++\\debug\\VO17XXX.INP", "r", stdin);
        freopen("D:\\c++\\debug\\VO17XXX.ans", "w", stdout);

    Sieve();
    Process();

    return 0;
}
