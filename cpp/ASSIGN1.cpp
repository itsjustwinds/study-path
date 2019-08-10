#include<bits/stdc++.h>
#define maxn 405
using namespace std;
int n,s,t,d[maxn],pos[maxn],dd[maxn],cost[maxn][maxn],cnt;
struct data{
      int u,v,f,c;
};
vector<data > edge;
vector<int > g[maxn];
int res,MAXcost;
void add_edge(int u,int v,int c){
      g[u].push_back(edge.size());
      edge.push_back({u,v,0,c});
      g[v].push_back(edge.size());
      edge.push_back({v,u,0,0});
}
bool bfs(){
      queue<int > q;
      dd[s]=++cnt;
      q.push(s);
      while(!q.empty()){
            int u=q.front();
            pos[u]=0;
            q.pop();
            for (int i=0;i<g[u].size();++i){
                  int id=g[u][i];
                  int v=edge[id].v;
                  if (dd[v]==cnt||edge[id].f==edge[id].c) continue;
                  dd[v]=cnt;
                  d[v]=d[u]+1;
                  q.push(v);
            }
      }
      return dd[t]==cnt;
}
int dfs(int u,int low){
      if (u==t||low==0) return low;
      for (;pos[u]<g[u].size();++pos[u]){
            int id=g[u][pos[u]];
            int v=edge[id].v;
            if (d[v]!=d[u]+1||edge[id].f==edge[id].c) continue;
            int x=dfs(v,min(low,edge[id].c-edge[id].f));
            if (x){
                  edge[id].f+=x;
                  edge[id^1].f-=x;
                  return x;
            }
      }
      return 0;
}
bool check(int M){
      s=2*n+1,t=2*n+2;
      int sum=0;
      for (int i=1;i<=2*n+2;++i)
            g[i].clear();
      edge.clear();
      for (int i=1;i<=n;++i){
            add_edge(s,i,1);
            add_edge(i+n,t,1);
      }
      for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
            if (cost[i][j]<=M) add_edge(i,j+n,1);
      while(bfs()){
            int x;
            while(1){
                  x=dfs(s,1e9);
                  if (x==0) break;
                  sum+=x;
            }
      }
      return sum==n;
}
int main(){
      freopen("ASSIGN1.inp","r",stdin);
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n;
      for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j){
                  cin>>cost[i][j];
                  MAXcost=max(MAXcost,cost[i][j]);
            }
      int l=1,r=MAXcost;
      while(l<=r){
            int m=(l+r)>>1;
            if (check(m)){
                  res=m;
                  r=m-1;
            }
            else l=m+1;
      }
      cout<<res;
}
