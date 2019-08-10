#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn][50];
int n,m,test,top[50];
int main()
{
        freopen("KAMEN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                cin>>s[i][j];
        cin>>test;
        for (int j=1;j<=m;++j)
        {
                int ok=0;
                for (int i=1;i<=n;++i)
                if (s[i][j]=='X')
                {
                        top[j]=i;
                        ok=1;
                        break;
                }
                if (!ok) top[j]=n+1;
        }
        while(test--)
        {
                int k;
                cin>>k;
                int tmp=top[k];
                if (tmp==n+1||s[tmp][k]=='X')
                {
                        s[tmp+1][k]='O';
                        top[k]++;
                        continue;
                }
                if (s[tmp][k]=='O')
        }
}
