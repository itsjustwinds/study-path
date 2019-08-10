#include<bits/stdc++.h>
#define maxn 3005
#define fs first
#define sc second
using namespace std;
int f[2*maxn][2*maxn],n,u,v;
typedef pair<int,int> II;
II a[maxn];
long long res;
void dfs1(int i,II x)
{
        if (i==n/2+1)
        {
                f[x.fs+maxn][x.sc+maxn]++;
                return;
        }
        dfs1(i+1,x);
        dfs1(i+1,II(x.fs+a[i].fs,x.sc+a[i].sc));
}
void dfs2(int i,II x)
{
        if (i==n+1)
        {
                res+=f[u-x.fs+maxn][v-x.sc+maxn];
                return ;
        }
        dfs2(i+1,x);
        dfs2(i+1,II(x.fs+a[i].fs,x.sc+a[i].sc));
}
int main()
{
        freopen("VECTOR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].fs>>a[i].sc;
        cin>>u>>v;
        if (abs(u)>3000||abs(v)>3000)
        {
                cout<<0;
                return 0;
        }
        dfs1(1,II(0,0));
        dfs2(n/2+1,II(0,0));
        cout<<res;
        return 0;
}
