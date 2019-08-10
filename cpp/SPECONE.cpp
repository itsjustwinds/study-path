#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int > II;
int n,m,cnt,stage[maxn],Need,Special;
queue<int > q;
string Name[maxn];
map<string,int > Num;
map<II,int > dd;
vector<int > e[maxn],res;
vector<string > ans;
int get(string s){
	if (Num[s]!=0) return Num[s];
	if (Num[s]==0) Num[s]=++cnt;
	Name[cnt]=s;
	return Num[s];
}
int main(){
	freopen("SPECONE.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Need>>Special>>m;
	for (int i=1;i<=Special;++i){
		string s;
		cin>>s;
		int x=get(s);
		q.push(x);
		stage[x]=Need;
	}
	for (int i=1;i<=m;++i){
		string First,Second;
		cin>>First>>Second;
		int F=get(First);
		int S=get(Second);
		if (F<S) swap(F,S);
		II tmp=II(F,S);
		if (dd[tmp]) continue;
		e[F].push_back(S);
		e[S].push_back(F);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		res.push_back(u);
		for (int i=0;i<e[u].size();++i){
			int v=e[u][i];
			++stage[v];
			if (stage[v]==Need) q.push(v);
		}
	}
	for (int i=0;i<res.size();++i)
		ans.push_back(Name[res[i]]);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for (int i=0;i<ans.size();++i)
		cout<<ans[i]<<" ";
}
