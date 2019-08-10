#include <bits/stdc++.h>
#define maxn 50005
using namespace std;
int n,m,pos[15];
char a[maxn][15];
void swapp(int a1,int a2,int a3,int a4)
{
    char t;
    t=a[a1][a2];
    a[a1][a2]=a[a3][a4];
    a[a3][a4]=t;
    return;
}
int main()
{
    //freopen("apples.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    for (int j=1; j<=m; j++)
        pos[j]=n;
    for (int j=1; j<=m; j++)
    {
        for (int i=n; i>=1; i--)
            if (a[i][j]!='.')
            {
                if (a[i][j]=='#')
                {
                    pos[j]=i-1;
                }
                else
                {
                    swapp(i,j,pos[j],j);
                    pos[j]-=1;
                }
            }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<a[i][j];
        cout<<"\n";
    }
    return 0;
}
