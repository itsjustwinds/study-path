#include<bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
char s[maxn];
int n;
ll res,dem;
int main()
{
        freopen("TREEWALK.inp","r",stdin);
        freopen("TREEWALK.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        dem=1;
        res=1;
        for (int i=1;i<=n;++i)
        {
                if (s[i]=='L')
                {
                        res=(res*2)%mod;
                        continue;
                }
                if (s[i]=='R')
                {
                        res=(res*2)%mod;
                        res=(res+dem)%mod;
                        continue;
                }
                if (s[i]=='P') continue;
                res=((res*5)%mod+dem)%mod;
                dem=(dem*3)%mod;
        }
        cout<<res;
        return 0;
}
