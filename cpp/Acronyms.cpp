#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int dd[26],total[26],n;
string s[maxn];
int main(){
	freopen("Acronyms.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>s[i];
	for (int i=1;i<=n;++i){
		total[s[i][0]-'a']++;
	}
	int res=0;
	for (int i=1;i<=n;++i){
		memset(dd,0,sizeof dd);
		for (int j=0;j<s[i].length();++j)
			dd[s[i][j]-'a']++;
		dd[s[i][0]-'a']++;
		int ok=1;
		for (int j=0;j<=26;++j)
			if (dd[j]>total[j]) ok=0;
		if (ok) ++res;
	}
	cout<<res;
}
