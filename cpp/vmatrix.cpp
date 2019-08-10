#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,res;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],c1[maxn][maxn],tmp[maxn][maxn],d[maxn][maxn],tmp2[maxn][maxn];
/*matrix operator * (matrix a,matrix b)
{
    matrix dm;
    dm.n=n;
    dm.m=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=1; j++)
        {
            dm.h[i][j]=0;
            for (int k=1; k<=n; k++)
                dm.h[i][j]=(dm.h[i][j]+a.h[i][k]*b.h[k][j])%10;
        }
    return dm;
}*/
//matrix a,b,c,c1,tmp,d;
void checkaa()
{
    for (int i=1; i<=n; i++)
        if (tmp2[i][1]!=c1[i][1])
        {
            res=1;
            return;
        }
}
int main()
{
    freopen("vmatrix.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t)
    {
        t--;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            char s[1005];
            cin>>(s+1);
            for (int j=1; j<=n; j++)
                a[i][j]=s[j]-'0';
        }
        for (int i=1; i<=n; i++)
        {
            char s[1005];
            cin>>(s+1);
            for (int j=1; j<=n; j++)
                b[i][j]=s[j]-'0';
        }
        for (int i=1; i<=n; i++)
        {
            char s[1005];
            cin>>(s+1);
            for (int j=1; j<=n; j++)
                c[i][j]=s[j]-'0';
        }
        res=0;
        for (int k=1; k<=1000; k++)
        {
            srand(time(NULL));
            for (int i=1; i<=n; i++)
                d[i][1]=rand()%2+0;
            //tmp=b*d;
            for (int i=1; i<=n; i++)
                for (int j=1; j<=1; j++)
                {
                    tmp[i][j]=0;
                    for (int k=1; k<=n; k++)
                        tmp[i][j]=(tmp[i][j]+b[i][k]*d[k][j])%10;
                }
            //tmp=a*tmp;
            for (int i=1; i<=n; i++)
                for (int j=1; j<=1; j++)
                {
                    tmp2[i][j]=0;
                    for (int k=1; k<=n; k++)
                        tmp2[i][j]=(tmp2[i][j]+a[i][k]*tmp[k][j])%10;
                }
            //c1=c*d;
            for (int i=1; i<=n; i++)
                for (int j=1; j<=1; j++)
                {
                    c1[i][j]=0;
                    for (int k=1; k<=n; k++)
                        c1[i][j]=(c1[i][j]+c[i][k]*d[k][j])%10;
                }
            checkaa();
            if (res==1) break;
        }
        if (res==1) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}
