#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][maxn],start[maxn];
char s[maxn];
int res,n;
int main()
{
        freopen("NKSP.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;++i)
        {
                f[i][i]=1;
                if (s[i]==s[i+1])
                {
                        f[i][i+1]=1;
                        start[i]=i+1;
                        ++res;
                }
                else start[i]=1;
        }
        for (int len=3;len<=n;++len)
                for (int i=1;i+len-1<=n;++i)
        {
                int j=i+len-1;
                if (f[i+1][j-1]&&s[i]==s[j]) f[i][j]=1;
        }
        for (int i=1;i<=n;++i)
                f[i][i]=0;
        for (int len=3;len<=n;++len)
        {
                for (int i=1;i<=n-len+1;++i)
                {
                        int j=i+len-1;
                        if (f[i][j])
                        {
                                ++res;
                                continue;
                        }
                        for (int k=i+1;k<j;++k)
                        if (f[i][k]&&f[k+1][j])
                        {
                                ++res;
                                f[i][j]=1;
                                break;
                        }
                }
        }
        cout<<res;
        return 0;
}
