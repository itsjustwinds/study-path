#include<bits/stdc++.h>
#define maxn 800005
using namespace std;
int n;
struct data
{
    int a,b;
};
data a[maxn];
int res;
bool cmp(data a,data b)
{
    return a.a-a.b<b.a-b.b;
}
int main()
{
    freopen("ACMNB.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    n*=2;
    for (int i=1;i<=n;++i)
        cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n/2;++i)
        res+=a[i].a;
    for (int i=n/2+1;i<=n;++i)
        res+=a[i].b;
    cout<<res;
    return 0;
}
