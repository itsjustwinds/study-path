#include<bits/stdc++.h>
#define maxn 3005
#define ll long long
using namespace std;
struct data {
    int x,y;
};
int top[maxn][maxn],down[maxn][maxn],n;
data a[maxn];
ll res;
ll ccw(data a,data b,data c) {
    return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
}
int main() {
    freopen("QBCAKE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i].x>>a[i].y;
    if (ccw(a[1],a[2],a[3])>0) reverse(a+1,a+n+1);
    for (int i=1; i<=n; ++i)
        a[i+n]=a[i];
    for (int k=1; k<n; ++k) {
        int j=k+1;
        if (k==3){
            int ok=1;
        }
        for (int i=k+2; i<k+n-1; ++i) {
            while(j+1<i&&abs(ccw(a[k],a[j],a[i]))<=abs(ccw(a[k],a[j+1],a[i])))
                ++j;
            top[k][i]=j;
        }
        j=k+n-1;
        for (int i=k+n-2; i>=k+2; --i) {
            while(j-1>i&&abs(ccw(a[k],a[j],a[i]))<=abs(ccw(a[k],a[j-1],a[i])))
                --j;
            down[k][i]=j;
        }
    }
    for (int i=1; i<=n; ++i)
        for (int j=i+2; j<=i+n; ++j) {
            if (top[i][j]==0||down[i][j]==0) break;
            res=max(res,abs(ccw(a[i],a[top[i][j]],a[j]))+abs(ccw(a[i],a[down[i][j]],a[j])));
        }
    double ans=(double)res/2;
    cout<<setprecision(1)<<fixed<<ans;
}
