#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,m,f[maxn][maxn],res1[100005],res2[100005],d1,d2;
int main()
{
    //freopen("816c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>f[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            while(1)
            {
                int minn1=10000;
                for (int k=1; k<=m; k++)
                    minn1=min(minn1,f[i][k]);
                int minn2=10000;
                for (int k=1; k<=n; k++)
                    minn2=min(minn2,f[k][j]);
                if (n>m)
                {
                    if (minn2)
                    {
                        for (int k=1; k<=n; k++)
                            f[k][j]-=1;
                        res2[++d2]=j;
                    }
                    else if (minn1)
                    {
                        for (int k=1; k<=m; k++)
                            f[i][k]-=1;
                        res1[++d1]=i;
                    }
                }
                else
                {
                    if (minn1)
                    {
                        for (int k=1; k<=m; k++)
                            f[i][k]-=1;
                        res1[++d1]=i;
                    }
                    else if (minn2)
                    {
                        for (int k=1; k<=n; k++)
                            f[k][j]-=1;
                        res2[++d2]=j;
                    }
                }
                if (minn1==minn2&&minn1==0) break;
            }
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (f[i][j]!=0)
            {
                cout<<-1;
                return 0;
            }
    cout<<d1+d2<<"\n";
    for (int i=1; i<=d1; i++)
        cout<<"row "<<res1[i]<<"\n";;
    for (int i=1; i<=d2; i++)
        cout<<"col "<<res2[i]<<"\n";
    return 0;
}
