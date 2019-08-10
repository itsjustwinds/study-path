#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n,a[maxn],r;
long long res;
int main()
{
        freopen("WALK.inp","r",stdin);
        freopen("WALK.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>r;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        int now=0;
        for (int i=2;i<=n;++i)
        {
                while(a[i]-a[now+1]>r)++now;
                res+=now;
        }
        cout<<res;
        return 0;
}
