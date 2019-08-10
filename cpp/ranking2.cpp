#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORE(i, v) for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)
#define long long long
#define mp make_pair
#define fi first
#define se second
const int N = 32677;
struct BinaryIndexedTree
{
    int t[N];
    void update(int x)
    {
        for (; x > 0; x -= x & -x)
            t[x]++;
    }
    int get(int x)
    {
        int res = 0;
        for (; x <= N; x += x & -x)
            res += t[x];
        return res;
    }
} BIT;
int n, m, b[N], Rank[N];
pair <int, int> a[N];

void Enter()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, n)
    {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
}
void Compress()
{
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; )
    {
        cnt++;
        int j = i;
        while (a[i].fi == a[j].fi) b[a[j++].se] = cnt;
        i = j;
    }
}
void Process()
{
    FOR(i, 1, n)
    {
        Rank[i] = BIT.get(b[i] + 1) + 1;
        BIT.update(b[i]);
    }
    while (m--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", Rank[x]);
    }
}
int main()
{
     freopen("RANKING.INP", "r", stdin);
    //freopen("RANKING.OUT", "w", stdout);

    Enter();
    Compress();
    Process();
    return 0;
}
