#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,k1,k2;
char a[maxn],b[maxn],res[maxn];
vector<int > Diferrent,Same;
int main(){
	freopen("HD1.inp","r",stdin);
	//freopen("HD1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>k1>>k2;
	cin>>(a+1);
	cin>>(b+1);
	n=strlen(a+1);
	k1=n-k1;k2=n-k2;
	for (int i=1;i<=n;++i)
	if (a[i]==b[i]) Same.push_back(i);
	else Diferrent.push_back(i);
	for (int i=0;i<Diferrent.size();++i){
		int Pos=Diferrent[i];
		if (k1>=k2){
			res[Pos]=a[Pos];
			--k1;
		}
		else {
			res[Pos]=b[Pos];
			--k2;
		}
	}
	for (int i=0;i<Same.size();++i){
		int Pos=Same[i];
		if (k1>0){
			res[Pos]=a[Pos];
			--k1;
		}
		else res[Pos]=(char)(1-(a[Pos]-'0')+'0');
	}
	for (int i=1;i<=n;++i)
		cout<<res[i];
}