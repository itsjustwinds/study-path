#include<bits/stdc++.h>
#define maxn 300
using namespace std;
int f[maxn][maxn],res[maxn];
char s[maxn];
int n;
int main()
{
    freopen("countpl.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
    {
        f[i][i]=1;
        if (s[i]==s[i-1])f[i-1][i]=1;
    }
    for (int j=1;j<=n;j++)
        for (int i=1;i<=j;i++)
            if (s[i]==s[j]&&i+1<=j-1)
        if (f[i+1][j-1]==1) f[i][j]=1;
    for (int i=1;i<=n;i++)
        res[i]=i;
    for (int j=1;j<=n;j++)
        for (int i=0;i<j;i++)
        if (f[i+1][j]==1)
        res[j]=min(res[j],res[i]+1);
    cout<<res[n];
    return 0;
}
