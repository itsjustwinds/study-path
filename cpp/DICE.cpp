#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,res1,res2;
int main()
{
        //freopen("DICE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin>>n;
        res2=n*6;
        res1=n/6;
        n%=6;
        res1+=7-n;
        cout<<res1<<" "<<res2;
        return 0;
}
