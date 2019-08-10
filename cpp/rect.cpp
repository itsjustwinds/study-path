#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
struct data
{
        int x,y;
};
data a[maxn][5];
int n,res,tmp,dd[maxn];
vector<int >e[maxn];
ll dt(data a,data b,data c)
{
        return abs(1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y));
}
void dfs(int u)
{
        dd[u]=1;
        ++tmp;
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i];
                if (dd[v]) continue;
                dfs(v);
        }
}
int main()
{
        freopen("RECT.inp","r",stdin);
        freopen("RECT.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                for (int j=1;j<=4;++j)
                        cin>>a[i][j].x>>a[i][j].y;
        }
        for (int i=1;i<=n;++i)
                for (int j=1;j<i;++j)
        {
                for (int h=1;h<=4;++h)
                {
                        data p1=a[j][1],p2=a[j][2],p3=a[j][3],p4=a[j][4];
                        data p=a[i][h];
                        ll sum=0;
                        ll S=0;
                        sum+=dt(p,p1,p2);
                        sum+=dt(p,p2,p3);
                        sum+=dt(p,p3,p4);
                        sum+=dt(p,p4,p1);
                        S+=dt(p1,p2,p3);
                        S+=dt(p1,p4,p3);
                        if (sum==S)
                        {
                                e[i].push_back(j);
                                e[j].push_back(i);
                                break;
                        }
                }
        }
        for (int i=1;i<=n;++i)
        if (!dd[i])
        {
                tmp=0;
                dfs(i);
                res=max(res,tmp);
        }
        cout<<res;
}
