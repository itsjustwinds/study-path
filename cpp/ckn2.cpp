#include <bits/stdc++.h>

using namespace std;
#define N 100005
long long MOD;
int n, k;
vector<int> NT[N];
int num[N][17], cnt[N];

void sangnt() {
    for (int i = 2; i<N; i++) {
        if (NT[i].size() == 0) {
            for (int j = 1; i * j <N; j++){
                NT[i * j].push_back(i);
            }
        }
    }
    memset(num, 0, sizeof num);
    for (int i = 2; i<N; i++) {
        for (int j = 0;j <(int)NT[i].size(); j++) {
            int x = i;
            while (x % NT[i][j] == 0) {
                num[i][j]++;
                x = x / NT[i][j];
            }
        }
    }
}
void cal(int n, int z) {
    if (z == 1) {
        for (int i = 2; i<=n; i++) {
            for (int j = 0; j<(int) NT[i].size(); j++) {
                cnt[NT[i][j]] += num[i][j];
            }
        }
    }
    else {
        for (int i = 2; i<=n; i++) {
            for (int j = 0; j<(int) NT[i].size(); j++) {
                cnt[NT[i][j]] -= num[i][j];
            }
        }
    }
}

long long POW(int x, int k) {
    if (k == 0) return 1;
    long long tmp = POW(x, k / 2);
    tmp = (tmp * tmp) % MOD;
    if (k % 2 == 1) tmp =(tmp * x) % MOD;
    return tmp;
}
int main()
{
    freopen("ckn.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>MOD;
    sangnt();
    memset(cnt, 0, sizeof cnt);
    cal(n, 1);
    cal(k, 2);
    cal(n - k, 2);
    long long ans = 1;
    for (int i = 1; i<N; i++) {
        ans = (ans * POW(i, cnt[i])) % MOD;
    }
    cout<<ans;
}
