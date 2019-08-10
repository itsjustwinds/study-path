#include<bits/stdc++.h>
#define ll long long
#define maxn 505
using namespace std;
ll den[maxn][maxn],trang[maxn][maxn],n,a[maxn][maxn];
int main()
{
    //freopen("2008b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
    {
        den[i][j]=den[i-1][j]+den[i][j-1]-den[i-1][j-1];
        trang[i][j]=trang[i-1][j]+trang[i][j-1]-trang[i-1][j-1];
        if ((i+j)%2==0) trang[i][j]+=a[i][j];
        else den[i][j]+=a[i][j];
    }
    int test;
    cin>>test;
    while(test)
    {
        test--;
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll tmpt=trang[x2][y2]-trang[x1-1][y2]-trang[x2][y1-1]+trang[x1-1][y1-1];
        ll tmpd=den[x2][y2]-den[x1-1][y2]-den[x2][y1-1]+den[x1-1][y1-1];
        cout<<abs(tmpt-tmpd)<<"\n";
    }
}
