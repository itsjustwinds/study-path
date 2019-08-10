#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
struct data
{
    int lazy,val,res;
};
typedef pair<int,int> II;
data st[5*maxn],dmcd;
vector<int> e[maxn];
int n,cnt,num[maxn],pos[maxn],d[maxn],dd[maxn],last[maxn];
void build(int id,int l,int r)
{
    if (l==r)
    {
        st[id].val=d[pos[l]];
        st[id].res=1;
        return;
    }
    build(id*2,l,(l+r)/2);
    build(id*2+1,(l+r)/2+1,r);
    st[id].val=min(st[id*2].val,st[id*2+1].val);
    st[id].res=st[id*2].res+st[id*2+1].res;
}
void dfs(int u)
{
    if (dd[u]) return;
    cnt++;
    int tmp=cnt;
    dd[u]=1;
    num[u]=cnt;
    pos[cnt]=u;
    for (int i=0; i<(int)e[u].size(); i++)
    {
        int v=e[u][i];
        dfs(v);
    }
    last[u]=cnt;
}
void down(int id)
{
    int tmp=st[id].lazy;
    st[id*2].lazy+=tmp;
    st[id*2+1].lazy+=tmp;
    st[id*2].val-=tmp;
    st[id*2+1].val-=tmp;
    st[id].lazy=0;
}
data get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i) return dmcd;
    if (l==r)
    {
        if (st[id].val>0) return st[id];
        st[id]=dmcd;
        return dmcd;
    }
    down(id);
    if (l>=i&&r<=j)
    {
        if (st[id].val>0) return st[id];
        int m=(l+r)/2;
        data tmp1=get(id*2,l,m,i,j);
        data tmp2=get(id*2+1,m+1,r,i,j);
        st[id].val=min(st[id*2].val,st[id*2+1].val);
        st[id].res=st[id*2].res+st[id*2+1].res;
        return st[id];
    }
    int m=(l+r)/2;
    data tmp1=get(id*2,l,m,i,j);
    data tmp2=get(id*2+1,m+1,r,i,j);
    data tmp3;
    tmp3.lazy=0;
    tmp3.res=tmp1.res+tmp2.res;
    tmp3.val=min(tmp1.val,tmp2.val);
    st[id].val=min(st[id*2].val,st[id*2+1].val);
    st[id].res=st[id*2].res+st[id*2+1].res;
    return tmp3;
}
void update(int id,int l,int r,int i,int j,int x)
{
    if (l>j||r<i) return;
    if (l>=i&&r<=j)
    {
        st[id].lazy+=x;
        st[id].val-=x;
        return;
    }
    down(id);
    int m=(l+r)/2;
    update(id*2,l,m,i,j,x);
    update(id*2+1,m+1,r,i,j,x);
    st[id].val=min(st[id*2].val,st[id*2+1].val);
}
int main()
{
    freopen("MLCHEF.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    dmcd.val=1000000000;
    for (int i=1; i<=n; i++)
    {
        int x,c;
        cin>>x>>c;
        e[c].push_back(i);
        d[i]=x;
    }
    cnt=-1;
    dfs(0);
    build(1,1,n);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int k;
        cin>>k;
        if (k==2)
        {
            int a;
            cin>>a;
            data res=get(1,1,n,num[a]+1,last[a]);
            cout<<res.res<<"\n";
        }
        else
        {
            int a,x;
            cin>>a>>x;;
            update(1,1,n,num[a]+1,last[a],x);
        }
    }
    return 0;
}
