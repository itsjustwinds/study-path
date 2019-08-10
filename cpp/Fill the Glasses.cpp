#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,k,a[maxn],lef,res;
int main(){
	freopen("Fill the Glasses.inp","r",stdin);
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	long long res=0;
	for (int i=1;i<=k;++i)
		sum+=a[i];
	res=sum/100+(sum%100!=0);
	cout<<res;
}
