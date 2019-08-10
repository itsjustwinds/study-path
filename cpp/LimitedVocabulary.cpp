#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
char s[maxn];
int n,k,dd[maxn],res;
int main()
{
    freopen("LimitedVocabulary.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>(s+1);
        int cnt=0;
        for (int j=0;j<=26;j++)
            dd[j]=0;
        int m=strlen(s+1);
        for (int j=1;j<=m;j++)
            if (!dd[s[j]-'a'])
        {
            dd[s[j]-'a']=1;
            cnt++;
        }
        if (cnt<=k) res=max(res,m);
    }
    if (res>0)cout<<res;
    else cout<<-1;
    return 0;
}
