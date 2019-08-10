#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = (int) 1e6 + 10;
const int md = (int) 1e9 + 7;

int p[N], cnt[N];
vector <int> factor;

void eratos()
{
    for (int i = 2; i * i < N; i++)
    {
        if (!p[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                p[j] = i;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (!p[i])
        {
            p[i] = i;
        }
    }
}

void analyze(int x)
{
    for ( ; x > 1; x /= p[x])
    {
        if (cnt[p[x]] == 0)
        {
            factor.push_back(p[x]);
        }
        ++cnt[p[x]];
    }
}

void initialize()
{
    factor.clear();
}

void solve()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        analyze(i);
    }
    long long res = 1;
    for (int i = 0; i < factor.size(); i++)
    {
        res = res * (2 * cnt[factor[i]] + 1) % 111539786;
        cnt[factor[i]] = 0;
    }
    printf("%lld\n", res);
}

int main()
{
    freopen("lcm.inp","r",stdin);
    eratos();
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        initialize();
        solve();
    }
    return 0;
}
