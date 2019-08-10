#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,m,out[maxn],root,dd[maxn],Dtmp[maxn];
vector<int > e[maxn];
void dfs(int u) {
    if (Dtmp[u]) return;
    Dtmp[u]=1;
    for (int i=0; i<e[u].size(); ++i) {
        int v=e[u][i];
        dfs(v);
    }
}
int main() {
    //freopen("CONTEST.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; ++i) {
        int u,v;
        cin>>u>>v;
        out[u]++;
        e[v].push_back(u);
    }
    int ans=0;
    for (int XXX=1; XXX<=n; ++XXX) {
        int res=0;
        root=XXX;
        if (XXX==5){
            int KKK=1;
        }
        memset(dd,0,sizeof dd);
        while(1) {
            ++res;
            int ok=0;
            dd[root]=1;
            for (int i=0; i<e[root].size(); ++i) {
                int v=e[root][i];
                memset(Dtmp,0,sizeof Dtmp);
                dfs(v);
                int OK=1;
                for (int j=1; j<=n; ++j) {
                    if (dd[j]) continue;
                    if (Dtmp[j]==0) {
                        OK=0;
                        break;
                    }
                }
                if (OK) {
                    root=v;
                    ok=1;
                    break;
                }
            }
            if (ok==0) break;
        }
        ans=max(ans,res);
    }
    cout<<ans;
}
