#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
ll res;
struct data
{
        int x,y;
};
data a[maxn];
int n,k;
struct cmp
{
        bool operator ()(int x,int y)
        {
                return x>y;
        }
};
priority_queue<int,vector<int>,cmp > q;
bool cmp2(data a,data b)
{
        return a.x>b.x;
}
int main()
{
        freopen("POWER.inp","r",stdin);
        freopen("POWER.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                cin>>a[i].x>>a[i].y;
        sort(a+1,a+n+1,cmp2);
        for (int i=1;i<=k;++i)
        {
                q.push(a[i].y);
        }
        res=1ll*a[k].x*q.top();
        for (int i=k+1;i<=n;++i)
        {
                q.push(a[i].y);
                q.pop();
                res=max(res,1ll*a[i].x*q.top());
        }
        cout<<res;
        return 0;
}
