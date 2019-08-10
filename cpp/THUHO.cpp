#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,now,res,m;
int main()
{
        freopen("THUHO.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        now=a[1]-min(a[1],m);
        res+=min(a[1],m);
        for (int i=2;i<=n+1;++i)
        {
                int tmp=m;
                if (now)
                {
                        int k=min(now,m);
                        res+=k;
                        tmp-=k;
                        now-=k;
                }
                now=a[i];
                int k=min(now,tmp);
                res+=k;
                now-=k;
        }
        cout<<res;
}
