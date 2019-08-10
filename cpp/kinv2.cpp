#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORE(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)
#define long long long

const int N = 2e4+10, base = 1e9;

int n, k;
int a[N];
long t[N], f[N][22];

void reset()
{
    FOR(i, 1, n) t[i] = 0;
}

void update(int x, long val)
{
    for(; x > 0; x -= x & -x)
        t[x] += val;
}

long get(int x)
{
    long res = 0;
    for (; x <= n; x += x & -x)
        res += t[x];
    return res;
}

void Enter()
{
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

void Process()
{
    FOR(i, 1, n) f[i][1] = 1;
    FOR(j, 2, k)
    {
        reset();
        FOR(i, 1, n)
        {
            f[i][j] = get(a[i] + 1) % base;
            update(a[i], f[i][j-1]);
        }
    }
}

void PrintResult()
{
    long res = 0;
    FOR(i, 1, n) cout << f[i][k] << "\n";
    FOR(i, 1, n) res = (res + f[i][k]) % base;
    printf("%lld", res);
}

int main()
{
    freopen("kinv.inp", "r", stdin);
    freopen("kinv2.out", "w", stdout);

    Enter();
    Process();
    PrintResult();

    return 0;
}
