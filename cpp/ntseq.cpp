#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100005
using namespace std;
int a[maxn],n,ac[maxn];
struct data
{
    int val,cnt;
};
data bit[maxn];
data get(int u)
{
    data res;
    res.val=0,res.cnt=1;
    while(u)
    {
        if (bit[u].val>res.val) res=bit[u];
        else if (bit[u].val==res.val) res.cnt=(res.cnt+bit[u].cnt)%mod;
        u-=u&(-u);
    }
    return res;
}
void update(int u,int val,int cnt)
{
    while(u<=maxn)
    {
        if (bit[u].val<val)
        {
            bit[u].val=val;
            bit[u].cnt=cnt;
        }
        else if (val==bit[u].val) bit[u].cnt=(bit[u].cnt+cnt)%mod;
        u+=u&(-u);
    }
}
int main()
{
    freopen("ntseq.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        ac[i]=a[i];
    sort(ac+1,ac+n+1);
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;
    for (int i=1;i<=n;i++)
    {
        data tmp=get(a[i]-1);
        if (!tmp.cnt) tmp.cnt++;
        update(a[i],tmp.val+1,tmp.cnt);
    }
    data res=get(n);
    cout<<res.cnt;
    return 0;
}
