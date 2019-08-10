#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,res;
int main()
{
    //freopen("food.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x>>y>>z;
    n-=z;
    int tmp1=y-(n-x);
    int tmp2=x-(n-y);
    res=max(tmp1,tmp2);
    cout<<res;
    return 0;
}
