#include<bits/stdc++.h>
#define maxn 1000007
#define mod 1000000007
#define ll long long
using namespace std;
char s[maxn];
int res,n,power[maxn];
int main()
{
    freopen("805e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    int n=strlen(s+1);
    power[0]=1;
    for (int i=1;i<=n;i++)
        power[i]=((ll)power[i-1]*2)%mod;
    int dem=0;
    for (int i=1;i<=n;i++)
    if (s[i]=='a')
    {
        dem++;
        if (s[i+1]=='b') res=((ll)res+power[dem]-1+mod)%mod;
    }
    cout<<res;
    return 0;
}
