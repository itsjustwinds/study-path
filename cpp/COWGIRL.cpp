#include<bits/stdc++.h>
#define maxn 35
#define ll long long
using namespace std;
ll f[maxn][maxn],n,m,test,maxx;
int get(int x,int i)
{
        return (x>>(i-1))&1;
}
int main()
{
        freopen("COWGIRL.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>test;
        while(test--)
        {
                memset(f,0,sizeof(f));
                cin>>n>>m;
                if (n>m) swap(n,m);
                maxx=(1<<n)-1;
                //f[0][0]=1;
                for (int i=0;i<=maxx;++i)
                        f[1][i]=1;
                for(int i=1; i<=m; ++i)
                {
                        for (int x=0; x<=maxx; ++x)
                                for (int y=0; y<=maxx; ++y)
                                {
                                        if (!f[i-1][y]) continue;
                                        int ok=1;
                                        for (int j=1; j<n; ++j)
                                        {
                                                int tmp=0;
                                                tmp+=get(x,j);
                                                tmp+=get(x,j+1);
                                                tmp+=get(y,j);
                                                tmp+=get(y,j+1);
                                                if (tmp==0||tmp==4)
                                                {
                                                        ok=0;
                                                        break;
                                                }
                                        }
                                        if (!ok) continue;
                                        f[i][x]+=f[i-1][y];
                                }
                }
                ll res=0;
                for (int i=0; i<=maxx; ++i)
                        res+=f[m][i];
                cout<<res<<"\n";
        }
        return 0;
}
