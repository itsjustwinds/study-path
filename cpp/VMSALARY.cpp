#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int bit[maxn],n;
vector<int > e[maxn];
struct data
{
        int c,id;
};
data b[maxn];
int c[maxn],res[maxn],last[maxn],cnt,head[maxn];
void dfs(int u)
{
        head[u]=++cnt;
        for (int i=0; i<e[u].size(); ++i)
        {
                int v=e[u][i];
                dfs(v);
        }
        last[u]=cnt;
}
bool cmp(data a,data b)
{
        return a.c<b.c;
}
long long ans;
void update(int u)
{
        while(u<=maxn)
        {
                bit[u]++;
                u+=u&(-u);
        }
}
int get(int u)
{
        int res=0;
        while(u)
        {
                res+=bit[u];
                u-=u&(-u);
        }
        return res;
}
int main()
{
        freopen("VMSALARY.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        cin>>c[1];
        b[1].c=c[1];
        b[1].id=1;
        for (int i=2; i<=n; ++i)
        {
                int u;
                cin>>u>>c[i];
                e[u].push_back(i);
                b[i].c=c[i];
                b[i].id=i;
        }
        dfs(1);
        sort(b+1,b+n+1,cmp);
        int now=0;
        for(int i=1; i<=n; ++i)
        {
                int u=b[i].id;
                if (b[i].c!=b[i-1].c)
                {
                        for (int j=now+1; j<=i-1; ++j)
                        {
                                int u=b[j].id;
                                update(head[u]);
                        }
                        now=i-1;
                }
                res[u]=get(last[u])-get(head[u]);
                ans+=1ll*res[u]*(res[u]-1)/2;
        }
        cout<<ans;
}
