#include<bits/stdc++.h>
#define maxn 200005
#define fs first
#define sc second
using namespace std;
int n,now,res,ans[maxn];
typedef pair<int,int> II;
II a[maxn];
int b[maxn],st[4*maxn];
struct query
{
    int l,r,k;
};
typedef pair<query,int> III;
III q[maxn];
bool cmp(III a,III b)
{
    return a.fs.k<b.fs.k;
}
void build(int id,int l,int r)
{
    if (l==r)
    {
        st[id]=1;
        return;
    }
    build(id*2,l,(l+r)/2);
    build(id*2+1,(l+r)/2+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r,int i)
{
    if (l>i||r<i) return;
    if (l==r)
    {
        st[id]=0;
        return;
    }
    update(id*2,l,(l+r)/2,i);
    update(id*2+1,(l+r)/2+1,r,i);
    st[id]=st[id*2]+st[id*2+1];
}
void get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i)
        return;
    if (l>=i&&r<=j)
    {
        res+=st[id];
        return;
    }
    get(id*2,l,(l+r)/2,i,j);
    get(id*2+1,(l+r)/2+1,r,i,j);
}
int main()
{
    freopen("kquery.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fs;
        a[i].sc=i;
    }
    int test;
    cin>>test;
    for (int i=1;i<=test;i++)
    {
        q[i].sc=i;
        cin>>q[i].fs.l>>q[i].fs.r>>q[i].fs.k;
    }
    sort(q+1,q+test+1,cmp);
    sort(a+1,a+n+1);
    build(1,1,n);
    for (int k=1;k<=test;k++)
    {
        int tr=now;
        for (int i=tr+1;i<=n;i++)
            if (a[i].fs<=q[k].fs.k) now=i;
        else break;
        res=0;
        for (int i=tr+1;i<=now;i++)
            update(1,1,n,a[i].sc);
        get(1,1,n,q[k].fs.l,q[k].fs.r);
        ans[q[k].sc]=res;
    }
    for (int i=1;i<=test;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
