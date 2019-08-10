#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
int n,a[10][maxn],M;
vector<int > e;
ll f[maxn][300];
int getbit(int n,int i)
{
        return (n>>(i-1))&1;
}
ll getval(int i,int sk)
{
        ll res=0;
        for (int j=1; j<=8; ++j)
        {
                int k=getbit(sk,j);
                if (k) res+=a[j][i];
        }
        return res;
}
int main()
{
        freopen("QBGAME.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        int maxx=-1e9;
        for (int i=1; i<=8; ++i)
                for (int j=1; j<=n; ++j)
                {
                        cin>>a[i][j];
                        maxx=max(maxx,a[i][j]);
                }
        if (maxx<0)
        {
                cout<<maxx;
                return 0;
        }
        M=(1<<8)-1;
        for (int i=0; i<=M; ++i)
        {
                if ((i&(i>>1))==0) e.push_back(i);
        }
        for(int i=0; i<=n; ++i)
                for (int j=0; j<e.size(); ++j)
                {
                        int x=e[j];
                        f[i][x]=-1e18;
                }
        f[0][0]=0;
        for (int i=1; i<=n; ++i)
        {
                for (int j=0; j<e.size(); ++j)
                {
                        int s1=e[j];
                        int ll sum=getval(i,s1);
                        for (int k=0; k<e.size(); ++k)
                        {
                                int s2=e[k];
                                if ((s1&s2)!=0) continue;
                                f[i][s1]=max(f[i][s1],f[i-1][s2]+sum);
                        }
                }
        }
        ll res=-1e18;
        for (int j=1; j<=n; ++j)
                for (int i=0; i<e.size(); ++i)
                {
                        int s=e[i];
                        res=max(res,f[j][s]);
                }
        cout<<res;
}
