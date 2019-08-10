#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int f[10][2][2][maxn][maxn],n,len[maxn],res;
char s[10][2][maxn];
int e[2][maxn][maxn];
void inint(int k)
{
    for (int i=1; i<=len[1]; i++)
        for (int j=1; j<=len[k]; j++)
        {
            if (s[1][0][i]==s[k][0][j]) f[k][0][0][i][j]=f[k][0][0][i-1][j-1]+1;
            else f[k][0][0][i][j]=0;
            e[0][k][i]=max(e[0][k][i],f[k][0][0][i][j]);
        }
    for (int i=1; i<=len[1]; i++)
        for (int j=1; j<=len[k]; j++)
        {
            if (s[1][0][i]==s[k][1][j]) f[k][0][1][i][j]=f[k][0][1][i-1][j-1]+1;
            else f[k][0][1][i][j]=0;
            e[0][k][i]=max(e[0][k][i],f[k][0][1][i][j]);
        }

    for (int i=1; i<=len[1]; i++)
        for (int j=1; j<=len[k]; j++)
        {
            if (s[1][1][i]==s[k][0][j]) f[k][1][0][i][j]=f[k][1][0][i-1][j-1]+1;
            else f[k][1][0][i][j]=0;
            e[1][k][i]=max(e[1][k][i],f[k][1][0][i][j]);
        }
    for (int i=1; i<=len[1]; i++)
        for (int j=1; j<=len[k]; j++)
        {
            if (s[1][1][i]==s[k][1][j]) f[k][1][1][i][j]=f[k][1][1][i-1][j-1]+1;
            else f[k][1][1][i][j]=0;
            e[1][k][i]=max(e[1][k][i],f[k][1][1][i][j]);
        }
}
int main()
{
    freopen("str5.inp","r",stdin);
    freopen("str5.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>(s[i][0]+1);
        len[i]=strlen(s[i][0]+1);
        for (int j=1; j<len[i]; j++)
            s[i][0][j+len[i]]=s[i][0][j];
        len[i]=len[i]*2-1;
        for (int j=1;j<=len[i];j++)
            s[i][1][j]=s[i][0][len[i]-j+1];
    }
 for (int i=2; i<=n; i++)
        inint(i);
    for (int i=1;i<=len[1];i++)
    {
        int k=10000;
        for (int j=2;j<=n;j++)
            k=min(k,max(e[0][j][i],e[1][j][i]));
        res=max(res,k);
    }
    cout<<res;
    return 0;
}
