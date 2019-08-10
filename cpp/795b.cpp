#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int>a[100005], b[100005];
int n, m, l, r;
long long d, w, cur, ans, p[100005], p2[100005];
bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.first==y.first) return x.second<y.second;
	return x.first>y.first;
}
int main () {
    freopen("795b.inp","r",stdin);
	scanf("%d %d %lld", &n, &m, &d);
	for (int i=0; i<n; i++) {
		scanf("%d %d", &a[i].first ,&a[i].second);
	}
	for (int i=0; i<m; i++) {
		scanf("%d %d", &b[i].first, &b[i].second);
	}
	sort(a,a+n,cmp);
	sort(b,b+m, cmp);
	for (int i=0; i<m; i++) {
		p[i+1]=p[i]+b[i].first;
		p2[i+1]=p2[i]+b[i].second;
	}
	for (int i=0; i<n; i++) {
		w+=a[i].second;
		cur+=a[i].first;
		int lo=1, hi=m;
		while (lo+1<hi) {
			int mid=(lo+hi)/2;
			long long s=p2[mid];
			if (w+s<=d) lo=mid;
			else hi=mid;
		}
		if (w+p2[hi]<=d) lo=hi;
		if (w+p2[lo]>d) continue;
		ans=max(ans, cur+p[lo]);
	}
	printf("%lld\n", ans);
	return 0;
}
