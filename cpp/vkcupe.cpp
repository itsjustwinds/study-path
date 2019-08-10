#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
char s[maxn];
ll m,dmcd,n,res;
int main()
{
    freopen("vkcupe.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    cin>>m;
    n=strlen(s+1);
    dmcd=1;
    for (int i=2; i<=n; i++)
        dmcd=(dmcd*10)%m;
    ll tmp=0;
    for (int i=1; i<=n; i++)
        tmp=(tmp*10+s[i]-'0')%m;
    res=tmp;
    for (int i=1; i<=n-1; i++)
    {
        ll tmp1=(tmp-((s[i]-'0')*dmcd)%m+m)%m;
        tmp=(tmp1*10+s[i]-'0')%m;
        if (s[i+1]=='0') continue;
        res=min(res,tmp);
    }
    cout<<res;
    return 0;
}
