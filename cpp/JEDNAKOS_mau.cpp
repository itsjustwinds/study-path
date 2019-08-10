//Cáº¥m chÃ©p code dÆ°á»i má»i hÃ¬nh thá»©c
//MÃ  cÃ³ chÃ©p thÃ¬ cháº£ ai quan tÃ¢m

#include <bits/stdc++.h>

using namespace std;
string ss, a;
#define N 5010
int num[N][N], f[N][N], s, n;

void init(string a, int s)
{
        for (int i = 0; i<n; i++)
        {
                int z = 0;
                for (int j = i; j < n; j++)
                {
                        z = z * 10 + a[j] - '0';
                        if (z > s) break;
                        num[i][j] = z;
                }
        }
        for (int i = 0; i<=n; i++) for (int j = 0; j<=s; j++) f[i][j] = 1e9;
}

const int inf = 1e9;

int TRY(int u, int rest)
{
        if (num[0][u] == rest) return 0;
        if (f[u][rest] != inf) return f[u][rest];
        int v = u;
        while (v > 0 && num[v][u] != -1 && num[v][u] <= rest)
        {
                f[u][rest] = min(f[u][rest], TRY(v - 1, rest - num[v][u]) + 1);
                v--;
        }
        f[u][rest] = min(f[u][rest], (int)1e9 - 1);
        return f[u][rest];
}
int main()
{
        freopen("JEDNAKOS.inp","r",stdin);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        getline(cin, a);
        string ss;
        memset(num, -1, sizeof num);
        while (true)
        {
                int t = a.back() - '0';
                if (t >= 0 && t<10) break;
                a.pop_back();
        }
        while(a.back() != '=')
        {
                ss = a.back()+ ss;
                a.pop_back();
        }
        int s = 0;
        for(char c: ss) s = s * 10 + c - '0';
        a.pop_back();
        string t = a;
        a.clear();
        int cc = 0;
        for (char c: t)
        {
                if (c != '0')
                {
                        a.push_back(c);
                        cc = 0;
                }
                else
                {
                        if (cc <= 3)
                        {
                                a.push_back(c);
                                cc++;
                        }
                }
        }
        n = a.size();
        init(a, s);
        cout<<TRY(n - 1, s);
}

