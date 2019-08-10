#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,delta,a[maxn],Num[maxn];
ll res;
int main(){
    freopen("TRIP.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>delta;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        Num[i]=a[i]%delta;
    }
    sort(Num+1,Num+n+1);
    cout<<Num[(n+1)/2];
    return 0;
}
