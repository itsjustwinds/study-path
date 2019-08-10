#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
int n,a[maxn],k,d,val[maxn][5],q[maxn];
int f[35][105][105][105],res;
int main()
{
    freopen("stock.inp","r",stdin);
    //freopen("stock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>d;
    for (int i=1; i<=n; i++)
        cin>>q[i];
    res=k;
    for (int i=1; i<=d; i++)
        for (int j=1; j<=n; j++)
            cin>>val[i][j];
    for (int h=1; h<=d; h++)
        for (int i=0; i<=q[1]; i++)
            for (int j=0; j<=q[2]; j++)
                for (int k=0; k<=q[3]; k++)
                    f[h][i][j][k]=-1000000000;
    f[0][0][0][0]=k;
    for (int i=0; i<=q[1]; i++)
        for (int j=0; j<=q[2]; j++)
            for (int k=0; k<=q[3]; k++)
                f[1][i][j][k]=max(f[1][i][j][k],f[0][0][0][0]-i*val[1][1]-j*val[1][2]-k*val[1][3]-i-j-k);
    for (int day=1; day<d; day++)
        for (int i=0; i<=q[1]; i++)
            for (int j=0; j<=q[2]; j++)
                for (int k=0; k<=q[3]; k++)
                    for (int x=0; x<=q[1]; x++)
                        for (int y=0; y<=q[2]; y++)
                            for (int z=0; z<=q[3]; z++)
                            {
                                f[day+1][x][y][z]=max(f[day+1][x][y][z],f[day][i][j][k]+(i-x)*val[day+1][1]+(j-y)*val[day+1][2]+(k-z)*val[day+1][3]-abs(i-x)-abs(j-y)-abs(k-z));
                                res=max(res,f[day+1][x][y][z]);
                            }
    cout<<res;
}
