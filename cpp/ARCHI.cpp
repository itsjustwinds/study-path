#include<bits/stdc++.h>
#define maxn 1005
#define oo 100000000
using namespace std;
struct data
{
        int ux,uy,vx,by,ok;
};
vector<data >edge,col,row;
vector<int >e[maxn][maxn];
int n;
vector<data > vex;
void dfs(int Ux,int Uy)
{
        for (int i=0;i<e[Ux][Uy].size();++i)
        {
                if (edge[e[Ux][Uy][i]].ok==0) continue;
                int Vx=edge[e[Ux][Uy][i]].Vx;
                int Vy=edge[e[Ux][Uy][i]].Vy;
                edge[e[Ux][Uy][i]].ok=0;
                dfs(Vx,Vy);
                break;
        }
}
int main()
{
        freopen("ARCHI.inp","r",stdin);
        freopen("ARCHI.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                int Ux,Uy,Vx,Vy;
                cin>>Ux>>Uy>>Vx>>Vy;
                if (Ux-Vx!=0) row.push_back({Ux,Uy,Vx,Vy,1});
                else col.push_back({Ux,Uy,Vx,Vy,1});
                if (!dd[Ux][Uy]) vex.push_back({Ux,Uy,0,0,0});
                if (!dd[Vx][Vy]) vex.push_back({Vx,Vy,0,0,0});
                e[Ux][Uy].push_back(edge.size());
                edge.push_back({Ux,Uy,Vx,Vy,1});
                e[Vx][Vy].push_back(edge.size());
                edge.push_back({Vx,Vy,Ux,Uy,1});
                dd[Ux][Uy]=1;
                dd[Vx][Vy]=1;
        }
        for (int i=1;i<row.size();++i)
        {
                int Ux=row[i].Ux;
                int Uy=row[i].Uy;
                for (int j=0;j<col.size();++j)
        }
        while(1)
        {
                int Ux=-oo,Uy=-oo;
                int dem=oo;
                for (int i=0;i<vex.size();++i)
                {
                        int Vx=vex[i].Ux;
                        int Vy=vex[i].Uy;
                        int d=0;
                        for (int j=0;j<e[Vx][Vy].size();++j)
                        {
                                if (edge[e[Vx][Vy][j]].ok==1)++d;
                        }
                        if (d==0) continue;
                        if (d<dem)
                        {
                                dem=d;
                                Ux=Vx;Uy=Vy;
                        }
                }
                if (dem==oo) break;
                for (int i=0;i<e[Ux][Uy].size();++i)
                {
                        if (edge[e[Ux][Uy][i]].ok==0) continue;
                        edge[e[Ux][Uy][i]].ok=0;
                        dfs(edge[e[Ux][Uy][i]].Vx,edge[e[Ux][Uy][i]].Vy);
                }
                ++res;
        }
}
