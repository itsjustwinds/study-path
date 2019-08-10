#include<bits/stdc++.h>
#define maxn 100005
#define oo 1000000000000LL
#define ll long long
using namespace std;
int base[10]= {0,1,2,4,8,5,0,9,10};
ll f[maxn][20],n,a[10][maxn],res,maxx;
int get(int pos,int n)
{
    return (n >>(pos-1))&1;
}
int main()
{
    freopen("qbselect.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    maxx=-oo;
    for (int i=1; i<=4; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            maxx=max(maxx,a[i][j]);
        }
    if (maxx<0)
    {
        cout<<maxx;
        return 0;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=8; j++)
            f[i][base[j]]=-oo;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=8; j++)
        {
            int tmp=0;
            for (int pos=1; pos<=4; pos++)
            {
                if (get(pos,base[j])==0) continue;
                tmp+=a[pos][i];
            }
            for (int k=1; k<=8; k++)
            {
                int d=base[j]&base[k];
                if (d!=0) continue;
                f[i][base[j]]=max(f[i][base[j]],f[i-1][base[k]]+tmp);
            }
            res=max(res,f[i][base[j]]);
        }
    cout<<res;
    return 0;
}
