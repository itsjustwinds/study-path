#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m,res,c[maxn][maxn],dd[maxn][maxn];
set<int> s[maxn];
set<int> ::iterator it1,it2;
bool tinh()
{
            memset(dd,0,sizeof(dd));
            res=0;
            for (int i=1; i<=n; ++i)
                        for (int j=1; j<=n; ++j)
                                    if (i!=j&&c[i][j]==0)
                                    {
                                                it1=s[i].begin();
                                                it2=s[j].begin();
                                                for (;;)
                                                {
                                                            if (it1==s[i].end()) break;
                                                            if (it2==s[j].end()) break;
                                                            int tmp1=*it1;
                                                            int tmp2=*it2;
                                                            if (tmp1<tmp2)
                                                            {
                                                                        it1++;
                                                                        continue;
                                                            }
                                                            if (tmp1>tmp2)
                                                            {
                                                                        it2++;
                                                                        continue;
                                                            }
                                                            if (dd[i][tmp1]||dd[tmp1][j])
                                                            {
                                                                        it1++;
                                                                        it2++;
                                                                        continue;
                                                            }
                                                            ++res;
                                                            dd[i][j]=1;
                                                            dd[j][i]=1;
                                                            c[i][j]=1;
                                                            c[j][i]=1;
                                                            s[i].insert(j);
                                                            s[j].insert(i);
                                                            break;
                                                }
                                    }
            if (res) return 1;
            return 0;
}
int main()
{
            freopen("D:\\c++\\debug\\VOSNET.inp","r",stdin);
           // freopen("D:\\c++\\debug\\VOSNET.out","w",stdout);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>m;
            for (int i=1; i<=m; ++i)
            {
                        int u,v;
                        cin>>u>>v;
                        s[u].insert(v);
                        s[v].insert(u);
                        c[u][v]=1;
                        c[v][u]=1;
            }
            while(tinh())
            {
                        cout<<res<<" ";
            }
            cout<<0;
            return 0;
}
