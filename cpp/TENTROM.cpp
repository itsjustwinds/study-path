#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,a[maxn],b[maxn];
ll bit[maxn];
ll get(int u)
{
        ll res=0;
        while(u<maxn)
        {
                res=max(res,bit[u]);
                u+=u&(-u);
        }
        return res;
}
void update(int u,ll val)
{
        while(u)
        {
                bit[u]=max(bit[u],val);
                u-=u&(-u);
        }
}
int main()
{
        freopen("TENTROM.inp","r",stdin);
        freopen("TENTROM.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i]>>b[i];
        for (int i=1;i<=n;++i)
        {
               ll tmp=get(a[i]+1)+b[i];
               update(a[i],tmp);
        }
        cout<<get(1);
        return 0;
}

