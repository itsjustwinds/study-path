#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int a[maxn],len,dem;
string s;
int main(){
	freopen("Inverse Factorial.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.length();
	if (len<=18){
		long long x=0;
		for (int i=0;i<len;++i)
			x=x*10+s[i]-'0';
		if (x==0){
			cout<<0;
			return 0;
		}
		ll now=1;
		for (int i=1;i<=1e9;++i){
			now*=i;
			if (now==x) {
				cout<<i;
				return 0;
			}
		}
	}
	double Log=0;
	for (int i=1;i<=1e9;++i){
        double L=(double) log10(i);
		Log+=L;
		a[i]=(int)Log+1;
		if (a[i]>=1e6) break;
	}
	int res=0;
	int l=1,r=1e6;
	for (int i=1;i<=1e7;++i)
		if (a[i]==len){
			cout<<i;
			return 0;
		}
}
