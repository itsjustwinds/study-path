#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
#define oo 1000000000000000LL
using namespace std;
struct data
{
    ll left,sum,ans,right;
};
ll a[maxn],n;
data st[4*maxn],zero;
void build(int id,int l,int r)
{
    if (l==r)
    {
            st[id].left=a[l];
            st[id].right=a[l];
            st[id].sum=a[l];
            st[id].ans=a[l];
        return;
    }
    build(id*2,l,(l+r)/2);
    build(id*2+1,(l+r)/2+1,r);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
    st[id].left=max(st[id*2].left,st[id*2].sum+st[id*2+1].left);
    st[id].right=max(st[id*2+1].right,st[id*2+1].sum+st[id*2].right);
    st[id].ans=max(st[id*2].right+st[id*2+1].left,max(st[id*2].ans,st[id*2+1].ans));
}
data get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i)
        return zero;
    if (l>=i&&r<=j)
    {
        return st[id];
    }
    data ans;
    data left=get(id*2,l,(l+r)/2,i,j);
    data right=get(id*2+1,(l+r)/2+1,r,i,j);
    ans.sum=left.sum+right.sum;
    ans.left=max(left.left,left.sum+right.left);
    ans.right=max(right.right,right.sum+left.right);
    ans.ans=max(left.right+right.left,max(left.ans,right.ans));
    return ans;
}
int main()
{
    freopen("gss.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    zero.left=-oo;
    zero.right=-oo;
    zero.sum=0;
    zero.ans=-oo;
    build(1,1,n);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int x,y;
        cin>>x>>y;
        data res=get(1,1,n,x,y);
        cout<<res.ans<<"\n";
    }
    return 0;
}
