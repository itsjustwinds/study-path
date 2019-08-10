#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],res,k,n;
int main()
{
    freopen("793a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if (k%2==0)
    {
        int dd1=0,dd2=0;
        for (int i=1; i<=n; i++)
            if (a[i]%2==0) dd2=1;
            else dd1=1;
        if (dd1==1&&dd2==1)
        {
            cout<<-1;
            return 0;
        }
    }
    int now=a[1];
    for (int i=2; i<=n; i++)
    {
        while(a[i]!=now)
        {
            if (a[i]<now)
            {
                now-=k;
                res*=i-1;
            }
            else
            {
                a[i]-=k;
                res++;
            }
        }
    }
    cout<<res;
}
