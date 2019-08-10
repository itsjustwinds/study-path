#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct matrix
{
        int n,m;
        int h[10][10][4];
};
matrix a;
int n,mod,s,t,trc[10][4],id[10][10];
matrix operator * (matrix a,matrix b)
{
        matrix c;
        for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
        for (int k=1;k<=8;k++)
        {
                if (id[k][j]==0) continue;
                int x=id[k][j];
                c.h[i][j][x]=0;
                for (int t=1;t<=3;t++)
                {
                        int z=trc[k][t];
                        if (z==j) continue;
                        c.h[i][j][x]=(c.h[i][j][x]+((ll)a.h[i][k][t]*b.h[k][j][x])%mod)%mod;
                }
        }
        return c;
}
matrix power(matrix a,int n)
{
        if (n==1) return a;
        matrix tmp=power(a,n>>1);
        tmp=tmp*tmp;
        if (n&1) tmp=tmp*a;
        return tmp;
}
int main()
{
        freopen("PA06ANT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        a.h[2][1][1]=1;trc[1][1]=2;id[2][1]=1;
        a.h[4][1][2]=1;trc[1][2]=4;id[4][1]=2;
        a.h[5][1][3]=1;trc[1][3]=5;id[5][1]=3;
        a.h[1][2][1]=1;trc[2][1]=1;id[1][2]=1;
        a.h[3][2][2]=1;trc[2][2]=3;id[3][2]=2;
        a.h[6][2][3]=1;trc[2][3]=6;id[6][2]=3;
        a.h[2][3][1]=1;trc[3][1]=2;id[2][3]=1;
        a.h[4][3][2]=1;trc[3][2]=4;id[4][3]=2;
        a.h[7][3][3]=1;trc[3][3]=7;id[7][3]=3;
        a.h[1][4][1]=1;trc[4][1]=1;id[1][4]=1;
        a.h[3][4][2]=1;trc[4][2]=3;id[3][4]=2;
        a.h[8][4][3]=1;trc[4][3]=8;id[8][4]=3;
        a.h[1][5][1]=1;trc[5][1]=1;id[1][5]=1;
        a.h[6][5][2]=1;trc[5][2]=6;id[6][5]=2;
        a.h[8][5][3]=1;trc[5][3]=8;id[8][5]=3;
        a.h[2][6][1]=1;trc[6][1]=2;id[2][6]=1;
        a.h[5][6][2]=1;trc[6][2]=5;id[5][6]=2;
        a.h[7][6][3]=1;trc[6][3]=7;id[7][6]=3;
        a.h[3][7][1]=1;trc[7][1]=3;id[3][7]=1;
        a.h[6][7][2]=1;trc[7][2]=6;id[6][7]=2;
        a.h[8][7][3]=1;trc[7][3]=8;id[8][7]=3;
        a.h[4][8][1]=1;trc[8][1]=4;id[4][8]=1;
        a.h[5][8][2]=1;trc[8][2]=5;id[5][8]=2;
        a.h[7][8][3]=1;trc[8][3]=7;id[7][8]=3;
        char x;
        cin>>x;
        s=x-'A'+1;
        cin>>x;
        t=x-'A'+1;
        cin>>n>>mod;
        if (n==1)
        {
                int res=0;
                for (int i=1;i<=3;i++)
                        res=max(res,a.h[s][t][i]%mod);
                cout<<res;
                return 0;
        }
        //matrix res=power(a,n);
        matrix res=a;
        for (int i=2;i<=n;i++)
                res=res*a;
        int ans=0;
        for (int i=1; i<=3; i++)
                ans=(ans+res.h[s][t][i])%mod;
        cout<<ans;
        return 0;
}
