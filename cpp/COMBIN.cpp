#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,res[50],dd[50];
ll c[50][50];
int main()
{
        freopen("COMBIN.inp","r",stdin);
        freopen("COMBIN.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k>>m;
        for (int i=0;i<=30;i++)
        {
                c[i][0]=0;
                c[0][i]=1;
        }
        for (int i=1;i<=30;++i)
                for (int j=i;j<=30;++j)
        {
                c[i][j]=c[i-1][j-1]+c[i][j-1];
        }
        for (int i=1;i<=k;i++)
        {
                int now=res[i-1]+1;
                while(m-c[k-i][n-now]>=0)
                {
                        m-=c[k-i][n-now];
                        now++;
                }
                res[i]=now;
                dd[res[i]]=1;
        }
        for (int i=1;i<=k;i++) cout<<res[i]<<" ";
        return 0;
}
