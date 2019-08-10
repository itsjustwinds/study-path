#include<bits/stdc++.h>
#define maxn 300005
#define mod 1000000007
using namespace std;
struct data{
	int x,y;
};
struct node{
	int id,val,cnt;
};
node bit[maxn];
data a[maxn];
int n,f[maxn];
vector<int > AC;
bool cmp(data a,data b){
	return a.x<b.x;
}
void update(int u,int val,int cnt){
	while(u<maxn){
		if (bit[u].val<val){
			bit[u].val=val;
			bit[u].cnt=cnt;
		}
		else if (bit[u].val==val) bit[u].cnt=(bit[u].cnt+cnt)%mod;
		u+=u&(-u);
	}
}
vector<node > bitch;
void go_out_bitch(){
	for (int i=0;i<bitch.size();++i){
		int id=bitch[i].id;
		update(id,bitch[i].val,bitch[i].cnt);
	}
	bitch.clear();
}
node get(int u){
	node ans;
	ans.val=0;
	ans.cnt=0;
	while(u){
		if (bit[u].val>ans.val) {
			ans=bit[u];
		}
		else if (bit[u].val==ans.val) ans.cnt=(ans.cnt+bit[u].cnt)%mod;
		u-=u&(-u);
	}
	return ans;
}
int main(){
	freopen("MCONVOI.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	AC.push_back(0);
	for (int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
		AC.push_back(a[i].y);
	}
	sort(AC.begin(),AC.end());
	unique(AC.begin(),AC.end());
	for(int i=1;i<=n;++i)
		a[i].y=lower_bound(AC.begin(),AC.end(),a[i].y)-AC.begin()+1;
	sort(a+1,a+n+1,cmp);
	int pos=lower_bound(AC.begin(),AC.end(),0)-AC.begin()+1;
	if (a[1].y!=pos)update(pos,0,1);
	else {
        node tmp;
        tmp.val=0;
        tmp.cnt=1;
        bitch.push_back(tmp);
	}
	for (int i=1;i<=n;++i){
		if (a[i].x!=a[i-1].x){
			go_out_bitch();
		}
		node T=get(a[i].y-1);
		node tmp;
		tmp.id=a[i].y;
		tmp.val=T.val+1;
		tmp.cnt=T.cnt;
		if (a[i].y==pos) {
            tmp.val=0;
            tmp.cnt=1;
		}
		bitch.push_back(tmp);
	}
	go_out_bitch();
	node res=get(maxn-1);
	cout<<res.val<<"\n";
	cout<<res.cnt;
}
