#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,m,k,d,res,p;
int check(int len)
{
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        cnt+=max(0,a[i]-len)/p;
        if (max(0,(a[i]-len))%p) cnt++;
    }
    if (cnt<=d*m) return 1;
    return 0;
}
int main()
{
    freopen("BAMBOOS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d>>m>>p;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=x+y*d;
    }
    int l=1,r=1e9+7;
    while(l<=r)
    {
        int tmp=(l+r)/2;
        if (check(tmp))
        {
            res=tmp;
            r=tmp-1;
        }
        else l=tmp+1;
    }
    cout<<res;
    return 0;
}
