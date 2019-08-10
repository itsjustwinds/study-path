#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,ans;
int power(int n){
	if (n==0) return 1;
	if (n==1) return 2;
	int tmp=power(n>>1);
	tmp=(1ll*tmp*tmp)%mod;
	if (n&1) tmp=(1ll*tmp*2)%mod;
	return tmp;
}
int main(){
	freopen("CBOOTH.inp","r",stdin);
	cin>>n;
	if (n<=2) {
        return 0;
	}
	cout<<(2ll*(power(n-1)-n+mod)%mod)%mod;
	return 0;
}
