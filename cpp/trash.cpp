#include<bits/stdc++.h>
#define db double
using namespace std;
struct data{
	int x,y;
};
vector<data > a,CVH,up,down;
int n;
bool cmp(data a,data b){
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int ccw(data a,data b,data c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
db dist(data a,data b){
	db u=a.x-b.x;
	db v=a.y-b.y;
	return sqrt(u*u+v*v);
}
db tinh(data a,data b,data c){
	db dt=abs(ccw(a,b,c));
	return dt/dist(a,b);
}
int main(){
	freopen("trash.inp","r",stdin);
	freopen("trash.out","w",stdout);
	int dem=0;
	while(1){
            ++dem;
		scanf("%d",&n);
		if (n==0) return 0;
		a.clear();
		CVH.clear();
		for (int i=1;i<=n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a.push_back({x,y});
		}
		sort(a.begin(),a.end(),cmp);
		data p1=a[0];
		data p2=a.back();
		up.clear();
		down.clear();
		up.push_back(p1);
		down.push_back(p1);
		for (int i=1;i<a.size();++i){
			data P=a[i];
			if (i==a.size()-1||ccw(p1,P,p2)<0){
				while(up.size()>1&&ccw(up[up.size()-2],up[up.size()-1],P)>=0) up.pop_back();
				up.push_back(P);
			}
			if (i==a.size()-1||ccw(p1,P,p2)>0){
				while(down.size()>1&&ccw(down[down.size()-2],down[down.size()-1],P)<=0) down.pop_back();
				down.push_back(P);
			}
		}
		for (int i=1;i<up.size()-1;++i)
			CVH.push_back(up[i]);
		for (int i=down.size()-1;i>=0;--i)
			CVH.push_back(down[i]);
		db res=1e9;
		for (int i=0;i<CVH.size();++i){
			data now=CVH[i];
			data pre;
			if (i==0) pre=CVH.back();
			else pre=CVH[i-1];
			db tmp=0;
			for (int i=0;i<CVH.size();++i)
				tmp=max(tmp,tinh(now,pre,CVH[i]));
			res=min(res,tmp);
		}
        cout<<"Case "<<dem<<": ";
		cout<<fixed<<setprecision(2)<<res<<"\n";
	}
}
