#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int a[maxn],n,dd[maxn],m;
int main()
{
        freopen("BANHCHUNG.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        dd[0]=1;
        for (int i=1;i<=m;++i)
        {
                int x;
                cin>>x;
                for (int j=n-x;j>=0;--j)
                if (dd[j]) dd[j+x]=1;
        }
        for (int i=n;i>=0;--i)
                if (dd[i])
        {
                cout<<i;
                return 0;
        }
}
