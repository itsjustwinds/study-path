#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,b[maxn];
long long res;
int main()
{
        freopen("INSUL.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                res+=a[i];
        }
        sort(a+1,a+n+1);
        int l=1,r=n;
        int now=0;
        while(l<r)
        {
                b[++now]=a[l];
                ++l;
                b[++now]=a[r];
                --r;
        }
        if (l==r) b[++now]=a[l];
        for (int i=1;i<n;++i)
                res+=max(0,b[i+1]-b[i]);
        cout<<res;
}
