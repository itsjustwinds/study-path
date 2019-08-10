#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll a[maxn],res;
struct data
{
    int lazy,dem;
    ll sum;
};
data st[8*maxn];
int n,m;
void build(int id,int l,int r)
{
    st[id].lazy=0;
    st[id].dem=0;
    if (l==r)
    {
        st[id].sum=a[l];
        return;
    }
    build(id*2,l,(l+r)>>1);
    build(id*2+1,((l+r)>>1)+1,r);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
}
void load(int id)
{
    st[id*2].dem+=st[id].lazy;
    st[id*2].lazy+=st[id].lazy;
    st[id*2+1].dem+=st[id].lazy;
    st[id*2+1].lazy+=st[id].lazy;
    st[id].lazy=0;
}
void update(int id,int l,int r,int i,int j)
{
    if (l>j||r<i) return;
    if (l>=i&&r<=j)
    {
        st[id].lazy++;
        st[id].dem++;
        return;
    }
    load(id);
    update(id*2,l,(l+r)>>1,i,j);
    update(id*2+1,((l+r)>>1)+1,r,i,j);
}
void get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i) return;
    if (l>=i&&r<=j)
    {
        if (st[id].dem-st[id].lazy>=8)
        {
            res+=st[id].sum;
            return;
        }
        if (l==r)
        {
            for (int i=1; i<=st[id].lazy; i++)
                st[id].sum=sqrt(st[id].sum);
            st[id].lazy=0;
            res+=st[id].sum;
            return;
        }
        load(id);
        get(id*2,l,(l+r)>>1,i,j);
        get(id*2+1,((l+r)>>1)+1,r,i,j);
        st[id].sum=st[id*2].sum+st[id*2+1].sum;
    }
    else
    {
        load(id);
        get(id*2,l,(l+r)>>1,i,j);
        get(id*2+1,((l+r)>>1)+1,r,i,j);
        st[id].sum=st[id*2].sum+st[id*2+1].sum;
    }
}
int main()
{
    freopen("gss4.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dem=0;
    while(cin>>n)
    {
        dem++;
        cout<<"Case #"<<dem<<":\n";
        for (int i=1; i<=n; i++)
            cin>>a[i];
        build(1,1,n);
        cin>>m;
        while(m--)
        {
            int x,l,r;
            cin>>x>>l>>r;
            if (l>r) swap(l,r);
            if (x==0)
            {
                update(1,1,n,l,r);
            }
            else
            {
                res=0;
                get(1,1,n,l,r);
                cout<<res<<"\n";
            }
        }
        cout<<"\n";
    }
    return 0;
}
