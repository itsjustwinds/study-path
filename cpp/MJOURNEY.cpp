#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll d[maxn],p[maxn],t,n,res[maxn];
struct data
{
        ll val,pos;
};
data w[maxn],cost[maxn];
bool cmp(data a,data b)
{
        return a.val>b.val;
}
int main()
{
        freopen("MJOURNEY.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>t;
        for (int i=1;i<=n;++i)
        {
                cin>>w[i].val;
                w[i].pos=i;
        }
        sort(w+1,w+n+1,cmp);
        for (int i=1;i<=n;++i)
                cin>>d[i];
        for (int i=1;i<=n;++i)
                cin>>p[i];
        for (int i=1;i<=n;++i)
        {
                cost[i].val=p[i]-t*d[i];
                cost[i].pos=i;
        }
        sort(cost+1,cost+n+1,cmp);
        for (int i=1;i<=n;++i)
                res[cost[i].pos]=w[i].pos;
        for (int i=1;i<=n;++i)
                cout<<res[i]<<" ";
        return 0;
}
