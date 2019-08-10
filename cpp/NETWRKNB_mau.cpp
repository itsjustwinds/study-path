#include <bits/stdc++.h>

using namespace std;

#define N 100100

struct data
{
            int a,b,c,pos;
            char ch;
} que[N], s[N], s2[N];
int n, m, head[N], cHead[N], cnt, nChain, last[N], nChild[N], level[N], parent[N], pos[N], BIT[N], res[N];
vector<int> e[N];

void dfs(int u)
{
            nChild[u] = 1;
            for (auto v: e[u])
            {
                        if (parent[v] == 0)
                        {
                                    parent[v] = u;
                                    level[v] = level[u] + 1;
                                    dfs(v);
                                    nChild[u] += nChild[v];
                        }
            }
}

void hld(int u)
{
            if (cHead[nChain] == 0) cHead[nChain] = u;
            head[u] = cHead[nChain];
            pos[u] = ++cnt;
            int mx = 0;
            int special = -1;
            //
            for (auto v: e[u])
            {
                        if (parent[v] == u)
                        {
                                    if (mx < nChild[v])
                                    {
                                                mx = nChild[v];
                                                special = v;
                                    }
                        }
            }
            //
            if (special != -1)
            {
                        hld(special);
                        for (auto v: e[u])
                        {
                                    if (parent[v] == u && v != special)
                                    {
                                                nChain++;
                                                hld(v);
                                    }
                        }
            }
            last[u] = cnt;
}

int lca(int u, int v)
{
            while (true)
            {
                        if (head[u] == head[v])
                        {
                                    if (level[u] > level[v]) return v;
                                    return u;
                        }
                        if (level[head[u]] > level[head[v]])
                        {
                                    u = parent[head[u]];
                        }
                        else v = parent[head[v]];
            }
}

bool cmp (const data &a, const data &b)
{
            return a.c < b.c;
}

void update(int u)
{
            for (; u<N; u += u&-u) BIT[u]++;
}

int get(int u)
{
            int ans = 0;
            for (; u>0; u -= u&-u) ans += BIT[u];
            return ans;
}

int calP(int lca, int u)
{
            int ans = 0;
            while (true)
            {
                        if (lca == u) return ans;
                        if (head[lca] == head[u])
                        {
                                    return ans + get(pos[u]) - get(pos[lca]);
                        }
                        ans += get(pos[u]) - get(pos[head[u]] - 1);
                        u = parent[head[u]];
            }
            return ans;
}

void solve()
{
            sort(s + 1, s + n, cmp);
            int point = 1;
            for (int i = 0; i<m; i++)
            {
                        cin>>que[i].ch;
                        que[i].pos = i;
                        if (que[i].ch == 'P') cin>>que[i].a>>que[i].b>>que[i].c;
                        else cin>>que[i].a>>que[i].c;
            }
            sort(que, que + m, cmp);
            for (int i = 0; i<m; i++)
            {
                        point++;
                        point--;
                        while (point <n && s[point].c <= que[i].c)
                        {
                                    int u = s[point].a;
                                    int v = s[point].b;
                                    if (u == parent[v])
                                    {
                                                update(pos[v]);
                                    }
                                    else update(pos[u]);
                                    point++;
                        }
                        if (que[i].ch == 'P')
                        {
                                    int u = que[i].a;
                                    int v = que[i].b;
                                    int lc = lca(u, v);
                                    res[que[i].pos] = calP(lc, u) + calP(lc, v);
                        }
                        else
                        {
                                    int u = s2[que[i].a].a;
                                    int v = s2[que[i].a].b;
                                    if (u == parent[v])
                                    {
                                                res[que[i].pos] = get(last[v]) - get(pos[v]);
                                    }
                                    else
                                    {
                                                //int tmp = (get(last[v]) - get(pos[u]));
                                                res[que[i].pos] = point - (get(last[u]) - get(pos[u])) - 1;// - (s2[que[i].a].c <= que[i].c);
                                    }
                        }
            }
            for (int i = 0; i<m; i++) cout<<res[i]<<endl;
}
void init()
{
            memset(parent, 0, sizeof parent);
            parent[1] = -1;
            cnt = 0;
            memset(last, 0, sizeof last);
            nChain = 1;
            memset(cHead, 0, sizeof cHead);
            level[1] = 1;
}
int main()
{
            freopen("D:\\C++\\debug\\NETWRKNB.inp","r",stdin);
            freopen("D:\\C++\\debug\\NETWRKNB.ans","w",stdout);
            ios::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            int u, v, c;
            for (int i = 1; i<n; i++)
            {
                        cin>>u>>v>>c;
                        s[i].a = u;
                        s[i].b = v;
                        s[i].c = c;
                        s[i].pos = i;
                        s2[i].a = u;
                        s2[i].b = v;
                        s2[i].c = c;
                        s2[i].pos = i;
                        e[u].push_back(v);
                        e[v].push_back(u);
            }
            init();
            dfs(1);
            hld(1);
            solve();
}

