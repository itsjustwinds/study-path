#include<bits/stdc++.h>
#define maxn 1000005
#define fs first
#define sc second
using namespace std;
struct II
{
        int fs,sc,id;
};
int n;
II a[maxn];
int bit[maxn],f[maxn];
int res;
bool cmp(II a,II b)
{
        return a.sc<b.sc;
}
int get(int u)
{
        int kq=0;
        while(u)
        {
                kq=max(kq,bit[u]);
                u-=u&(-u);
        }
        return kq;
}
int update(int u,int k)
{
        while(u<=maxn)
        {
                bit[u]=max(bit[u],k);
                u+=u&(-u);
        }
}
int main()
{
        freopen("MEETING.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i].fs>>a[i].sc;
                a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
                int k=get(a[i].fs);
                f[i]=k+1;
                res=max(res,f[i]);
                update(a[i].sc,f[i]);
        }
        cout<<res;
}
