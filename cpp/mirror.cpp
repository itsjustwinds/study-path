#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int n;
long long res;
char s[maxn][maxn];
void try1(int i,int j)
{
    if(s[i][j]!='.') return;
    if (s[i-1][j]=='#') res+=9;
    if (s[i][j+1]=='#') res+=9;
    if (s[i+1][j]=='#') res+=9;
    if (s[i][j-1]=='#') res+=9;
    s[i][j]='*';
    try1(i-1,j);
    try1(i,j+1);
    try1(i+1,j);
    try1(i,j-1);
}
int main()
{
    freopen("mirror.inp","r",stdin);
    freopen("mirror.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            cin>>s[i][j];
    for (int i=0;i<=n+1;i++)
    {
        s[0][i]='#';
        s[n+1][i]='#';
        s[i][0]='#';
        s[i][n+1]='#';
    }
    try1(1,1);
    cout<<res-36;
    return 0;
}
