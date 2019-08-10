#include<bits/stdc++.h>
#define maxn 105
using namespace std;
struct data
{
        int x,y;
};
data neww[100005],now[100005];
int n,m,dneww,dnow,len,dx[5],dy[5];
char a[maxn][maxn],s[maxn];
bool go()
{
        dnow=0;
        dneww=0;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
        if (a[i][j]==s[1]) now[++dnow]={i,j};
        for (int i=2;i<=len;++i)
        {
                dneww=0;
                if (dnow==0)
                {
                        break;
                }
                for (int j=1;j<=dnow;++j)
                {
                        int x=now[j].x;
                        int y=now[j].y;
                        for (int k=1;k<=4;++k)
                        {
                                int u=x+dx[k];
                                int v=y+dy[k];
                                if (a[u][v]==s[i])
                                {
                                        neww[++dneww]={u,v};
                                }
                        }
                }
                dnow=dneww;
                for (int j=1;j<=dneww;++j)
                        now[j]=neww[j];
        }
        return dnow!=0;
}
int main()
{
        freopen("hidden.inp","r",stdin);
        freopen("hidden.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        dx[1]=-1;dy[1]=0;
        dx[2]=0;dy[2]=1;
        dx[3]=1;dy[3]=0;
        dx[4]=0;dy[4]=-1;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                cin>>a[i][j];
        int test;
        cin>>test;
        while(test--)
        {
                cin>>(s+1);
                len=strlen(s+1);
                if (go()) cout<<"Yes\n";
                else cout<<"No\n";
        }
        return 0;
}
