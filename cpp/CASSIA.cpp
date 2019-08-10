#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,a[maxn];
deque<int > d;
int res;
int main()
{
        freopen("CASSIA.inp","r",stdin);
        //freopen("CASSIA.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1;i<=n;++i)
        {
                while(d.size()>0&&a[i]-a[d.front()]+1>n) d.pop_front();
                d.push_back(i);
                res=max(res,(int)d.size());
        }
        cout<<n-res;
        return 0;
}
