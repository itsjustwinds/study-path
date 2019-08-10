#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> ii;

int n, a[100001];
class interval_tree
{
    ii t[400004];
public:
    void up(int k, int l, int r)
    {
        if (l == r)
        {
            t[k]=ii(a[r], a[r]);
            return;
        }
        int mid=(l + r) / 2;
        up(2*k, l, mid);
        up(2*k+1, mid+1, r);
        t[k]=ii(max(t[2*k].x, max(t[2*k + 1].x, t[2*k].y + t[2*k+1].y)), max(t[2*k].y, t[2*k+1].y));
    }
    ii get(int k, int l, int r, int i, int j)
    {
        if (l >j || i>r) return ii(0, 0);
        if (i <= l && r <= j) return t[k];
        int mid=(l + r) / 2;
        ii c=get(2*k, l, mid, i, j), d=get(2*k+1, mid+1, r, i, j);
        return ii(max(c.x, max(d.x, c.y + d.y)), max(c.y, d.y));
    }
    void update(int k, int l, int r, int pos, int val)
    {
        if (l > pos || r < pos) return;
        if (l == r)
        {
            t[k]=ii(val, val);
            return;
        }
        int mid=(l + r) / 2;
        update(2*k, l, mid, pos, val);
        update(2*k+1, mid+1, r, pos, val);
        t[k]=ii(max(t[2*k].x, max(t[2*k+1].x, t[2*k].y + t[2*k+1].y)), max(t[2*k].y, t[2*k+1].y));
    }
} it;
main()
{
    freopen("kgss.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>a[i];
    it.up(1, 1, n);
    int q;
    cin>>q;
    while (q--)
    {
        int u, v;
        char Q;
        cin>>Q>>u>>v;
        if (Q == 'U')
            it.update(1, 1, n, u, v);
        else
        {
            ii c=it.get(1, 1, n, u, v);
            cout<<c.x<<"\n";
        }
    }
}

