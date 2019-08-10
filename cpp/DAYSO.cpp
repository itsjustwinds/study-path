#include<bits/stdc++.h>
#define maxn 505
using namespace std;
char s[maxn];
int n,a[maxn];
int main()
{
        freopen("DAYSO.inp","r",stdin);
        freopen("DAYSO.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n+1;++i)
        {
                int tmp1=0;
                int max1=0;
                int tmp2=0;
                int max2=0;
                for (int j=i-1;j>=1;--j)
                {
                        if (s[j]=='>') --tmp1;
                        if (s[j]=='<') ++tmp1;
                        max1=max(max1,tmp1);
                }
                for (int j=i;j<=n;++j)
                {
                        if (s[j]=='<') --tmp2;
                        if (s[j]=='>') ++tmp2;
                        max2=max(max2,tmp2);
                }
                a[i]=max(0,max(max1,max2))+1;
        }
        for (int i=1;i<=n+1;++i)
                cout<<a[i]<<" ";
        return 0;
}
