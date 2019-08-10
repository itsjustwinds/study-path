#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
struct node
{
    int l,r,s;
};
int n,f[maxn];
char s[maxn];
node it[4*maxn],zero;
void update(int id,int l,int r)
{
    if (l==r)
    {
        if (f[l]==1)
        {
            it[id].l=1;
        }
        else it[id].r=1;
        return;
    }
    update(id*2,l,(l+r)/2);
    update(id*2+1,(l+r)/2+1,r);
    int k=min(it[id*2].l,it[id*2+1].r);
    it[id].s=it[id*2].s+it[id*2+1].s+k*2;
    it[id].l=it[id*2].l+it[id*2+1].l-k;
    it[id].r=it[id*2+1].r+it[id*2].r-k;
}
node get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i)
    return zero;
    if (l>=i&&r<=j)
    {
        return it[id];
    }
    node h,s1,s2;
    s1=get(id*2,l,(l+r)/2,i,j);
    s2=get(id*2+1,(l+r)/2+1,r,i,j);
    int k=min(s1.l,s2.r);
    h.s=s1.s+s2.s+k*2;
    h.l=s1.l+s2.l-k;
    h.r=s1.r+s2.r-k;
    return h;
}
int main()
{
    //freopen("380c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    int n=strlen(s+1);
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='(') f[i]=1;
        else f[i]=-1;
    }
    zero.s=0;
    zero.l=0;zero.r=0;
    update(1,1,n);
    int test;
    cin>>test;
    while (test)
    {
        test--;
        int x,y;
        cin>>x>>y;
        node res=get(1,1,n,x,y);
        cout<<res.s<<"\n";
    }
    return 0;
}
