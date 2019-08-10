#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
map<string,int > m;
int n,res;
int main(){
	//freopen("ALCOHOL.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	m["ABSINTH"]=1;
	m["TEQUILA"]=1;
	m["VODKA"]=1;
	m["WHISKEY"]=1;
	m["WINE"]=1;
	m["BEER"]=1;
	m["BRANDY"]=1;
	m["CHAMPAGNE"]=1;
	m["GIN"]=1;
	m["RUM"]=1;
	m["SAKE"]=1;
	for (int i=1;i<=n;++i){
		string s;
		cin>>s;
		if (s[0]>='0'&&s[0]<='9'){
			int x=0;
			if (s.length()>2) continue;
			for (int j=0;j<s.length();++j)
				x=x*10+s[j]-'0';
			if (x<18) ++res;
		}
		else {
			if (m[s]) ++res;
		}
	}
	cout<<res;
}
