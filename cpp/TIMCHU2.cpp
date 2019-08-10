#include<bits/stdc++.h>
#define maxn 505
#define mod 1000000007
#define base 37
#define fs first
#define ll long long
#define sc second
using namespace std;
map <int,int> m[maxn][maxn];
map<int,int> :: iterator it1,it2;
char a[maxn][maxn];
int n,x,y,res;
int main()
{
            freopen("TIMCHU2.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1; i<=n; ++i)
                        for (int j=1; j<=n; ++j)
                                    cin>>a[i][j];
            int tmp1=0;
            for (int i=1;i<=n;++i)
            {
                        tmp1=(((ll)tmp1*base)%mod+a[1][i]-'A')%mod;
                        m[1][i][tmp1]=1;
            }
            int tmp2=0;
            for (int i=n;i>=1;--i)
            {
                        tmp2=(((ll)tmp2*base)%mod+a[i][n]-'A')%mod;
                        m[i][n][tmp2]=1;
            }
            if (tmp1==tmp2) ++res;
            for (int i=2;i<=n;++i)
            {
                        x=i;
                        y=n+1-x;
                        for (int j=1;j<=y;++j)
                        {
                                    for (it1=m[x-1][j].begin();it1!=m[x-1][j].end();it1++)
                                    {
                                                int tmp=it1->fs;
                                                tmp=(((ll)tmp*base)+a[x][j]-'A')%mod;
                                                int tmp2=it1->sc;
                                                m[x][j][tmp]+=tmp2;
                                    }
                                    for (it1=m[x][j-1].begin();it1!=m[x][j-1].end();it1++)
                                    {
                                                int tmp=it1->fs;
                                                tmp=(((ll)tmp*base)+a[x][j]-'A')%mod;
                                                int tmp2=it1->sc;
                                                m[x][j][tmp]+=tmp2;
                                    }
                        }
                        for (int j=n;j>=x;--j)
                        {
                                    vector<int> ax,ay;
                                    ax.clear();
                                    ay.clear();
                                    for (it1=m[j][y+1].begin();it1!=m[j][y+1].end();it1++)
                                    {
                                                int tmp=it1->fs;
                                                tmp=(((ll)tmp*base)+a[j][y]-'A')%mod;
                                                int tmp2=it1->sc;
                                                it2=m[j][y].find(tmp);
                                                if (j==x) res=(res+((ll)tmp2*it2->sc)%mod)%mod;
                                                ax.push_back(tmp2);
                                                ay.push_back(tmp);
                                    }
                                    for (it1=m[j+1][y].begin();it1!=m[j+1][y].end();it1++)
                                    {
                                                int tmp=it1->fs;
                                                tmp=(((ll)tmp*base)+a[j][y]-'A')%mod;
                                                int tmp2=it1->sc;
                                                it2=m[j][y].find(tmp);
                                                if (j==x) res=(res+((ll)tmp2*it2->sc)%mod)%mod;
                                                m[j][y][tmp]+=tmp2;
                                    }
                                    for (int k=0;k<ax.size();++k)
                                    {
                                                int tmp=ax[k];
                                                int tmp2=ay[k];
                                                m[j][y][ay[k]]+=ax[k];
                                    }
                        }
            }
            cout<<res;
            return 0;
}
