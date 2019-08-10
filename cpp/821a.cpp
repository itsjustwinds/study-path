#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int a[maxn][maxn],n;
int main()
{
        //freopen("821a.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; i++)
                for (int j=1; j<=n; j++)
                        cin>>a[i][j];
        for (int i=1; i<=n; i++)
                for (int j=1; j<=n; j++)
                        if (a[i][j]!=1)
                        {
                                int ok=0;
                                for (int y=1;y<=n;y++)
                                {
                                        if (y==j) continue;
                                        for (int x=1;x<=n;x++)
                                        {
                                                if (x==i) continue;
                                                if (a[i][y]+a[x][j]==a[i][j])
                                                {
                                                        ok=1;
                                                        break;
                                                }
                                        }
                                }
                                if (!ok)
                                {
                                        cout<<"no";
                                        return 0;
                                }
                        }
        cout<<"yes";
        return 0;
}
