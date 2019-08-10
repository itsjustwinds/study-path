#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll a[maxn],n,Left,Right,NextLeft,NextRight;
map<ll,ll > pos;
vector<ll > AC,Times[maxn],Ac;
int main() {
    freopen("sp16_B.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (ll i=1; i<=n; ++i) {
        cin>>a[i];
        AC.push_back(a[i]);
    }
    AC.push_back(0);
    sort(AC.begin(),AC.end());
    AC.resize(unique(AC.begin(),AC.end())-AC.begin());
    for (ll i=0; i<AC.size(); ++i) {
        ll x=AC[i];
        pos[x]=i;
    }
    for (ll i=1; i<=n; ++i) {
        ll P=pos[a[i]];
        Times[P].push_back(i);
    }
    Times[0].push_back(1);
    for (ll i=1; i<AC.size(); ++i) {
        ll l=Times[i-1][0];
        ll r=Times[i-1].back();
        Right=NextRight;
        Left=NextLeft;
        // cal NextLeft
        ll x=Times[i].back();
        NextLeft=min(Left+abs(x-l),Right+abs(x-r))+1;
        for (ll j=(ll)Times[i].size()-2; j>=0; --j)
            NextLeft+=abs(Times[i][j]-Times[i][j+1])+1;
        //cal NextRight
        x=Times[i][0];
        NextRight=min(Left+abs(x-l),Right+abs(x-r))+1;
        for (ll j=0; j<(ll)Times[i].size()-1; ++j)
            NextRight+=abs(Times[i][j]-Times[i][j+1])+1;
    }
    cout<<min(NextLeft,NextRight);
}
