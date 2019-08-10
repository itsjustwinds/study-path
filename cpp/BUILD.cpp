#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data{
	int x,y,c;
};
vector<data > edge;
int n,root[maxn];
ll res;
int getr(int u){
	if (root[u]==u) return u;
	root[u]=getr(root[u]);
	return root[u];
}
data a[maxn];
bool cmpx(data a,data b){
	return a.x<b.x;
}
bool cmpy(data a,data b){
	return a.y<b.y;
}
bool cmp(data a,data b){
	return a.c<b.c;
}
int main(){
	//freopen("BUILD.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
		a[i].c=i;
	}
	sort(a+1,a+n+1,cmpx);
	for (int i=1;i<=n-1;++i){
		edge.push_back({a[i].c,a[i+1].c,abs(a[i].x-a[i+1].x)});
		if (i+2<=n) edge.push_back({a[i].c,a[i+2].c,abs(a[i].x-a[i+2].x)});
	}
	sort(a+1,a+n+1,cmpy);
	for (int i=1;i<=n-1;++i){
		edge.push_back({a[i].c,a[i+1].c,abs(a[i].y-a[i+1].y)});
		if (i+2<=n) edge.push_back({a[i].c,a[i+2].c,abs(a[i].y-a[i+2].y)});
	}
	sort(edge.begin(),edge.end(),cmp);
	int d=0;
	for (int i=1;i<=n;++i)
        root[i]=i;
	for (int i=0;i<edge.size();++i){
		int u=edge[i].x;
		int v=edge[i].y;
		int c=edge[i].c;
		int ru=getr(u);
		int rv=getr(v);
		if (ru==rv) continue;
		root[ru]=rv;
		res+=c;
		d++;
		if (d==n-1) break;
	}
	cout<<res;
}
