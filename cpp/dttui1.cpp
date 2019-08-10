#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int d1,d2,a[50],v[50],n,m;
struct data
{
        int val,w;
};
data f1[maxn],f2[maxn];
void dfs1(int i,int val,int w)
{
        if(i==n/2+1)
        {
                if (w>m) return;
                f1[++d1]={val,w};
                return;
        }
        dfs1(i+1,val,w);
        dfs1(i+1,val+v[i],w+a[i]);
}
void dfs2(int i,int val,int w)
{
        if (i>n)
        {
                if (w>m) return;
                f2[++d2]={val,w};
                return;
        }
        dfs2(i+1,val,w);
        dfs2(i+1,val+v[i],w+a[i]);
}
bool cmp(data a,data b)
{
        return a.w<b.w;
}
int findd(int l,int r,int x)
{
        int res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (f2[m].w<=x)
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        return res;
}
int main()
{
        freopen("DTTUI1.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i]>>v[i];
        dfs1(1,0,0);
        dfs2(n/2+1,0,0);
        sort(f1+1,f1+d1+1,cmp);
        sort(f2+1,f2+d2+1,cmp);
        for (int i=1;i<=d2;++i)
                f2[i].val=max(f2[i].val,f2[i-1].val);
        int res=0;
        for (int i=1;i<=d1;++i)
        {
                int t=findd(1,d2,m-f1[i].w);
                res=max(res,f1[i].val+f2[t].val);
        }
        cout<<res;
}
