#include<bits/stdc++.h>
#define maxn 2505
#define MAX 1000005
using namespace std;
int n,a[maxn],f[maxn][maxn],res,pos[4*MAX];
int main()
{
    //freopen("thseq.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n;
        res=0;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=0;i<=4*MAX;i++)
            pos[i]=-1;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                int tmp=pos[a[j]-a[i]+2*MAX];
                if (tmp>=0)
                {
                    f[i][j]=f[tmp][i]+1;
                }
                else f[i][j]=2;
                res=max(res,f[i][j]);
            }
            pos[a[i]+2*MAX]=i;
        }
        cout<<res<<"\n";
    }
    return 0;
}
