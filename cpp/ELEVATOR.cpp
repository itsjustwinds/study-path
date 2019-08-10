#include<bits/stdc++.h>
#define maxn 40005
using namespace std;
int f[maxn],n;
struct data
{
        int a,h,c;
};
data a[maxn];
bool cmp(data a,data b)
{
        return a.h<b.h;
}
int main()
{
        freopen("ELEVATOR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        cin>>a[i].a>>a[i].h>>a[i].c;
        f[0]=1;
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                for (int D=1;D<=a[i].c;++D)
                for (int j=a[i].h-a[i].a;j>=0;--j)
                if (f[j]) f[j+a[i].a]=1;
        }
        for (int i=maxn-1;i>=0;--i)
        if (f[i])
        {
                cout<<i;
                return 0;
        }
}
