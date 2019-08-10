#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
#define oo 1000000000000000LL
using namespace std;
ll a[maxn],f[maxn],n,t[maxn],dd[maxn],tmp;
int main()
{
        freopen("HR22c.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
                cin>>t[i];
        for (int i=1;i<=n;i++)
                cin>>a[i];
        for (int i=1;i<=n;i++)
                f[i]=oo;
        for (int i=1;i<=n;i++)
        {
                tmp=0;
                for (int j=i-1;j>=0;j--)
                {
                        if (dd[t[j+1]]==i) break;
                        dd[t[j+1]]=i;
                        tmp=tmp|a[j+1];
                        f[i]=min(f[i],f[j]+tmp);
                }
        }
        cout<<f[n];
        return 0;
}
