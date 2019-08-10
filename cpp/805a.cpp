#include<bits/stdc++.h>
using namespace std;
int l,r;
vector<int> e;
int main()
{
    //freopen("805a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>l>>r;
    if (l<r) cout<<2;
    else cout<<l;
    return 0;
}
