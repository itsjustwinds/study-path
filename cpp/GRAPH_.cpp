#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,khop[maxn],cau,slx,cnt,num[maxn],low[maxn];
vector<int > e[maxn],tplt[maxn];
stack<int > St;
void dfs(int u,int trc){
      num[u]=low[u]=++cnt;
      int Dem=0;
      St.push(u);
      for (int i=0;i<e[u].size();++i){
            int v=e[u][i];
            if (v==trc) continue;
            ++Dem;
            if (num[v]) low[u]=min(low[u],num[v]);
            else {
                  dfs(v,u);
                  low[u]=min(low[u],low[v]);
                  if (low[v]==num[v]) ++cau;
                  if (!khop[u]){
                        if (trc==-1){
                              if (Dem==2) khop[u]=1;
                        }
                        else if (low[v]>=num[u]) khop[u]=1;
                  }
            }
      }
      if (low[u]==num[u]){
            int x;
            ++slx;
            do {
                  x=St.top();
                  //cout<<x<<" ";
                  St.pop();
                  tplt[slx].push_back(x);
            }while(u!=x);
            //cout<<"\n";
      }
}
int main(){
      freopen("GRAPH_.inp","r",stdin);
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n>>m;
      for (int i=1;i<=m;++i){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
      }
      for (int i=1;i<=n;++i)
      if (!num[i]) dfs(i,-1);
      int res=0;
      for (int i=1;i<=n;++i)
      if (khop[i]) ++res;
      cout<<res<<" "<<cau;
}
