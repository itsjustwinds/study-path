#include<bits/stdc++.h>
#define maxn 70005
using namespace std;
vector<int > e[maxn];
int n,Parray[maxn][35],Ptree[maxn][35],Prev[maxn],high[maxn];
void dfs(int u){
    for (int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if (v==Prev[u]) continue;
        Prev[v]=u;
        high[v]=high[u]+1;
        dfs(v);
    }
}
int lca(int u,int v){
    if(high[u]<high[v]) swap(u,v);
    int log=log2(high[u]);
    for (int i=log;i>=0;--i)
    if (high[u]-(1<<i)>=high[v]) u=Ptree[u][i];
    if (u==v) return u;
    for (int i=log;i>=0;--i)
    if (Ptree[u][i]!=-1&&Ptree[v][i]!=-1&&Ptree[u][i]!=Ptree[v][i]){
        u=Ptree[u][i];
        v=Ptree[v][i];
    }
    return Prev[u];
}
int get(int l,int r){
    int log=log2(r-l+1);
    return lca(Parray[l][log],Parray[r-(1<<log)+1][log]);
}
int main(){
    freopen("VOTREE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>test;
    for (int i=2;i<=n;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    memset(Ptree,-1,sizeof Ptree);
    for (int i=1;i<=n;++i)
        Ptree[i][0]=Prev[i];
    for (int j=1;1<<j<=n;++j)
        for (int i=1;i<=n;++i)
        if (Ptree[i][j-1]!=-1){
            Ptree[i][j]=Ptree[Ptree[i][j-1]][j-1];
        }
    for (int i=1;i<=n;++i)
        Parray[i][0]=i;
    for (int j=1;1<<j<=n;++j)
        for (int i=1;i+(1<<j)-1<=n;++i)
        Parray[i][j]=lca(Parray[i][j-1],Parray[i+(1<<(j-1))][j-1]);
    while(test--){
        int u,v;
        cin>>u>>v;
        cout<<get(u,v)<<"\n";
    }
    return 0;
}
