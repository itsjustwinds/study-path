#include<bits/stdc++.h>
using namespace std;
int t1,t2;
int main()
{
    //freopen("dicegame.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    t1=x1+x2+x3+x4;
    cin>>x1>>x2>>x3>>x4;
    t2=x1+x2+x3+x4;
    if (t1>t2) cout<<1;
    else if (t1<t2) cout<<2;
    else cout<<3;
    return 0;
}
