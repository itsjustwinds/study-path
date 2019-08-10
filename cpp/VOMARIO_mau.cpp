
#include <iostream>
//#include <Bits.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define N 100005

int n, b[N], c[N];
long long w[N], f[N], e[N], x[N], val[N], a[N];

struct line
{
        long long a, b;
} IT[4 * N];

long long Get(line &d, long long pos)
{
        return d.a * val[pos] + d.b;
}

long long Query(int k, int l, int r, int x)
{
        if (l > x || r < x) return 0;
        long long ans = Get(IT[k], x);
        if (l == r) return ans;
        int m = (l + r) >> 1;
        ans = max(ans, Query(k * 2, l, m, x));
        ans = max(ans, Query(k * 2 + 1, m + 1, r, x));
        return ans;
}

void Update(int k, int l, int r, int u, int v, line val)
{
        if (l > v || r < u) return;
        int m = (l + r) >> 1;
        if (u <= l && r <= v)
        {
//1
                if (Get(IT[k], l) >= Get(val, l) && (Get(IT[k], r) >= Get(val, r)))
                {
                        return;
                }
//2
                if (Get(IT[k], l) <= Get(val, l) && (Get(IT[k], r) <= Get(val, r)))
                {
                        IT[k] = val;
                        return;
                }
//3
                if (Get(IT[k], l) <= Get(val, l) && (Get(IT[k], m) <= Get(val, m)))
                {
                        Update(k * 2 + 1, m + 1, r, u, v, IT[k]);
                        IT[k] = val;
                        return;
                }
//4
                if (Get(IT[k], l) >= Get(val, l) && (Get(IT[k], m) >= Get(val, m)))
                {
                        Update(k * 2 + 1, m + 1, r, u, v, val);
                        return;
                }
//5
                if (Get(IT[k], r) <= Get(val, r) && (Get(IT[k], m + 1) <= Get(val, m + 1)))
                {
                        Update(k * 2, l, m, u, v, IT[k]);
                        IT[k] = val;
                        return;
                }
//6
                if (Get(IT[k], r) >= Get(val, r) && (Get(IT[k], m + 1) >= Get(val, m + 1)))
                {
                        Update(k * 2, l, m, u, v, val);
                        return;
                }
        }
        Update(k * 2, l, m, u, v, val);
        Update(k * 2 + 1, m + 1, r, u, v, val);
}
int main()
{
        freopen("D:\\C++\\debug\\VOMARIO.inp","r",stdin);
        //freopen("D:\\C++\\debug\\VOMARIO.ans","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        a[0] = w[0] = x[0] = e[0] = 0;
        for (int i = 1; i <=n; i++)
        {
                cin >> x[i] >> w[i] >> e[i];
                a[i] = x[i];
        }
        sort(a, a + n + 1);
        for (int i = 0; i <= n; i++)
        {
                b[i] = lower_bound(a, a + n, x[i]) - a + 1;
                c[i] = b[i];
        }
        sort(c, c + n + 1);
        for (int i = 0; i <= n; i++)
                val[b[i]] = x[i];

        for (int i = 0; i < 4 * N; i++)
        {
                IT[i].a = IT[i].b = 0;
        }
        long long ans = 0;
        int top = *max_element(b, b + n + 1);

        for (int i = 1; i <= n; i++)
        {
                f[i] = Query(1, 1, top, b[i]) + e[i];
                ans = max(ans, f[i]);
                int l = 1;
                int r = top;
                if (w[i] != 0)
                {
                        l = lower_bound(a, a + n + 1, x[i] - f[i] / w[i]) - a;
                        l = c[l];
                        r = upper_bound(a, a + n + 1, x[i] + f[i] / w[i]) - a - 1;
                        r = c[r];
                }
                line tmp;
                tmp.a = w[i];
                tmp.b = f[i] - w[i] * x[i];
                Update(1, 1, top, l, b[i], tmp);
                tmp.a = -w[i];
                tmp.b = f[i] + w[i] * x[i];
                Update(1, 1, top, b[i], r, tmp);
        }
        cout << ans;
}
