#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
char s[maxn],t[maxn];
int n,m,k;
int res;
void solve()
{
        for (int i=1;i<=n-m+1;++i)
        {
                int ans=0;
                for (int j=1;j<=m;++j)
                if (s[i+j-1]!=t[j]) ++ans;
                res=min(res,ans);
        }
}
int main()
{
        freopen("HAMMING.inp","r",stdin);
        freopen("HAMMING.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>k;
        cin>>(s+1);
        res=1e9;
        for (int i=1;i<n;++i)
                s[i+n]=s[i];
        n=2*n-1;
        for (int i=1;i<=k;++i)
        {
                cin>>(t+1);
                solve();
        }
        cout<<res;
}
