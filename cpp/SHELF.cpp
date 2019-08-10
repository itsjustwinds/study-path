#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,a[maxn];
ll bit[maxn],sum;
void update(int u,int val)
{
        while(u<maxn)
        {
                bit[u]+=val;
                u+=u&(-u);
        }
}
ll get(int u)
{
        ll res=0;
        while(u)
        {
                res+=bit[u];
                u-=u&(-u);
        }
        return res;
}
int main()
{
        freopen("SHELF.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                update(i,a[i]);
                sum+=a[i];
        }
        int test;
        cin>>test;
        while(test--)
        {
                int x;
                cin>>x;
                ll tmp1=get(x-1);
                ll tmp2=sum-get(x);
                cout<<min(tmp1,tmp2)<<" ";
                update(x,1);
        }
        return 0;
}
