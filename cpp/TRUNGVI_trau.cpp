#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int a[maxn],n,up[maxn],down[maxn],m,res,now;
int main()
{
        freopen("D:\\c++\\TRUNGVI.inp","r",stdin);
        freopen("D:\\c++\\TRUNGVI.ans","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
        {
                up[i]=up[i-1];
                down[i]=down[i-1];
                if (a[i]>m) up[i]++;
                if (a[i]<m) down[i]++;
                if (a[i]==m)
                {
                        now=i;
                }
        }
        for (int i=now;i<=n;++i)
                for (int j=i;j>=1;j-=2)
        {
                if (j>now) continue;
                if (up[i]-up[j-1]==down[i]-down[j-1]) ++res;
        }
        cout<<res;
}
