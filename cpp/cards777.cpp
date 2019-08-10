#include<bits/stdc++.h>
using namespace std;
int re,bl,a,b;
int main()
{
    //freopen("cards777.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>re>>bl>>a;
        b=re+bl-a;
        double res=max(min(re,a),min(bl,b));
        cout<<fixed<<setprecision(10)<<res<<"\n";
    }
    return 0;
}
