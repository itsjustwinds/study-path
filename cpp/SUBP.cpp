#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
char s[maxn];
int n,f[maxn][maxn],res;
bool check(int i,int j)
{
        int sum=0;
        int minn=1e9;
        for (int k=i;k<=j;++k)
        {
                if (s[k]=='(') sum++;
                else sum--;
                minn=min(minn,sum);
        }
        return (sum==0&&minn>=0);
}
int main()
{
        freopen("SUBP.inp","r",stdin);
        freopen("SUBP.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;j+=2)
        if (check(i,j))
        {
                res=max(res,j-i+1);
        }
        cout<<res;
        return 0;
}
