#include<bits/stdc++.h>
#define maxn 505
#define oo 1000000007
using namespace std;
struct data
{
        int u,v,val;
};
int c[maxn][maxn],n,m,res[maxn][maxn];
char a[maxn][maxn];
data d[5],s,t;
struct cmp{

bool operator() (data a,data b) {return a.val<b.val;}

};
int check(int x,int y)
{
        if (x<=0||x>n||y<=0||y>m) return 0;
        return 1;
}
void bfs()
{
        queue<data> q;
        while(!q.empty())q.pop();
        for (int i=1; i<=n; i++)
                for (int j=1; j<=m; j++)
                        if (a[i][j]=='+')
                        {
                                c[i][j]=0;
                                data tmp;
                                tmp.u=i;
                                tmp.v=j;
                                tmp.val=0;
                                q.push(tmp);
                        }
        while(!q.empty())
        {
                data u;
                u=q.front();
                q.pop();
                data v;
                for (int i=1;i<=4;i++)
                {
                        v.u=u.u+d[i].u;
                        v.v=u.v+d[i].v;
                        v.val=u.val+1;
                        if (check(v.u,v.v)&&c[v.u][v.v]==-1)
                        {
                                c[v.u][v.v]=v.val;
                                q.push(v);
                        }
                }
        }
}
void solve()
{
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        q.push(s);
        res[s.u][s.v]=s.val;
        while(!q.empty())
        {
                data u=q.top();
                q.pop();
                if (res[u.u][u.v]!=u.val) continue;
                if (u.u==t.u&&u.v==t.v) return;
                for (int i=1;i<=4;i++)
                {
                        data v;
                        v.u=u.u+d[i].u;
                        v.v=u.v+d[i].v;
                        if (!check(v.u,v.v)) continue;
                        v.val=min(u.val,c[v.u][v.v]);
                        if (v.val>res[v.u][v.v])
                        {
                                res[v.u][v.v]=v.val;
                                q.push(v);
                        }
                }
        }

}
int main()
{
        freopen("VUKVN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        d[1].u=-1;d[1].v=0;
        d[2].u=0;d[2].v=1;
        d[3].u=1;d[3].v=0;
        d[4].u=0;d[4].v=-1;
        for (int i=1; i<=n; i++)
                for (int j=1; j<=m; j++)
                {
                        cin>>a[i][j];
                        if (a[i][j]=='V')
                        {
                                s.u=i;
                                s.v=j;
                        }
                        if (a[i][j]=='J')
                        {
                                t.u=i;
                                t.v=j;
                        }
                }
        memset(c,-1,sizeof(c));
        bfs();
        s.val=c[s.u][s.v];
        t.val=c[t.u][t.v];
        for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                res[i][j]=-oo;
        solve();
        cout<<res[t.u][t.v];
        return 0;
}
