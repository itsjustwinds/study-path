#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
struct data{
	int a,b;
};
int n,res;
data a[maxn];
bool cmp(data a,data b){
	if (a.b!=b.b)return a.b>b.b;
	return a.a<b.a;
}
struct pri{
    bool operator()(int a,int b){
        return a<b;
    }
};
bool check(int k){
	ll sum=0;
	priority_queue<int,vector<int>,pri > q;
	for (int i=1;i<=k;++i){
        sum+=a[i].a;
        q.push(a[i].a);
	}
    if (1ll*a[k].b*k>=sum) return 1;
    for (int i=k+1;i<=n;++i){
        int x=q.top();
        q.pop();
        sum-=x;
        q.push(a[i].a);
        sum+=a[i].a;
        if (1ll*a[i].b*k>=sum) return 1;
    }
    return 0;
}
int main(){
	freopen("BACTERIUM.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int l=1,r=n;
	for (int i=1;i<=n;++i)
		cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1,cmp);
	while(l<=r){
		int m=(l+r)>>1;
		if (check(m)){
			res=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout<<res;
}
