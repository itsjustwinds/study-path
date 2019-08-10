#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,x1,x2,k1,k2;
long long res;
int main()
{
    freopen("CartesianCountry.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>a2;
    cin>>b1>>b2;
    cin>>x1>>x2;
    k1=a1-1;
    k2=a2-1;
    b1-=k1;
    b2-=k2;
    x1-=k1;
    x2-=k2;
    a1=1;
    a2=1;
    res=(min(b2-x2+1,x2-a2+1)*2LL-1)*(min(b1-x1+1,x1-a1+1)*2LL-1);
    res-=1;
    res/=2;
    cout<<res;
    return 0;
}
