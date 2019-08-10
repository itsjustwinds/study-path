#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
    int val[3];
};
data hashT[maxn],base,power[maxn],hashQ;
int n,len;
char s[maxn],q[maxn];
vector<int> e[maxn];
int trc[maxn],h[maxn];
int p[maxn][55];
bool check(data a,data b)
{
    for (int i=0;i<=2;i++)
        if (a.val[i]!=b.val[i]) return false;
    return true;
}
void dfs(int u,int t)
{
    h[u]=h[t]+1;
    for (int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if (v==t) continue;
        trc[v]=u;
        dfs(v,u);
    }
}
data get(int i,int j)
{
    data c;
    for (int k=0;k<=2;k++)
        c.val[k]=(hashT[j].val[k]-((ll)hashT[i-1].val[k]*power[j-i+1].val[k])%mod+mod)%mod;
    return c;
}
int lca(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    int log=log2(h[u]);
    for (int i=log;i>=0;i--)
        if (h[u]-(1<<i)>=h[v]) u=p[u][i];
    if (u==v) return u;
    for (int i=log;i>=0;i--)
        if (p[u][i]!=1&&p[v][i]!=1&&p[u][i]!=p[v][i])
    {
        u=p[u][i];
        v=p[v][i];
    }
    return trc[u];
}
int main()
{
    freopen("w33f.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>test;
    cin>>(s+1);
    cin>>(q+1);
    hashQ.val[0]=0;hashQ.val[1]=0;hashQ.val[2]=0;
    base.val[0]=17;base.val[1]=59;base.val[2]=101;
    power[0].val[0]=1;power[0].val[1]=1;power[0].val[2]=1;
    len=strlen(q+1);
    for (int i=1;i<=len;i++)
    {
        for (int j=0;j<=2;j++)
            hashQ.val[j]=((ll)hashQ.val[j]*base.val[j]+(q[i]-'a'))%mod;
    }
    for (int i=2;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=2;j++)
            power[i].val[j]=((ll)power[i-1].val[j]*base.val[j])%mod;
    }
    dfs(1,0);
    hashT[0].val[0]=0;hashT[0].val[1]=0;hashT[0].val[2]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;1<<j<=n;j++)
        p[i][j]=-1;
    for (int i=1;i<=n;i++)
        p[i][0]=trc[i];
    for (int j=1;1<<j<=n;j++)
        for (int i=1;i<=n;i++)
        if (p[i][j-1]!=-1)
        p[i][j]=p[p[i][j-1]][j-1];
    while(test--)
    {
        int u,v;
        cin>>u>>v;
        int w=lca(u,v);
        char t[maxn];
        int dem=0;
        while(u!=w)
        {
            t[++dem]=s[u];
            u=trc[u];
        }
        t[++dem]=s[w];
        char k[maxn];
        int dem2=0;
        while(v!=w)
        {
            k[++dem2]=s[v];
            v=trc[v];
        }
        for (int i=dem2;i>=1;i--)
        {
            t[++dem]=k[i];
        }
        for (int i=1;i<=dem;i++)
            for (int j=0;j<=2;j++)
                hashT[i].val[j]=((ll)hashT[i-1].val[j]*base.val[j]+(t[i]-'a'))%mod;
        int res=0;
        for (int i=1;i<=dem-len+1;i++)
        {
            data sml=get(i,i+len-1);
            if (check(sml,hashQ)) res++;
        }
        cout<<res<<"\n";
    }
    return 0;
}
