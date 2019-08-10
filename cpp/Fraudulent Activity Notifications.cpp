#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,d,a[maxn],res;
struct data {
    vector<int > x;
};
data st[4*maxn];
vector<int > combine(vector<int > a,vector<int > b) {
    int n=a.size()-1;
    int m=b.size()-1;
    int nowM=0;
    vector<int > c;
    c.clear();
    for (int nowN=0; nowN<=n; ++nowN) {
        while(nowM<=m&&a[nowN]>b[nowM]) {
            c.push_back(b[nowM++]);
        }
        c.push_back(a[nowN]);
    }
    while(nowM<=m) c.push_back(b[nowM++]);
    return c;
}
void build(int id,int l,int r) {
    if (l==r) {
        st[id].x.push_back(a[l]);
        return;
    }
    int m=(l+r)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id].x=combine(st[id*2].x,st[id*2+1].x);
}
int findd(vector<int > a,int x) {
    int res=-1;
    int l=0,r=a.size()-1;
    while(l<=r) {
        int m=(l+r)>>1;
        int k=a[m];
        if (a[m]<=x) {
            res=m;
            l=m+1;
        } else r=m-1;
    }
    return res+1;
}
int get(int id,int l,int r,int i,int j,int x) {
    if (l>j||r<i) return 0;
    if (l>=i&&r<=j) {
        int X=findd(st[id].x,x);
        return X;
    }
    int m=(l+r)>>1;
    return get(id*2,l,m,i,j,x)+get(id*2+1,m+1,r,i,j,x);
}
int getM(int l,int r) {
    int L=0,R=400;
    int res=0;
    while(L<=R) {
        int m=(L+R)>>1;
        if (get(1,1,n,l,r,m)>=(d+1)/2) {
            res=m;
            R=m-1;
        } else L=m+1;
    }
    int ans=res;
    L=0,R=400;
    res=0;
    while(L<=R) {
        int m=(L+R)>>1;
        if (get(1,1,n,l,r,m)>=d/2+1) {
            res=m;
            R=m-1;
        } else L=m+1;
    }
    return (ans+res)/2;
}
int main() {
    freopen("Fraudulent Activity Notifications.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        a[i]<<=1;
    }
    build(1,1,n);
    for (int i=d; i<n; ++i) {
        int x=getM(i-d+1,i);
        if (x<=a[i+1]/2) ++res;
    }
    cout<<res;
}
