#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,m,s,t,pos[maxn],dd[maxn],d[maxn],cnt,res;
struct data{
      int u,v,f,c;
};
vector<data> edge;
vector<int > g[maxn];
void add_edge(int u,int v,int c){
      g[u].push_back(edge.size());
      edge.push_back({u,v,0,c});
      g[v].push_back(edge.size());
      edge.push_back({v,u,0,0});
}
bool bfs(){
      dd[s]=++cnt;
      queue<int > q;
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
void trace(){
    for (int id=0;id<edge.size();++id){
        if (edge[id].f<=0) continue;
        int u=edge[id].u;
        int v=edge[id].v;
        if (u<=n&&v>n&&v<=n+m){
            cout<<u<<" "<<v-n<<"\n";
        }
    }
}
void solve(){
      while(bfs()){
            int x;
            while(1){
                  x=dfs(s,1e9);
                  if (x==0) break;
                  res+=x;
            }
      }
      cout<<res<<"\n";
      trace();
}
int main(){
      freopen("MATCH1.inp","r",stdin);
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      cin>>n>>m;
      int u,v;
      s=n+m+1,t=n+m+2;
      for (int i=1;i<=n;++i)
            add_edge(s,i,1);
      for (int i=1;i<=m;++i)
            add_edge(i+n,t,1);
      while(cin>>u>>v){
            add_edge(u,v+n,1);
      }
      solve();
}
