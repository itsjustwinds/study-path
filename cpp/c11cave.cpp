#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int a[maxn],b[maxn],n,now1,now2,h,d1,d2,f[maxn];
int main()
{
    freopen("c11cave.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>h;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (i%2==1)
        {
            a[++d1]=x;
        }
        else b[++d2]=x;
    }
    sort(a+1,a+d1+1);
    sort(b+1,b+d2+1);
    now1=0;
    now2=d2;
    a[d1+1]=100000000;
    b[0]=0;
    for (int i=1;i<=h;i++)
    {
        while (i>a[now1+1]) now1++;
        while (h-i+1<=b[now2]) now2--;
        f[d1-now1+d2-now2]++;
    }
    for (int i=0;i<=n;i++)
        if (f[i]!=0)
    {
        cout<<i<<" "<<f[i];
        return 0;
    }
}
