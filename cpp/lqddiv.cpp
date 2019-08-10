#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
#define fs first
#define sc second
using namespace std;
int a[maxn],n;
ll sum1[maxn],sum2[maxn],d1,d2,res,SUM,Newd,CNT;
typedef pair<ll,ll > II;
II Newsum[maxn];
void dfs1(int i,ll sum) {
    if (i==n/2+1) {
        sum1[++d1]=sum;
        return;
    }
    dfs1(i+1,sum);
    dfs1(i+1,sum+a[i]);
}
void dfs2(int i,ll sum) {
    if (i==n+1) {
        sum2[++d2]=sum;
        return;
    }
    dfs2(i+1,sum);
    dfs2(i+1,sum+a[i]);
}
int findd(int l,int r,ll x) {
    int res=0;
    while(l<=r) {
        int m=(l+r)>>1;
        if (x+Newsum[m].fs<=SUM/2) {
            res=m;
            l=m+1;
        } else r=m-1;
    }
    return res;
}
int main() {
    freopen("LQDDIV.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        SUM+=a[i];
    }
    res=SUM;
    dfs1(1,0);
    dfs2(n/2+1,0);
    sort(sum2+1,sum2+d2+1);
    Newd=1;
    Newsum[Newd]= {0,1};
    for (int i=2; i<=d2; ++i) {
        if(sum2[i]==sum2[i-1]) Newsum[Newd].sc++;
        else {
            ++Newd;
            Newsum[Newd]= {sum2[i],1};
        }
    }
    d2=Newd;
    for (int i=1; i<=d1; ++i) {
        ll x1=sum1[i];
        int x2=findd(1,d2,x1);
        ll c=abs(x1+Newsum[x2].fs-(SUM-x1-Newsum[x2].fs));
        if (res>c) {
            res=c;
            CNT=Newsum[x2].sc;
        } else if (res==c) {
            CNT+=Newsum[x2].sc;
        }
        ++x2;
           c=abs(x1+Newsum[x2].fs-(SUM-x1-Newsum[x2].fs));
        if (res>c) {
            res=c;
            CNT=Newsum[x2].sc;
        } else if (res==c) {
            CNT+=Newsum[x2].sc;
        }
    }
    cout<<res<<" "<<CNT/2;
}
