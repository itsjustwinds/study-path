#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int f[maxn][maxn],n,m;
char s[maxn][maxn];
struct data
{
    int x,y;
};
vector<data> tmp;
bool check(int i,int j)
{
    if (i<1||i>n||j<1||j>m) return 0;
    if (s[i][j]=='#') return 0;
    return 1;
}
void answer()
{
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
            cout<<f[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    freopen("QUEENNB.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>s[i][j];
    for (int i=1; i<=n; ++i)
    {
        tmp.clear();
        int x=i,y=1;
        while(1)
        {
            if (!check(x,y))
            {
                if (tmp.size()!=0)
                {
                    int d=tmp.size();
                    for (int k=0; k<tmp.size(); ++k)
                    {
                        int u=tmp[k].x;
                        int v=tmp[k].y;
                        f[u][v]+=d;
                    }
                    tmp.clear();
                }
                if (x<1||x>n||y<1||y>m) break;
            }
            if (check(x,y)) tmp.push_back({x,y});
            y++;
        }
    }
    for (int j=1; j<=m; ++j)
    {
        int x=1,y=j;
        tmp.clear();
        while(1)
        {
            if (!check(x,y))
            {
                if (tmp.size()!=0)
                {
                    int d=tmp.size()-1;
                    for (int k=0; k<tmp.size(); ++k)
                    {
                        int u=tmp[k].x;
                        int v=tmp[k].y;
                        f[u][v]+=d;
                    }
                    tmp.clear();
                }
                if (x<1||x>n||y<1||y>m) break;
            }
            if (check(x,y)) tmp.push_back({x,y});
            x++;
        }
    }
    for (int i=2; i<=n+m; ++i)
    {
        int x,y;
        if (i<=n)
        {
            y=1;
            x=i-y;
        }
        else
        {
            x=n;
            y=i-x;
        }
        tmp.clear();
        while(1)
        {
            if (!check(x,y))
            {
                if (tmp.size()!=0)
                {
                    int d=tmp.size()-1;
                    for (int k=0; k<tmp.size(); ++k)
                    {
                        int u=tmp[k].x;
                        int v=tmp[k].y;
                        f[u][v]+=d;
                    }
                    tmp.clear();
                }
                if (x<1||x>n||y<1||y>m) break;
            }
            if (check(x,y)) tmp.push_back({x,y});
            x--;
            y++;
        }
    }
    for (int i=1; i<=n; ++i)
    {
        int x=i,y=m;
        tmp.clear();
        while(1)
        {
            if (!check(x,y))
            {
                if (tmp.size()!=0)
                {
                    int d=tmp.size()-1;
                    for (int k=0; k<tmp.size(); ++k)
                    {
                        int u=tmp[k].x;
                        int v=tmp[k].y;
                        f[u][v]+=d;
                    }
                    tmp.clear();
                }
                if (x<1||x>n||y<1||y>m) break;
            }
            if (check(x,y)) tmp.push_back({x,y});
            x--;
            y--;
        }
    }
    for (int j=1; j<m; ++j)
    {
        int x=n,y=j;
        tmp.clear();
        while(1)
        {
            if (!check(x,y))
            {
                if (tmp.size()!=0)
                {
                    int d=tmp.size()-1;
                    for (int k=0; k<tmp.size(); ++k)
                    {
                        int u=tmp[k].x;
                        int v=tmp[k].y;
                        f[u][v]+=d;
                    }
                    tmp.clear();
                }
                if (x<1||x>n||y<1||y>m) break;
            }
            if (check(x,y)) tmp.push_back({x,y});
            x--;
            y--;
        }
    }
    answer();
}
