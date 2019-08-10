#include<bits/stdc++.h>
#define maxn 205
using namespace std;
struct data
{
    int x,y;
    string s;
};
int n,dd[maxn][maxn],ok;
data S,T,trc[maxn][maxn],d[10];
bool operator !=(data a,data b)
{
    return a.x!=b.x||a.y!=b.y;
}
bool operator ==(data a,data b)
{
    return a.x==b.x&&a.y==b.y;
}
void answer()
{
    vector<string > res;
    while(S!=T)
    {
        data tmp=trc[T.x][T.y];
        res.push_back(tmp.s);
        T=tmp;
    }
    cout<<res.size()<<"\n";
    for (int i=res.size()-1;i>=0;--i)
        cout<<res[i]<<" ";
}
bool check(int i,int j)
{
    return i>=1&&i<=n&&j>=1&&j<=n;
}
void bfs()
{
    queue<data > q;
    q.push(S);
    dd[S.x][S.y]=1;
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        if (x==1&&y==4)
        {
            int OK=1;
        }
        q.pop();
        for (int i=1;i<=6;++i)
        {
            int u=x+d[i].x;
            int v=y+d[i].y;
            if (!check(u,v)) continue;
            if (dd[u][v]) continue;
            dd[u][v]=1;
            trc[u][v]={x,y,d[i].s};
            if (u==T.x&&v==T.y)
            {
                ok=1;
                answer();
                return;
            }
            q.push({u,v});
        }
    }
}
int main()
{
    freopen("short.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d[1]={-2,-1,"UL"};
    d[2]={-2,1,"UR"};
    d[3]={0,2,"R"};
    d[4]={2,1,"LR"};
    d[5]={2,-1,"LL"};
    d[6]={0,-2,"L"};
    cin>>n;
    cin>>S.x>>S.y>>T.x>>T.y;
    S.x++;S.y++;
    T.x++;T.y++;
    if (S==T)
    {
        cout<<0;
        return 0;
    }
    bfs();
    if (!ok) cout<<"Impossible";
}
