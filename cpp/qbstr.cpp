#include <bits/stdc++.h>
using namespace std;
char s1[1001],s2[1001];
int f[10000][10000];
main()
{
    //freopen("qbstr.inp","r",stdin);
    //freopen("qbstr.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s1+1);
    cin>>(s2+1);
    int leng1=strlen(s1+1);
    int leng2=strlen(s2+1);
    for (int i=1; i<=leng1; i++)
        for (int j=1; j<=leng2;j++)
            if (s1[i]==s2[j])
                f[i][j]=f[i-1][j-1]+1;
            else
                f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout<<f[leng1][leng2];
    return 0;
}
