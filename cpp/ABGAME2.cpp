#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b;
int main(){
	freopen("ABGAME2.inp","r",stdin);
	//freopen("ABGAME2.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string TST;
	while(getline(cin,TST)){
		//getline(cin,TST);
		int x=0;
		a=0,b=0;
		TST=TST+' ';
		for (int i=0;i<TST.size();++i)
		if (TST[i]==' '){
			if (a==0){
				a=x;
			}
			else if (b==0)b=x;
			x=0;
		}
		else {
			x=x*10+TST[i]-'0';
		}
		int Win=1;
		while(1){
			if (a<b) swap(a,b);
			a%=b;
			if (a==0||a==1) break;
			Win=1-Win;
		}
		if (Win)cout<<"YES\n";
			else cout<<"NO\n";
	}
}
