#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int a[maxn],b[maxn],n,m,dd1[maxn],dd2[maxn];
int main()
{
        //freopen("872A.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                dd1[a[i]]=1;
        }
        for (int i=1;i<=m;++i)
        {
                cin>>b[i];
                dd2[b[i]]=1;
        }
        for (int i=1;i<=9;++i)
        if (dd1[i]==dd2[i]&&dd1[i]==1)
        {
                cout<<i;
                return 0;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        cout<<min(a[1],b[1])<<max(a[1],b[1]);
        return 0;
}
