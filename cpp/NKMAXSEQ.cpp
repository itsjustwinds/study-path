#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int a[maxn],bit[2*maxn],n,p;
struct data
{
        int val,pos;
};
bool cmp(data a,data b)
{
        return a.val<b.val;
}
data sum[2*maxn];
int findd(int l,int r,int x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (sum[m].val<x)
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        return res+1;
}
int get(int u)
{
        int res=1e9;
        while(u)
        {
                res=min(res,bit[u]);
                u-=u&(-u);
        }
        return res;
}
void update(int u,int val)
{
        while(u<2*maxn)
        {
                bit[u]=min(bit[u],val);
                u+=u&(-u);
        }
}
int main()
{
        freopen("NKMAXSEQ.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>p;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                sum[i].val=sum[i-1].val+a[i];
                sum[i].pos=i;
        }
        for (int i=n+1;i<=2*n;++i)
        {
                sum[i].val=sum[i-n].val-p;
                sum[i].pos=-1;
        }
        sort(sum+1,sum+2*n+1,cmp);
        int res=-1;
        for (int i=0;i<2*maxn;++i)
                bit[i]=1e9;
        for (int i=1;i<=2*n;++i)
        {
                if (sum[i].pos==-1) continue;
                int x=findd(1,2*n,sum[i].val-p);
                int tmp=get(x);
                res=max(res,sum[i].pos-tmp);
                x=findd(1,2*n,sum[i].val);
                update(x,sum[i].pos);
        }
        cout<<res;
        return 0;
}
