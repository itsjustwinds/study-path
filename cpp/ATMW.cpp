#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cash,c,res,ans;
ll Power(ll a,ll n) {
    if (n==0)
        return 1;
    if (n==1)
        return a;
    ll tmp=Power(a,n/2);
    tmp=tmp*tmp;
    if (n&1)
        tmp=tmp*a;
    return tmp;
}
ll cach(ll ways) {
    if (ways>10)
        return cach(5+ways%5);
    if (ways==10) return 1;
    if (ways==9) return 3;
    if (ways==8) return 1;
    if (ways==7) return 1;
    if (ways==6) return 2;
    if (ways==5) return 1;
    if (ways==4) return 2;
    if (ways==3) return 1;
    if (ways==2) return 1;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>cash>>c;
    if (cash%1000!=0) {
        cout<<0;
        return 0;
    }
    ans=1;
    for (int C=c; C>=0; --C) {
        ll tmp;
        tmp=1ll*1000*Power(10,C);
        ll ways=cash/tmp;
        ans=ans*cach(ways);
        tmp=1ll*5000*Power(10,C);
        if (cash>=tmp) {
            res+=cash/tmp;
            cash%=tmp;
        }
        tmp=1ll*3000*Power(10,C);
        if (cash>=tmp) {
            res+=cash/tmp;
            cash%=tmp;
        }
        tmp=1ll*2000*Power(10,C);
        if (cash>=tmp) {
            res+=cash/tmp;
            cash%=tmp;
        }
        tmp=1ll*1000*Power(10,C);
        if (cash>=tmp) {
            res+=cash/tmp;
            cash%=tmp;
        }
    }
    cout<<res<<" "<<ans;
}
