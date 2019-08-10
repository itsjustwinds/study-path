#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int res,n,a[maxn],b[maxn];
void maximize(int &a,int &b,int c){
	if (c>a) {
			b=a;
			a=c;
		}
	else if (c>b) b=c;
}
bool check(int m){
	int MAX1=0;
	int MAX2=0;
	for (int i=1;i<=n;++i){
		if (b[i]>=m){
			maximize(MAX1,MAX2,a[i]);
			if (MAX1!=0&&MAX2!=0){
				if (MAX1+MAX2>=m) return 1;
			}
		}
		else {
			MAX1=0;
			MAX2=0;
		}
	}
	return 0;
}
int main(){
	//freopen("SEQAB.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int j=1;j<=n;++j)
		cin>>b[j];
	int l=1,r=1e8;
	while(l<=r){
		int m=(l+r)>>1;
		if (check(m)){
			res=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout<<res;
}
