#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][2];
int n;
struct data{
	int v,c;
};
vector<data > e[maxn];
void reset(){
	for (int i=1;i<=n;++i){
		e[i].clear();
		for (int j=0;j<=1;++j)
			f[i][j]=1e9;
	}
}
int cal(int u,int val){
	if (f[u][val]!=1e9) return f[u][val];
	if (e[u].size()==0){
		if (val==0) return 0;
		return 1e9;
	}
	int sum=0;
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i].v;
		int c=e[u][i].c;
		int tmp=1e9;
		for (int j=0;j<=val;++j){
			tmp=min(tmp,(val-j)*c+cal(v,j));
		}
		sum+=tmp;
	}
	f[u][val]=sum;
	return f[u][val];
}
void write(int x){
	if (x>=100){
		cout<<x/100;
		cout<<".";
		write(x%100);
		return;
	}
	cout<<x/10;
	cout<<x%10;
}
void solve(){
	for (int i=2;i<=n;++i){
		int u,c;
		cin>>u>>c;
		e[u].push_back({i,c});
	}
	int res=cal(1,1);
	cout<<res<<".00\n";
}
int main(){
	freopen("ITREE.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while(test--){
		cin>>n;
		reset();
		solve();
	}
}
