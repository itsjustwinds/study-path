#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1000100
#define pp pair<long long, long long>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
const long long MOD = 1e9 + 7;
const long long base1 = 29;
const long long base2 = 101;
long long H1[2][N], H2[2][N], P1[N], P2[N];
vector<string> st;

int sz[N];

void Hash(int u, int v)
{
        H1[u][0] = H2[u][0] = 0;
        FOR(i, 1, sz[v])
        {
                H1[u][i] = (H1[u][i - 1] * base1 + st[v][i - 1] - 'a') % MOD;
                H2[u][i] = (H2[u][i - 1] * base2 + st[v][i - 1] - 'a') % MOD;
        }
}

pp getH(int u, int i, int j)
{
        return pp((H1[u][j] - H1[u][i - 1] * P1[j - i + 1] + MOD * MOD) % MOD,
                  (H2[u][j] - H2[u][i - 1] * P2[j - i + 1] + MOD * MOD) % MOD);
}

vector<map<pp, int> > F1, F2, S1, S2;

bool Palin(int u, int i, int j)
{
        if (i > j) return true;
        if (getH(0, i, j) == getH(1, sz[u] - j + 1, sz[u] - i + 1)) return true;
        return false;
}

long long Add(int u)
{
        long long ans = 0;
        F1[sz[u]][getH(0, 1, sz[u])]++;
        S1[sz[u]][getH(1, 1, sz[u])]++;
        FOR(i, 1, sz[u] - 1)
        {
                //Get F2 check S1
                if (Palin(u, i + 1, sz[u]))
                {
                        F2[i][getH(0, 1, i)]++;
                        ans += S1[i][getH(0, 1, i)];
                }
                //Get S2 check F1
                if (Palin(u, 1, i))
                {
                        S2[sz[u] - i][getH(1, 1, sz[u] - i)]++;
                        ans += F1[sz[u] - i][getH(1, 1, sz[u] - i)];
                }
        }
        //Get F1 check S1
        ans += S1[sz[u]][getH(0, 1, sz[u])];
        //Get S1 check F1
        ans += F1[sz[u]][getH(1, 1, sz[u])];
        //Get F1 check S2
        ans += S2[sz[u]][getH(0, 1, sz[u])];
        //Get S1 check F2
        ans += F2[sz[u]][getH(1, 1, sz[u])];
        if (Palin(u, 1, sz[u])) ans--;
        return ans;
}

int main()
{
        freopen("D:\\c++\\PALINX.inp","r",stdin);
        freopen("D:\\c++\\PALINX.ans","w",stdout);
        IO;
        cin>>n;
        st.resize(n);
        P1[0] = P2[0] = 1;
        FOR(i, 1, N - 1)
        {
                P1[i] = P1[i - 1] * base1 % MOD;
                P2[i] = P2[i - 1] * base2 % MOD;
        }
        long long ans = 0;
        int mx = 0;
        REP(i, n)
        {
                cin>>sz[i]>>st[i];
                mx = max(sz[i], mx);
        }
        mx++;
        F1.resize(mx);
        F2.resize(mx);
        S1.resize(mx);
        S2.resize(mx);
        REP(i, n)
        {
                Hash(0, i);
                reverse(st[i].begin(), st[i].end());
                Hash(1, i);
                ans += Add(i);
        }
        cout<<ans;
}

