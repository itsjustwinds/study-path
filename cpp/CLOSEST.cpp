#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
ll a[maxn],b[maxn],n,m,res,ans,c1,c2,now1,now2;
map<int,int > dd;
map<int,int > :: iterator it;
int main()
{
        //freopen("CLOSEST.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        cin>>c1>>c2;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=m;++i)
                cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        now1=1;
        now2=1;
        ans=abs(a[1]-b[1]);
        a[n+1]=1e9;
        b[m+1]=1e9;
        while(now1<=n&&now2<=m)
        {
                if (abs(a[now1+1]-b[now2])<=abs(a[now1]-b[now2]))
                        ++now1;
                else ++now2;
                if (now1<=n&&now2<=m)ans=min(ans,abs(a[now1]-b[now2]));
        }
        for (int i=1;i<=n;++i)
        {
                dd[a[i]]=dd[a[i]]+1;
        }
        for (int i=1;i<=m;++i)
        {
                res+=dd[b[i]-ans];
                res+=dd[b[i]+ans];
        }
        cout<<ans+abs(c2-c1)<<" "<<res;
        return 0;
}
