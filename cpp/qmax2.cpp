#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
    int val,lazy;
};
data st[4*maxn];
int n,m;
void down(int id)
{
    int tmp=st[id].lazy;
    st[id*2].val+=tmp;
    st[id*2].lazy+=tmp;
    st[id*2+1].val+=tmp;
    st[id*2+1].lazy+=tmp;
    st[id].lazy=0;
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
    update(id*2,l,(l+r)/2,i,j,val);
    update(id*2+1,(l+r)/2+1,r,i,j,val);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
int get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i) return 0;
    if (l>=i&&r<=j)
    {
        return st[id].val;
    }
    down(id);
    return max(get(id*2,l,(l+r)/2,i,j),get(id*2+1,(l+r)/2+1,r,i,j));
}
int main()
{
    //freopen("qmax2.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        if (!k)
        {
            int x,y,val;
            cin>>x>>y>>val;
            update(1,1,n,x,y,val);
        }
        else{
            int x,y;
            cin>>x>>y;
            int res=get(1,1,n,x,y);
            cout<<res<<"\n";
        }
    }
    return 0;
}
