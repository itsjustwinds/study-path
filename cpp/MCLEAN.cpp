#include<bits/stdc++.h>
#define maxn 25
using namespace std;
struct data{
	int x,y;
};
data P[maxn];
int n,m,cnt,M,dd[maxn][maxn],cost[maxn][maxn],f[1500][maxn],dx[5],dy[5],D[maxn][maxn];
char s[maxn][maxn];
bool check(int i,int j){
    return i>=1&&i<=n&&j>=1&&j<=m&&s[i][j]!='x';
}
void bfs(int id){
	cost[id][id]=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			D[i][j]=1e9;
	D[P[id].x][P[id].y]=0;
	queue<data > q;
	q.push({P[id].x,P[id].y});
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		q.pop();
		for (int i=1;i<=4;++i){
			int u=x+dx[i];
			int v=y+dy[i];
			if (!check(u,v)) continue;
			if (u==4&&y==2){
                int ok=1;
			}
			int ID=dd[u][v];
			if (D[x][y]+1<D[u][v]){
				D[u][v]=D[x][y]+1;
				if (s[u][v]=='*'){
					cost[id][ID]=D[u][v];
				}
				q.push({u,v});
			}
		}
	}
}
int main(){
	freopen("MCLEAN.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dx[1]=-1;dy[1]=0;
	dx[2]=0;dy[2]=1;
	dx[3]=1;dy[3]=0;
	dx[4]=0;dy[4]=-1;
	while(1){
		cin>>m>>n;
		if (n==0) break;
		cnt=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j){
				cin>>s[i][j];
				if (s[i][j]=='o'){
					P[0]={i,j};
				}
				if (s[i][j]=='*'){
					P[++cnt]={i,j};
					dd[i][j]=cnt;
				}
			}
		for (int i=0;i<=cnt;++i)
			for (int j=0;j<=cnt;++j)
				cost[i][j]=1e9;
		for (int i=0;i<=cnt;++i)
			bfs(i);
		M=(1<<cnt)-1;
		for (int i=1;i<=M;++i)
			for (int j=0;j<=cnt;++j)
				f[i][j]=1e9;
		for (int i=1;i<=cnt;++i)
				f[1<<(i-1)][i]=cost[0][i];
		for (int mask=1;mask<=M;++mask){
			for (int i=1;i<=cnt;++i){
				if (!((mask>>(i-1))&1)) continue;
				int MASK=mask^(1<<(i-1));
				if (MASK==0) continue;
				for (int j=1;j<=cnt;++j){
					if (!((MASK>>(j-1))&1)) continue;
					if (f[MASK][j]+cost[j][i]<f[mask][i]) f[mask][i]=f[MASK][j]+cost[j][i];
				}
			}
		}
		int res=1e9;
		for (int i=1;i<=cnt;++i)
			res=min(res,f[M][i]);
		if (res>=1e9) cout<<"-1\n";
		else cout<<res<<"\n";
	}
}
