#include<bits/stdc++.h>
#define maxn 105
using namespace std;
char a[maxn],b[maxn],s[maxn];
int n,m,k;
int f[maxn][maxn][maxn],X[maxn][maxn][maxn],nex[maxn][maxn];
struct data
{
    int x,y,k;
};
int res;
vector<char > ans;
data trc[maxn][maxn][maxn],T;
void init()
{
    for (int i=0; i<k; ++i)
        for (int c=0; c<='Z'-'A'; ++c)
        {
            if (s[i+1]-'A'==c)
            {
                nex[i][c]=i+1;
                continue;
            }
            nex[i][c]=0;
            for (int nlen=i; nlen>=1; --nlen)
            {
                if (c!=s[nlen]-'A') continue;
                int I=nlen-1,J=i;
                while(I>0&&s[I]==s[J])
                {
                    --I;
                    --J;
                }
                if (I==0)
                {
                    nex[i][c]=nlen;
                    break;
                }
            }
        }
}
int main()
{
    freopen("346B.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(a+1);
    cin>>(b+1);
    cin>>(s+1);
    n=strlen(a+1);
    m=strlen(b+1);
    k=strlen(s+1);
    init();
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            for (int h=0; h<k; ++h)
            {
                int x=max(f[i-1][j][h],f[i][j-1][h]);
                if (x>f[i][j][h])
                {
                    if (f[i-1][j][h]>f[i][j-1][h])
                    {
                        f[i][j][h]=f[i-1][j][h];
                        trc[i][j][h]= trc[i-1][j][h];
                    }
                    else
                    {
                        f[i][j][h]=f[i][j-1][h];
                        trc[i][j][h]= trc[i][j-1][h];
                    }
                }
                if (a[i]==b[j])
                {
                    int c=nex[h][a[i]-'A'];
                    if (h>0&&f[i-1][j-1][h]==0) continue;
                    if (f[i][j][c]<f[i-1][j-1][h]+1)
                    {
                        f[i][j][c]=f[i-1][j-1][h]+1;
                        trc[i][j][c]= {i-1,j-1,h};
                        X[i][j][c]=h;
                    }
                    if (f[i][j][c]>res&&c<k)
                    {
                        res=f[i][j][c];
                        T= {i,j,c};
                    }
                }
            }

    if (res==0)
    {
        cout<<0;
        return 0;
    }
    for (int i=0; i<k; ++i)
        if (f[n][m][k]>=res)
        {
            T= {n,m,k};
        }
    int i=T.x,j=T.y,h=T.k;
        ans.push_back(a[i]);
        T=trc[i][j][h];
        i=T.x;
        j=T.y;
        h=T.k;
        res--;
    while(res)
    {
        ans.push_back(a[i]);
        int x=X[i][j][h];
        T=trc[i][j][h];
        i=T.x;
        j=T.y;
        h=T.k;
        --res;
    }
    for (int i=ans.size()-1; i>=0; --i)
        cout<<ans[i];
}
