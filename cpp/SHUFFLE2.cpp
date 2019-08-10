#include<bits/stdc++.h>
using namespace std;
//map<int,int > Pos,Bit;
int Pos[10005],Bit[10005];
int n;
vector<int > a,b,Num;
void update(int u,int val){
	while(u<=n){
		Bit[u]+=val;
		u+=u&(-u);
	}
}
int get(int u){
	int res=0;
	while(u){
		res+=Bit[u];
		u-=u&(-u);
	}
	return res;
}
int main(){
	freopen("SHUFFLE2.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>n>>test;
	while(test--){
		int x,y;
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
		Num.push_back(x);
		Num.push_back(y);
	}
	sort(Num.begin(),Num.end());
	Num.resize(unique(Num.begin(),Num.end())-Num.begin());
	for (int i=0;i<Num.size();++i){
		int x=Num[i];
		Pos[x]=x;
	}
	for (int d=0;d<a.size();++d){
		int i=a[d];
		int j=b[d];
		int P=Pos[i];
		update(P+1,-1);
		P=Pos[j];
		update(P+1,1);
		Pos[i]=Pos[j]-1;
		Pos[j];
	}
	int ans=0;
	for (int i=0;i<Num.size();++i){
		int x=Num[i];
		int tmp=Pos[i];
		tmp+=get(Pos[i]);
		if (tmp<x) ++ans;
	}
	cout<<ans;
}
