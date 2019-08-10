#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
struct data
{
    ll a,b,id;
};
data a[maxn];
ll n;
bool cmp(data a,data b)
{
    if (a.a!=b.a) return a.a>b.a;
    return a.b>b.b;
}
int main()
{
    freopen("798d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].a;
    for (int i=1;i<=n;i++)
        cin>>a[i].b;
    for (int i=1;i<=n;i++)
        a[i].id=i;
    sort(a+1,a+n+1,cmp);
    cout<<n/2+1<<"\n";
    cout<<a[1].id<<" ";
    for (int i=2;i<=n;i+=2)
    {
        int tmp=i;
        if (tmp+1<=n&&a[tmp].b<a[tmp+1].b) tmp++;
        cout<<a[tmp].id<<" ";
    }
    return 0;
}
