#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],b[maxn],f[maxn];
typedef pair<int,int > II;
vector<II > res;
int n,m,ans;
bool check(int k)
{
        vector<II> tmp;
        tmp.clear();
        for (int i=1;i<=n;++i)
                f[i]=a[i];
        int now=1;
        for (int i=1;i<=n;++i)
        {
                if (f[i]<k)
                {
                        while(now<=m&&f[i]+b[now]<k)++now;
                        f[i]+=b[now];
                        tmp.push_back(II(i,now));
                        ++now;
                }
                if (f[i]<k) return 0;
        }
        res=tmp;
        return 1;
}
int main()
{
        freopen("WALL.inp","r",stdin);
        freopen("WALL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        cin>>m;
        for (int i=1;i<=m;++i)
                cin>>b[i];
        int l=1,r=2e9;
        while(l<=r)
        {
                int m=(l+r)>>1;
                if (check(m))
                {
                        l=m+1;
                        ans=m;
                }
                else r=m-1;
        }
        cout<<ans<<" "<<res.size()<<"\n";
        for (int i=0;i<res.size();++i)
                cout<<res[i].first<<" "<<res[i].second<<"\n";
}
