#include <bits/stdc++.h>

using namespace std;
#define N 500005
#define pp<int, int>

const long long  MOD = 1e9 + 7;
int n, k, a[N];
long long f[N], g[N];
multiset<int> fr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i = 1; i<=n; i++) cin>>a[i];
    int start = 1;
    int cnt = 0;
    f[0] = 1;
    g[0] = 1;
    for (int last = 1; last <=n; last++) {
        if (a[last] <= k) {
            if (fr.count(a[last]) == 0) cnt++;
            fr.insert(a[last]);
        }
        while (cnt == k + 1) {
            if (a[start] >k) {
                start++;
                continue;
            }
            auto it = fr.find(a[start]);
            fr.erase(it);
            if (fr.count(a[start]) == 0) cnt--;
            start++;
        }
        f[last] = g[last - 1];
        if (start >1) f[last] =(f[last] -  g[start - 2] + MOD * MOD) % MOD;
        g[last] = (g[last - 1] + f[last]) % MOD;
    }
    cout<<f[n];
}
