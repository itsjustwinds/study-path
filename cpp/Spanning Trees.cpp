#include<bits/stdc++.h>
#define maxn 1000000000
using namespace std;
int n,k,le,ri,dd[100005];
struct data{
	int u,v,c;
};
vector<data > edge;
int main(){
	freopen("Spanning Trees.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	ri=1e9;
	le=600000;
	if (n==1){
		if (k) cout<<-1;
		else cout<<0;
		return 0;
	}
	if (n==2){
		if (k==1) {
			cout<<1<<"\n";
			cout<<"1 2 1";
			return 0;
		}
		else cout<<-1;
		return 0;
	}
	if (n==3&&k==0){
        cout<<-1;
        return 0;
	}
	dd[1]=1;
	for (int i=1;i<=k;++i) {
		dd[i+1]=1;
		edge.push_back({1,i+1,maxn/2+1});
	}
	int x,y;
	if (k){
		x=1,y=2;
	}
	else {
		edge.push_back({1,2,le});
		le--;
		edge.push_back({1,3,ri});
		ri-=3;
		dd[2]=1;dd[3]=1;
		x=2,y=3;
	}
	for (int i=1;i<=n;++i)
	if (!dd[i]){
		edge.push_back({x,i,le});
		le--;
		edge.push_back({y,i,ri});
		ri-=3;
	}
	if (!k){
        for (int i=2;i<edge.size();i+=2)
            swap(edge[i].c,edge[i+1].c);
        edge.push_back({2,3,le});
        le--;
        edge.push_back({1,4,ri});
        ri-=3;
	}
	cout<<edge.size()<<"\n";
	for (int i=0;i<edge.size();++i)
        cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].c<<"\n";
}
