#include<bits/stdc++.h>
#define maxn 2505
#define oo 1000001
#define fs first
#define sc second
using namespace std;
int n,a[maxn],res;
typedef pair<int,int> II;
II f[maxn][maxn];
int main()
{
    freopen("seq.inp","r",stdin);
    //freopen("seq.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n;
        for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=II(0,0);
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=2;i<=n;i++)
            for (int j=i-1;j>0;j--)
            f[j][i]=II(a[i]+a[j],2);
        for (int k=3;k<=n;k++)
        {
            for (int j=k-1;j>1;j--)
                for (int i=j-1;i>0;i--)
                if (a[k]==f[i][j].fs&&f[j][k].sc<f[i][j].sc+1)
            {
                f[j][k].sc=f[i][j].sc+1;
            }
        }
        res=2;
        for (int j=2;j<=n;j++)
            for (int i=1;i<=j-1;i++)
            res=max(res,f[i][j].sc);
        cout<<res<<"\n";
    }
    return 0;
}
