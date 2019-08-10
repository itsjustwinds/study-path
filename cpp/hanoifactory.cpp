#include<bits/stdc++.h>
using namespace std;
struct k
{
    int a,b,h;
};
bool kt(k a,k b)
{
    if (a.b==b.b)
        return a.a>b.a;
    return a.b>b.b;
};
k a[100005];
int n;
long long res,sum;
int main()
{
    freopen("hanoifactory.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    cin>>a[i].a>>a[i].b>>a[i].h;
    sort(a+1,a+n+1,kt);
    stack<k> q;
    q.push(a[1]);
    res=a[1].h;sum=a[1].h;
    for (int i=2;i<=n;i++)
    {
            while (q.empty()!=1&&a[i].b<=q.top().a)
            {
                sum-=q.top().h;
                q.pop();
            }
            sum+=a[i].h;
            res=max(res,sum);
            q.push(a[i]);
    }
    cout<<res;
    return 0;
}
