#include <bits/stdc++.h>

using namespace std;

const int maxn = 1009;
int i, j, n, a[maxn], b[maxn], f[maxn];

int main() {
    freopen("nkjump.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    int tmp, ans = 0;
    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            bool tmp = binary_search(a+1,a+j,a[i] - a[j]);
            if (tmp == 1) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}
