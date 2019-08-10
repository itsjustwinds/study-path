#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int n,m,q;
struct data
{
        int val,lazy;
};
data st[4*maxn];
void down(int id)
{
        int m=st[id].lazy;
        st[id*2].val+=m;
        st[id*2].lazy+=m;
        st[id*2+1].val+=m;
        st[id*2+1].lazy+=m;
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
        int m=(l+r)>>1;
        down(id);
        update(id*2,l,m,i,j,val);
        update(id*2+1,m+1,r,i,j,val);
        st[id].val=max(st[id*2].val,st[id*2+1].val);
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j) return st[id].val;
        int m=(l+r)>>1;
        down(id);
        return max(get(id*2,l,m,i,j),get(id*2+1,m+1,r,i,j));
}
int main()
{
        freopen("QMAX.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=m;++i)
        {
                int u,v,k;
                cin>>u>>v>>k;
                update(1,1,n,u,v,k);
        }
        cin>>q;
        while(q--)
        {
                int u,v;
                cin>>u>>v;
                cout<<get(1,1,n,u,v)<<"\n";
        }
        return 0;
}
