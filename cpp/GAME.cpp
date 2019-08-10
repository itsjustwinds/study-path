#include<bits/stdc++.h>
#define maxn 105
#define ll long long
#define oo 100000000000000000
using namespace std;
ll f[maxn][maxn][maxn][maxn];
int n,nA,nB,nC,zC,zA,zB,a[maxn],c[maxn],b[maxn],dd[maxn][maxn][maxn][maxn];
ll tinh(int i,int j,int k,int x)
{
        if (i<0||j<0||k<0||x<0) return -oo;
        if (i+x<0)
        {
                dd[i][j][k][x]=1;
                f[i][j][k][x]=-oo;
                return f[i][j][k][x];
        }
        if (dd[i][j][k][x]) return f[i][j][k][x];
        if (x>zA||i+x-j<0||i+x-j>zB||i+x-k<0||i+x-k>zC)
        {
                dd[i][j][k][x]=1;
                f[i][j][k][x]=-oo;
                return f[i][j][k][x];
        }
        dd[i][j][k][x]=1;
        if (i==0&&j==0&&k==0&&x==0) return 0;
        f[i][j][k][x]=tinh(i-1,j-1,k-1,x)+1ll*a[i]*b[j]*c[k];//X Y Z
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i-1,j,k,x));// X
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i,j-1,k,x-1));// Y
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i,j,k-1,x-1));// Z
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i-1,j-1,k,x));//X Y
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i-1,j,k-1,x));//x Z
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i,j-1,k-1,x-1));//Y Z
        f[i][j][k][x]=max(f[i][j][k][x],tinh(i,j,k,x-1));//
        return f[i][j][k][x];
}
int main()
{
        freopen("GAME.inp","r",stdin);
        //freopen("GAME.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
                int x;
                cin>>x;
                if (x!=0) a[++nA]=x;
                else ++zA;
        }
        for (int i=1; i<=n; ++i)
        {
                int x;
                cin>>x;
                if (x!=0) b[++nB]=x;
                else ++zB;
        }
        for (int i=1; i<=n; ++i)
        {
                int x;
                cin>>x;
                if (x!=0) c[++nC]=x;
                else ++zC;
        }
        cout<<tinh(nA,nB,nC,zA);
        return 0;
}
