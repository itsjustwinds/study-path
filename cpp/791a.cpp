#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    int res=0;
    while(a<=b)
    {
        a*=3;
        b*=2;
        res++;
    }
    cout<<res;
    return 0;
}
