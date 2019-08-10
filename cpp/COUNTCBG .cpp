#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main()
{
    //freopen("COUNTCBG.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n)
    {
        ll res=0;
        for (int i=2;i*i<=2*n;i++)
            if (2*n%i==0)
        {
            if ((i+2*n/i-1)%2==0) res++;
        }
        cout<<res<<"\n";
    }
    return 0;
}
