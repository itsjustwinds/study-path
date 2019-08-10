#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,d;
int gcd(int a,int b,int &x,int &y){
	int r,xm,xn,xr,n,m;
	xm=1,xn=0;
	n=b,m=a;
	while(n){
		int q=m/n;
		r=m-n*q;
		xr=xm-xn*q;
		m=n;n=r;
		xm=xn;xn=xr;
	}
	x=xm;y=(m-a*xm)/b;
	return m;
}
void solve(){
	d=gcd(a,b,x,y);
	if (c%d){
		cout<<"-1\n";
		return;
	}
	int TT=c/d;
	x*=TT;
	y*=TT;
	int Tmpa=a/d;
	int Tmpb=b/d;
	int res=abs(x)+abs(y);
	while(abs(x+Tmpb)+abs(y-Tmpa)<abs(x)+abs(y)){
		x+=Tmpb;
		y-=Tmpa;
	}
	res=min(res,abs(x)+abs(y));
	while(abs(x-Tmpb)+abs(y+Tmpa)<abs(x)+abs(y)){
		x-=Tmpb;
		y+=Tmpa;
	}
	res=min(res,abs(x)+abs(y));
	cout<<res<<"\n";
}
int main(){
	freopen("CWATER.inp","r",stdin);
	freopen("CWATER.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while(test--){
		cin>>a>>b>>c;
		solve();
	}
}
