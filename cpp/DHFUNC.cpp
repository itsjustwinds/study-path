#include<bits/stdc++.h>
#define maxn 505
#define ll unsigned long long
using namespace std;
ll f[maxn][maxn],g[maxn];
ll x,y,gcd[maxn][maxn];
ll alp,beta,mod,oo;
ll tich(ll x,ll y)
{
        //if((db)log10(x)+log10(y)<17) return (x*y)%mod;
        if (y==1) return x%mod;
        ll res=tich(x,y>>1);
        res=(res+res)%mod;
        if (y&1) res=(res+x)%mod;
        return res;
}
ll cal(ll x,ll y)
{
        if (x==0) return y;
        if (y==0) return x;
        if (f[x][y]!=oo) return f[x][y];
        f[x][y]=(tich(alp,cal(x-1,y))+tich(beta,cal(x,y-1))+g[gcd[x][y]])%mod;
        return f[x][y];
}
int main()
{
        freopen("DHFUNC.inp","r",stdin);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        for (int i=1;i<=500;++i)
                for (int j=1;j<=500;++j)
                gcd[i][j]=__gcd(i,j);
        oo=(1<<63)-1;
        while(test--)
        {
                //read(x);read(y);read(alp);read(beta);read(mod);
                cin>>x>>y>>alp>>beta>>mod;
                for (int i=0;i<=x;++i)
                        for (int j=0;j<=y;++j)
                        f[i][j]=oo;
                g[1]=g[2]=1;
                for (int i=3;i<=max(x,y);++i)
                        g[i]=(g[i-1]+g[i-2])%mod;
                cout<<cal(x,y)<<"\n";
        }
}
