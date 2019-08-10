#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
char s[maxn];
ll res[maxn],maxx,ans[maxn];
int n;
int main()
{
        freopen("VOSSEVEN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        ll dem=0;
        for (int i=1;i<=n;i++)
        {
                if (s[i]=='7')
                {
                        ++res[++dem];
                        maxx=max(maxx,dem);
                }
                else dem=0;
        }
        ll sum=0;
        for (int i=maxx;i>=1;i--)
        {
                sum+=res[i];
                ans[i]=sum;
        }
        for (int i=1;i<=maxx;i++)
        {
                if (ans[i]==0) continue;
                cout<<i<<" "<<ans[i]<<"\n";
        }
        return 0;
}
