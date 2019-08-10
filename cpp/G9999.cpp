#include<bits/stdc++.h>
using namespace std;
int f[10][10][10][10],n,x;
int main()
{
        freopen("G9999.inp","r",stdin);
        //freopen("G9999.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        f[9][9][9][9]=1;
        for (int i=9; i>=0; --i)
        for (int j=9; j>=0; --j)
        for (int k=9; k>=0; --k)
        for (int h=9; h>=0; --h)
        {
                if (f[i][j][k][h]==1)
                {
                        for (int x=1; x<=3; ++x)
                        {
                        if (i-x>=0)f[i-x][j][k][h]=max(f[i-x][j][k][h],0);
                        if (j-x>=0)f[i][j-x][k][h]=max(f[i][j-x][k][h],0);
                        if (k-x>=0)f[i][j][k-x][h]=max(f[i][j][k-x][h],0);
                        if (h-x>=0)f[i][j][k][h-x]=max(f[i][j][k][h-x],0);
                        }
                }
                if (f[i][j][k][h]==0)
                {
                        for (int x=1; x<=3; ++x)
                        {
                                if (i-x>=0)f[i-x][j][k][h]=1;
                                if (j-x>=0)f[i][j-x][k][h]=1;
                                if (k-x>=0)f[i][j][k-x][h]=1;
                                if (h-x>=0)f[i][j][k][h-x]=1;
                        }
                }
        }
        while(n--)
        {
                cin>>x;
                int a[10];
                for (int i=1;i<=4;++i)
                {
                        a[i]=x%10;
                        x/=10;
                }
                int k=f[a[1]][a[2]][a[3]][a[4]];
                if (k==1) cout<<"N";
                else cout<<"Y";
        }
        return 0;
}
