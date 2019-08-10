//PN
#include <bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
struct Tnode
{
    int child[2];
    long long gt;
};
int T,n,deg[maxn];
vector<II> g[maxn];

int cl[maxn];
long long kc[maxn];

Tnode trie[maxn*51];
int root,nt;
void dfs(int u)
{
    cl[u]=1;
    for(int i=0; i<deg[u]; ++i)
    {
        int v=g[u][i].fs, l=g[u][i].sc;
        if(cl[v]==0)
        {
            kc[v]=kc[u]^l;
            dfs(v);
        }
    }
}
int addnode()
{
    ++nt;
    trie[nt].child[0]=trie[nt].child[1]=0;
    trie[nt].gt=0;
    return nt;
}
void addword(long long s)
{
    int r=root;
    for(int i=50; i>=0; --i)
    {
        int k=(s&(1LL<<i))? 1:0;
        if(trie[r].child[k]==0)
        {
            int l=addnode();
            trie[r].child[k]=l;
        }
        r=trie[r].child[k];
    }
    trie[r].gt=s;
}
long long calc(long long s)
{
    int r=root;
    for(int i=50; i>=0; --i)
    {
        int k=(s&(1LL<<i))? 1:0;
        k=1-k;
        if(trie[r].child[k]==0) k=1-k;
        r=trie[r].child[k];
    }
    return trie[r].gt;
}
void khoitao()
{
    for(int i=1; i<=n; ++i)
    {
        cl[i]=0;
        kc[i]=0;
        deg[i]=0;
        g[i].clear();
    }
    nt=0;
}
void lam()
{
    cin>>n;
    khoitao();
    for(int i=1; i<=n-1; ++i)
    {
        int u,v,c;
        cin>>u>>v>>c;
        deg[u]++;
        g[u].push_back(II(v,c));
        deg[v]++;
        g[v].push_back(II(u,c));
    }
    dfs(1);
    root=addnode();
    for(int i=1; i<=n; ++i)
        addword(kc[i]);
    long long ds=0;
    for(int i=1; i<=n; ++i)
        ds=max(ds,kc[i]^calc(kc[i]));
    cout<<ds<<"\n";
}
int main()
{
    freopen("a.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--)
        lam();
}
