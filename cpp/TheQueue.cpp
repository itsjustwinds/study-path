#include <bits/stdc++.h>
#define maxn 100005
#define maxx 1000000000005
using namespace std;
int n;
long long ts,tf,t,now,a[maxn],res,ss,newest;
int main()
{
    freopen("thequeue.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ts>>tf>>t;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    now=tf;
    newest=tf;
    ss=maxx;
    if (a[1]>now)
    {
        cout<<now;
        return 0;
    }
    now=a[1]+t+1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>now)
        {
            cout<<now;
            return 0;
        }
        now=now+t+1;
        if (now>tf)
        {
            if(ts-(a[1]-1)>=now-t-1) cout<<now;
            else cout<<a[1]-1;
            return 0;
        }
    }
    if (ss<ts-(a[1]-1)) cout<<a[1]-1;
    else cout<<res;
    return 0;
}

