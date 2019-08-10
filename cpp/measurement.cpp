#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data{
	int id,neg,who,val;
};
data a[maxn];
int n,D[3],trc;
bool cmp(data a,data b){
	return a.id<b.id;
}
int main(){
	freopen("measurement.in","r",stdin);
	//freopen("measurement.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i].id;
		string S;
		cin>>S;
		if (S[0]=='M') a[i].who=0;
		else if (S[0]=='B') a[i].who=1;
		else a[i].who=2;
		char s;
		cin>>s;
		if (s=='-') a[i].neg=-1;
		else a[i].neg=1;
		cin>>a[i].val;
	}
	int res=0;
	trc=-1;
	D[0]=D[1]=D[2]=7;
	sort(a+1,a+n+1,cmp);
	a[++n]={100000,0,0,0};
	for (int i=1;i<=n;++i){
		if (a[i].id==a[i-1].id){
			int x=a[i].who;
			D[x]+=a[i].neg*a[i].val;
			continue;
		}
		int k=0;
		for (int j=0;j<=2;++j)
			if (D[k]<D[j]) k=j;
		if (k!=trc){
			++res;
			trc=k;
		}
		int x=a[i].who;
		D[x]+=a[i].neg*a[i].val;
	}
	cout<<res-1;
}
