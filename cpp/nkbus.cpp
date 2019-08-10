#include<bits/stdc++.h>
using namespace std;
int n,m,trc;
int res;
int main()
{
    freopen("nkbus.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    priority_queue <int,vector<int>,greater<int> > q;
    for (int i=1;i<=n;i++)
    {
        int x,k,h;
        cin>>x;
        cin>>k;
        for (int i=1;i<=k;i++)
        {
            cin>>h;
            q.push(max(0,h-res));
        }
        res+=x;
    }
    for (int i=1;i<=m;i++)
    {
        int x=q.top();
        q.pop();
        if (i==m) res+=x;
        if (q.empty()==1) break;
    }
    cout<<res;
    return 0;
}
