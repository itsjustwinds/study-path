#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,k,a[maxn],res,P[maxn][35],b[maxn],dem;
vector<int > e[maxn];
int get(int i,int j){
    if (i>j) return -1;
    int log=log2(j-i+1);
    int x=P[i][log];
    int y=P[j-(1<<log)+1][log];
    if (a[x]>a[y]) return x;
    return y;
}
int go(int l,int r){
    if (l>r) return -1;
    int res=get(l,r);
    int Left=go(l,res-1);
    int Right=go(res+1,r);
    if (Left!=-1) e[res].push_back(Left);
    if (Right!=-1) e[res].push_back(Right);
    return res;
}
void dfs(int u){
    for (int i=0;i<e[u].size();++i){
        int v=e[u][i];
        dfs(v);
    }
    b[++dem]=u;
}
void solve(){
    dem=0;
    memset(P,0,sizeof P);
    for (int i=1;i<=n;++i)
        P[i][0]=i;
    for (int j=1;1<<j<=n;++j){
        for (int i=1;i+(1<<j)-1<=n;++i){
            int x=P[i][j-1];
            int y=P[i+(1<<(j-1))][j-1];
            if (a[x]>a[y]) P[i][j]=x;
            else P[i][j]=y;
        }
    }
    for (int i=1;i<=n;++i) e[i].clear();
    int root=go(1,n);
    dfs(root);
    ++res;
    for (int i=1;i<=n;++i)
    if (a[b[i]]!=i) {
        res--;
        return;
    }
}
int main(){
	freopen("TSORT.inp","r",stdin);
	freopen("TSORT.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
    int DDD=0;
	do{
		solve();
        ++DDD;
        if (DDD==k) break;
	}while(next_permutation(a+1,a+n+1));
	cout<<res;
}
