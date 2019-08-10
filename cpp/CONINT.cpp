#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int f[2*maxn];
struct data
{
        int a,b;
};
data a[maxn];
int n,res;
bool cmp (data a,data b)
{
        return a.a<b.a;
}
int main()
{
        freopen("CONINT.inp","r",stdin);
        freopen("CONINT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].a>>a[i].b;
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                f[a[i].b+maxn]=max(f[a[i].b+maxn],f[a[i].a+maxn]+1);
                res=max(res,f[a[i].b+maxn]);
        }
        cout<<res;
        return 0;
}
