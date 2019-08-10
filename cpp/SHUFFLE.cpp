#include<bits/stdc++.h>
#define maxn 105
using namespace std;
string res[maxn],s[maxn];
int a[maxn];
int n;
int main(){
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		cin>>s[i];
	for (int i=1;i<=n;++i)
		res[a[i]]=s[i];
	for (int i=1;i<=n;++i)
		cout<<res[i]<<"\n";
}
