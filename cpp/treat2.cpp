
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

const int N = 1e5+10;

#define I_Love_TT(i, a, b) for (int i = a; i <= b; ++i)

int n, Next[N], d[N], Num[N], Low[N], cnt;
stack <int> s;

void dfs(int u) {
    Num[u] = Low[u] = ++cnt;
    s.push(u);
    if (Num[Next[u]])
        Low[u] = min(Num[Next[u]], Low[u]);
    else {
        dfs(Next[u]);
        Low[u] = min(Low[u], Low[Next[u]]);
    }
    if (Num[u] == Low[u]) {
        vector <int> ab;
        int v, curr = 0;
        do {
            v = s.top();    s.pop();
            Num[v] = Low[v] = INT_MAX;
            ab.push_back(v);
            curr++;
        } while (v != u);
        I_Love_TT(i, 0, ab.size() - 1) d[ab[i]] = curr;
    }
}

int get(int u) {
    return !d[u] ? get(Next[u]) + 1: d[u];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("TREAT.INP", "r", stdin);
        //freopen("TREAT.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    I_Love_TT(i, 1, n) scanf("%d", &Next[i]);

    I_Love_TT(i, 1, n)
      if (!Num[i])
        dfs(i);
    I_Love_TT(i, 1, n)
      if (d[i] == 1)
        d[i] = Next[i] == i ? d[i] : 0;
    I_Love_TT(i, 1, n)
      if (!d[i])
        d[i] = get(i);
    I_Love_TT(i, 1, n) printf("%d\n", d[i]);
    return 0;
}
