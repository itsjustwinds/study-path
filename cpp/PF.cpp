#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
char s[maxn];
int n,Z[maxn];
int main()
{
        freopen("PF.inp","r",stdin);
        freopen("PF.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=2;i<=n;++i)
        {
                int tmp=Z[i-1];
                if (s[tmp+1]==s[i])
                {
                        Z[i]=Z[i-1]+1;
                }
                else
                {
                        Z[i]=0;
                }
        }
        for (int i=1;i<=n;++i)
                cout<<Z[i]<<" ";
}
