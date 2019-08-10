#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

const int MAXN = 1000000 + 10;
const int MAXV = 10000 + 10;

int freq[MAXV];
int a[MAXN];
int c[MAXN];
vector<pair<int, int> > b[MAXV];
int n;

void init() {
    vector<bool> p(MAXV, true);
    p[0] = p[1] = false;
    for(int i = 2; i * i <= 10000; i++) {
        if (p[i]) {
            int j = i + i;
            while (j <= 10000) {
                p[j] = false;
                j += i;
            }
        }
    }
    vector<int> prime;
    for(int i = 1; i <= 10000; i++) {
        if (p[i]) prime.push_back(i);
    }
    for(int i = 1; i <= 10000; i++) {
        if (freq[i] == 0) continue;
        for(int j = 0; j < prime.size(); j++) {
            int cnt = 0;
            int v = i;
            while (v % prime[j] == 0) {
                cnt++; v /= prime[j];
            }
            b[prime[j]].push_back(make_pair(cnt, freq[i]));
        }
    }
}

long long power(int x, int k) {
    long long ret = 1;
    for(int i = 1; i <= k; i++) ret *= x;
    return ret;
}

int main()
{
    freopen("D:\\C++\\huy\\PVOI14_5.inp", "r", stdin);
    freopen("D:\\C++\\huy\\PVOI14_5.ans", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) freq[a[i]]++;
    init();
    long long ans1 = 0; long long ans2 = 1;
    for(int i = 1; i <= 10000; i++) {
        if (b[i].size() > 0) {
            for(int j = 0; j <= 50; j++) c[j] = 0;
            for(int j = 0; j < b[i].size(); j++) c[b[i][j].first] += b[i][j].second;
            long long tot = 0;
            for(int j = 0; j <= 50; j++) tot += (long long)(j) * c[j];
            int p = (n + 1) / 2, l = 0;
            long long s = 0;
            for(int j = 0; j <= 50; j++) {
                s += (long long)(j) * c[j]; l += c[j];
                if (l >= p) {
                    int kk = (long long)(l) * j - s + (tot - s) - (long long)(n - l) * j;
                    ans1 += (long long)(l) * j - s + (tot - s) - (long long)(n - l) * j;
                    ans2 *= power(i, j);
                    break;
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}
