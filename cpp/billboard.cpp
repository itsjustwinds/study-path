#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int dd[2*maxn][2*maxn];
int main(){
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	y1++;
	x1++;
	for (int x=x1;x<=x2;++x)
		for (int y=y1;y<=y2;++y)
			dd[x+maxn][y+maxn]=1;
	cin>>x1>>y1>>x2>>y2;
	y1++;
	x1++;
	for (int x=x1;x<=x2;++x)
		for (int y=y1;y<=y2;++y)
			dd[x+maxn][y+maxn]=1;
	cin>>x1>>y1>>x2>>y2;
	y1++;
	x1++;
	int res=0;
	for (int x=x1;x<=x2;++x)
		for (int y=y1;y<=y2;++y)
			dd[x+maxn][y+maxn]=0;
	for (int x=-1000;x<=1000;++x)
		for (int y=-1000;y<=1000;++y)
			res+=dd[x+maxn][y+maxn];
	cout<<res;
}
