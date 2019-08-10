#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int c[maxn][maxn],n,m,cnt,res;
vector<int> e[maxn];
void tinh()
{
            for (int i=1;i<=n;++i)
                        for (int j=0;j<e[i].size();++j)
            {
                        int v=e[i][j];
                        c[i][v]=cnt;
            }
            ++cnt;
            res=0;
            for (int u=1;u<=n;++u)
            {
                        for (int i=0;i<e[u].size();++i)
                        {
                                    int v=e[u][i];
                                    if (c[u][v]!=cnt-1) continue;
                                    for (int j=0;j<e[v].size();++j)
                                    {
                                                int x=e[v][j];
                                                if (x==u) continue;
                                                if (c[v][x]!=cnt-1) continue;
                                                if (c[u][x]!=-1) continue;
                                                ++res;
                                                c[u][x]=cnt;
                                                c[x][u]=cnt;
                                                e[u].push_back(x);
                                                e[x].push_back(u);
                                    }
                        }
            }
}
int main()
{
            freopen("D:\\c++\\debug\\VOSNET.inp","r",stdin);
            //freopen("D:\\c++\\debug\\VOSNET.ans","w",stdout);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            memset(c,-1,sizeof(c));
            for (int i=1;i<=m;++i)
            {
                        int x,y;
                        cin>>x>>y;
                        e[x].push_back(y);
                        e[y].push_back(x);
                        c[x][y]=0;
                        c[y][x]=0;
            }
            while(1)
            {
                        tinh();
                        if (res) cout<<res<<" ";
                        else break;
            }
            cout<<0;
            return 0;
}
