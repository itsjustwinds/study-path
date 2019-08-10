#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n;
long long res;
int main()
{
        freopen("GATHER.inp","r",stdin);
        freopen("GATHER.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1);
        int p=a[n/2+1];
        for (int i=1;i<=n;++i)
                res+=abs(p-a[i]);
        cout<<res;
        return 0;
}
