#include<bits/stdc++.h>
#define maxn 55
#define ll long long
using namespace std;
ll f[maxn][maxn][7][7][7];
int n,m,a[maxn][maxn];
struct data
{
        int u,v,top,fro,ri;
        ll val;
};
data s,t;
ll res;
struct cmp{

bool operator() (data a,data b) {return a.val>b.val;}

};
data go1(data u)
{
        data v;
        v.u=u.u-1;
        v.v=u.v;
        v.fro=7-u.top;
        v.top=u.fro;
        v.ri=u.ri;
        int tmp=7-u.fro;
        v.val=u.val+tmp*a[v.u][v.v];
        return v;
}
data go2(data u)
{
        data v;
        v.u=u.u;
        v.v=u.v+1;
        v.fro=u.fro;
        v.top=7-u.ri;
        v.ri=u.top;
        int tmp=u.ri;
        v.val=u.val+tmp*a[v.u][v.v];
        return v;
}
data go3(data u)
{
        data v;
        v.u=u.u+1;
        v.v=u.v;
        v.fro=u.top;
        v.top=7-u.fro;
        v.ri=u.ri;
        int tmp=u.fro;
        v.val=u.val+tmp*a[v.u][v.v];
        return v;
}
data go4(data u)
{
        data v;
        v.u=u.u;
        v.v=u.v-1;
        v.fro=u.fro;
        v.top=u.ri;
        v.ri=7-u.top;
        int tmp=7-u.ri;
        v.val=u.val+tmp*a[v.u][v.v];
        return v;
}
void dijkstra(data s)
{
        priority_queue<data,vector<data>,cmp > q;
        q.push(s);
        for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                for (int x=1;x<=6;x++)
                for (int y=1;y<=6;y++)
                for (int z=1;z<=6;z++)
                f[i][j][x][y][z]=100000000000000000LL;
        f[s.u][s.v][s.fro][s.top][s.ri]=s.val;
        while(!q.empty())
        {
                data u=q.top();
                q.pop();
                if (u.val!=f[u.u][u.v][u.fro][u.top][u.ri]) continue;
                if (u.u==t.u&&u.v==t.v)
                {
                        res=u.val;
                        return ;
                }
                data v=go1(u);
                if (v.val<f[v.u][v.v][v.fro][v.top][v.ri])
                {
                        f[v.u][v.v][v.fro][v.top][v.ri]=v.val;
                        q.push(v);
                }

                v=go2(u);
                if (v.val<f[v.u][v.v][v.fro][v.top][v.ri])
                {
                        f[v.u][v.v][v.fro][v.top][v.ri]=v.val;
                        q.push(v);
                }

                v=go3(u);
                if (v.val<f[v.u][v.v][v.fro][v.top][v.ri])
                {
                        f[v.u][v.v][v.fro][v.top][v.ri]=v.val;
                        q.push(v);
                }

                v=go4(u);
                if (v.val<f[v.u][v.v][v.fro][v.top][v.ri])
                {
                        f[v.u][v.v][v.fro][v.top][v.ri]=v.val;
                        q.push(v);
                }
        }
}
int main()
{
        freopen("XUCXAC.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                cin>>a[i][j];
        cin>>s.u>>s.v>>t.u>>t.v;
        s.top=2;
        s.fro=1;
        s.ri=3;
        s.val=5*a[s.u][s.v];
        dijkstra(s);
        cout<<res;
        return 0;
}
