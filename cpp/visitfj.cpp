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
#define task "visitfj"

template <class T> bool inside(T a, T b, T c)
{
    return a <= b && b <= c;
}
typedef pair <long, int> ii;

const int dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
const int dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

int n, t;
long ans;
vector < vector <int> > a;
long d[10010];

void Enter()
{
    scanf("%d%d", &n, &t);
    a.assign(n, vector <int>(n));
    REP(i, n)
    REP(j, n)
    {
        scanf("%d", &a[i][j]);
        d[i * n + j] = INF;
    }
}

void Dijkstra()
{

    priority_queue <ii> q;
    q.push(ii(0, 0));
    d[0] = 0;

    ans = INF;
    while (!q.empty())
    {
        int u = q.top().se;
        long du = -q.top().fi;
        q.pop();
        if (d[u] != du) continue;

        int x = u / n, y = u % n;
        int dis = (n - x - 1) + (n - y - 1);
        if (dis < 3)
        {
            ans = min(ans, du + dis * t);
        }

        REP(i, 16)
        {
            int r = x + dx[i], c = y + dy[i];
            int v = r * n + c;
            if (!inside(0, r, n - 1) || !inside(0, c, n - 1)) continue;
            int xx = a[r][c];
            if (d[v] > d[u] + a[r][c] + 3 * t)
            {
                d[v] = d[u] + a[r][c] + 3 * t;
                q.push(ii(-d[v], v));
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);

    Enter();
    Dijkstra();

    return 0;
}

