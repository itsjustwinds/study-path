#include<bits/stdc++.h>
#define maxn 205
using namespace std;
struct data
{
        int u,v,c;
};
data edge[maxn*maxn];
int n,k,now,dd[maxn],root[maxn];
bool cmp(data a,data b)
{
        return a.c<b.c;
}
int getroot(int u)
{
        if (root[u]==u) return u;
        root[u]=getroot(root[u]);
        return root[u];
}
bool check(int m)
{
        for (int i=1;i<=n;++i)
                root[i]=i;
        int dem=0;
        memset(dd,0,sizeof dd);
        for (int i=1;i<=now;++i)
        if (edge[i].c<m)
        {
                int u=edge[i].u;
                int v=edge[i].v;
                int ru=getroot(u);
                int rv=getroot(v);
                root[ru]=rv;
                if (i==now) return 0;
        }
        else break;
        for (int i=1;i<=n;++i)
        {
                int ru=getroot(i);
                if (!dd[ru])
                {
                        ++dem;
                        dd[ru]=1;
                }
        }
        if (dem>=k) return 1;
        return 0;
}
int main()
{
        freopen("YUGI.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
        {
                int x;
                cin>>x;
                if (i<j)
                {
                        edge[++now]={i,j,x};
                }
        }
        sort(edge+1,edge+now+1,cmp);
        int l=1,r=32768,res=0;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        res=m;
                        l=m+1;
                }
                else r=m-1;
        }
        cout<<res;
}
