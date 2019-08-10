#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct data
{
        int u,v,w;
};
data c[1000000],d[10];
int n,m,res,a[maxn][maxn],dem;
bool cmp(data a,data b)
{
        return a.w>b.w;
}
int check(int u,int v)
{
        if (u>n||u<1||v>m||v<1) return 0;
        return 1;
}
void dfs(int u,int v,int w)
{
        a[u][v]=0;
        for (int i=1;i<=8;i++)
        {
                int nu=u+d[i].u;
                int nv=v+d[i].v;
                if (!check(nu,nv)) continue;
                if (w<a[nu][nv]) continue;
                if (a[nu][nv]==0) continue;
                dfs(nu,nv,a[nu][nv]);
        }
}
int main()
{
        freopen("NKGUARD.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        d[1].u=-1;
        d[2].u=-1;d[2].v=1;
        d[3].v=1;
        d[4].u=1;d[4].v=1;
        d[5].u=1;
        d[6].u=1;d[6].v=-1;
        d[7].v=-1;
        d[8].u=-1;d[8].v=-1;
        for (int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
        {
                cin>>a[i][j];
                ++dem;
                c[dem].u=i;
                c[dem].v=j;
                c[dem].w=a[i][j];
        }
        sort(c+1,c+dem+1,cmp);
        for (int i=1;i<=dem;i++)
        {
                int u=c[i].u;
                int v=c[i].v;
                int w=c[i].w;
                if (a[u][v]==0) continue;
                dfs(u,v,w);
                res++;
        }
        cout<<res;
        return 0;
}
