#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
struct data
{
    ll a,b;
};
int n,m;
data st[4*maxn];
ll get(data T,int x)
{
    return T.a*x+T.b;
}
void update(int id,int l,int r,int i,int j,data T)
{
    if (l>j||r<i) return;
    if (l>=i&&r<=j)
    {
        if (get(T,l)>=get(st[id],l)&&get(T,r)>=get(st[id],r))
        {
            st[id]=T;
            return;
        }
        if (get(T,l)<get(st[id],l)&&get(T,r)<get(st[id],r))
            return;
    }
    int m=(l+r)>>1;
    update(id*2,l,m,i,j,T);
    update(id*2+1,m+1,r,i,j,T);
}
ll GET(int id,int l,int r,int i)
{
    if (l>i||r<i) return -1e18;
    if (l==r)
    {
        return get(st[id],l);
    }
    int m=(l+r)>>1;
    ll tmp=get(st[id],i);
    return max(tmp,max(GET(id*2,l,m,i),GET(id*2+1,m+1,r,i)));
}
int main()
{
    freopen("JEWELNB.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d",&n,&m);
    for (int i=1;i<4*maxn;++i)
        st[i].b=-1e18;
    for (int i=1;i<=m;++i)
    {
        int start,last,val,inc;
        scanf("%d%d%d%d",&start,&last,&val,&inc);
        data T={inc,1ll*val-1ll*inc*start};
        update(1,1,n,start,last,T);
    }
    for (int i=1;i<=n;++i)
    {
        ll tmp=GET(1,1,n,i);
        if (tmp==-1e18) printf("0\n");
        else printf("%lld\n",tmp);
    }
}
