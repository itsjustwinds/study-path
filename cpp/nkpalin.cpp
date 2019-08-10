#include <bits/stdc++.h>
using namespace std;
char s1[2001],s2[2001];
int f[2001][2001],trace1[2001][2001],trace2[2001][2001];
int main()
{
    freopen("nkpalin.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>(s1+1);
    int n=strlen(s1+1);
    for (int i=1; i<=n; i++)
        s2[i]=s1[n-i+1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (s1[i]==s2[j])
            {
                f[i][j]=f[i-1][j-1]+1;
                trace1[i][j]=i;
                trace2[i][j]=j;
            }
            else
            {
                if (f[i-1][j]>f[i][j-1])
                {
                    f[i][j]=f[i-1][j];
                    trace1[i][j]=trace1[i-1][j];
                    trace2[i][j]=trace2[i-1][j];
                }
                else
                {
                    f[i][j]=f[i][j-1];
                    trace1[i][j]=trace1[i][j-1];
                    trace2[i][j]=trace2[i][j-1];
                }
            }
        }
    int x=trace1[n][n],y=trace2[n][n];
    for (int i=1;i<=f[n][n];i++)
    {
        cout<<s1[x];
        int tmp=trace1[x-1][y-1];
        y=trace2[x-1][y-1];
        x=tmp;
    }
    return 0;
}
