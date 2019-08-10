#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
using namespace std;
ll res,n;
priority_queue <ll,vector<ll>,greater<ll> > q;
int main()
{
    freopen("heap1.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n;
        res=0;
        for (int i=1; i<=n; i++)
        {
            ll x;
            cin>>x;
            q.push(x);
        }
        for (int i=1;i<=n-1;i++)
        {
            ll a=q.top();q.pop();
            ll b=q.top();q.pop();
            res+=a+b;
            q.push(a+b);
        }
        q.pop();
        cout<<res<<"\n";
    }
    return 0;
}
