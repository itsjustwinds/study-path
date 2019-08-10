#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int p[maxn],n,dem,R[maxn],B[maxn],dR,dB,costR[maxn],costB[maxn];
ll Rcon[maxn],Rnew[maxn],Bcon[maxn],Bnew[maxn];
long long res;
struct data{
    int pos;
    char c;
};
data a[maxn];
int findd(int l,int r,int x){
    int res=1e9;
    while(l<=r){
        int m=(l+r)>>1;
        if (x<=p[m]){
            res=min(res,abs(x-p[m]));
            r=m-1;
        }
        else {
            res=min(res,abs(x-p[m]));
            l=m+1;
        }
    }
    return res;
}
int findd1(int l,int r,int x){
    int res=1e9;
    while(l<=r){
        int m=(l+r)>>1;
        if (x<=B[m]){
            res=min(res,abs(x-B[m]));
            r=m-1;
        }
        else {
            res=min(res,abs(x-B[m]));
            l=m+1;
        }
    }
    return res;
}
void solve(){
    for (int i=1;i<=n;++i)
    if (a[i].c=='R') R[++dR]=a[i].pos;
    else if (a[i].c=='B')B[++dB]=a[i].pos;
    sort(R+1,R+dR+1);
    sort(B+1,B+dB+1);
    for (int i=1;i<dR;++i)
        res+=R[i+1]-R[i];
    for (int i=1;i<dB;++i)
        res+=B[i+1]-B[i];
    int minn=1e9;
    for (int i=1;i<=dR;++i){
        minn=min(minn,findd1(1,dB,R[i]));
    }
    if (minn==1e9) minn=0;
    res+=minn;
}
int main(){
    freopen("908F.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].pos>>a[i].c;
        if (a[i].c=='G') p[++dem]=a[i].pos;
        if (a[i].c=='R') R[++dR]=a[i].pos;
        if (a[i].c=='B') B[++dB]=a[i].pos;
    }
    if (dem==0){
        solve();
        cout<<res;
        return 0;
    }
    sort(p+1,p+dem+1);
    sort(R+1,R+dR+1);
    sort(B+1,B+dB+1);
    for (int i=1;i<dem;++i)
        res+=p[i+1]-p[i];
    for (int i=1;i<=dR;++i){
        int x=findd(1,dem,R[i]);
        costR[i]=x;
    }
    for (int i=1;i<=dB;++i){
        int x=findd(1,dem,B[i]);
        costB[i]=x;
    }

}
