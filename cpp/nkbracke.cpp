#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000000
using namespace std;
int n,m,a[maxn];
char s[maxn];
struct data
{
    int val,lazy;
};
data st[5*maxn];
void down(int id)
{
    st[id*2].lazy+=st[id].lazy;
    st[id*2+1].lazy+=st[id].lazy;
    st[id*2].val+=st[id].lazy;
    st[id*2+1].val+=st[id].lazy;
    st[id].lazy=0;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].val=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id].val=min(st[id*2].val,st[id*2+1].val);
}
void update(int id,int l,int r,int i,int j,int val)
{
    if (l>j||r<i) return;
    if (l>=i&&r<=j)
    {
        st[id].val+=val;
        st[id].lazy+=val;
        return;
    }
    down(id);
    int m=(l+r)>>1;
    update(id*2,l,m,i,j,val);
    update(id*2+1,m+1,r,i,j,val);
    st[id].val=min(st[id*2].val,st[id*2+1].val);
}
int get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i) return oo;
    if (l>=i&&r<=j)
    {
        return st[id].val;
    }
    down(id);
    int m=(l+r)>>1;
    return min(get(id*2,l,m,i,j),get(id*2+1,m+1,r,i,j));
}
int main()
{
    freopen("NKBRACKE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>test;
    cin>>(s+1);
    for (int i=1; i<=n; i++)
        if (s[i]=='(')
        {
            a[i]=a[i-1]+1;
        }
        else a[i]=a[i-1]-1;
    build(1,0,n);
    while(test--)
    {
        int x;
        cin>>x;
        if (x==0)
        {
            int i;
            char c;
            cin>>i>>c;
            if (c!=s[i])
            {
                if (c=='(') update(1,0,n,i,n,2);
                else update(1,0,n,i,n,-2);
            }
            s[i]=c;
        }
        if (x==1)
        {
            int u,v;
            cin>>u>>v;
            if (u>v) swap(u,v);
            if (s[u]=='(')
            {
                int tmp1=get(1,0,n,u,v);
                int tmp2=get(1,0,n,u,u);
                if (tmp1==tmp2-1&&tmp1==get(1,0,n,v,v)) cout<<1;
                else cout<<0;
            }
            else cout<<0;
        }
    }
    return 0;
}
