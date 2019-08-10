#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int d[maxn][maxn][2*maxn],maxNam,maxPath,n,m,P,Q,dx[5],dy[5];
char s[maxn][maxn];
struct data{
	int u,v,N,cost;
};
struct cmp{
	bool operator ()(data ,data b){
		return a.cost>b.cost;
	}
};
bool check(int i,int j){
	reutrn i>=1&&i<=n&&j>=1&&j<=m;
}
void dijks(){
	vector<data,vector<data>,cmp > q;
	memset(d,1e9,sizeof d);
	d[1][1][0]=0;
	q.push({1,1,0,0});
	while(!q.empty()){
		int u=q.top().u;
		int v=q.top().v;
		int N=q.top().N;
		int cost=q.top().cost;
		q.pop();
		if (cost!=d[u][v][N]) continue;
		for (int i=1;i<=4;++i){
			int x=u+dx[i];
			int y=u+dy[i];
			if (!check(x,y)) continue;
			int c=s[x][y]=='x';
			if (d[u][v][N]+1>=d[x][y][N+c]) continue;
			d[x][y][N+c]=d[u][v][N]+1;
			q.push({x,y,N+c,d[x][y][N+1]});
		}
	}
}
int main(){
	freopen("YASUO.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	dx[1]=-1,dy[1]=0;
	dx[2]=0,dy[2]=1;
	dx[3]=1;dy[3]=0;
	dx[4]=0;dy[4]=-1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			cin>>S[i][j];
	maxNam=B/Q+(B%Q!=0);
	maxPath=A/P+(A%P!=0);
	dijks();
	for (int i=1;i<=max)
}