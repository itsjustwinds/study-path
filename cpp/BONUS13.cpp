#include<bits/stdc++.h>
#define maxn 10
#define ll long long
using namespace std;
int f[maxn][maxn],ddx[maxn][maxn],dd[maxn][maxn],k,tt,cx[10],cy[10],x[5],y[5];
ll res;
ll add(int dx,int dy)
{
        if (ddx[dx][dy]!=tt)
        {
                ddx[dx][dy]=tt;
                return f[dx][dy];
        }
        return 0;
}
bool check(int x,int y)
{
        if (x<=0||x>8||y<=0||y>8) return 0;
        return 1;
}
ll tuong(int x,int y)
{
        ll tmp=0;
        int dx=x;
        int dy=y;
        tmp+=add(x,y);
        while(1)
        {
                dx-=1;
                dy+=1;
                if (!check(dx,dy)) break;
                tmp+=add(dx,dy);
        }
        dx=x;
        dy=y;
        while(1)
        {
                dx+=1;
                dy+=1;
                if (!check(dx,dy)) break;
                tmp+=add(dx,dy);
        }
        dx=x;dy=y;
        while(1)
        {
                dx+=1;
                dy-=1;
                if (!check(dx,dy)) break;
                tmp+=add(dx,dy);
        }
        dx=x;dy=y;
        while(1)
        {
                dx-=1;
                dy-=1;
                if (!check(dx,dy)) break;
                tmp+=add(dx,dy);
        }
        return tmp;
}
ll xe(int x,int y)
{
        ll sum=0;
        sum+=add(x,y);
        for (int i=1; i<=8; ++i)
        {
                sum+=add(i,y);
                sum+=add(x,i);
        }
        return sum;
}
ll hau(int x,int y)
{
        ll tmp=xe(x,y)+tuong(x,y);
        tmp+=add(x,y);
        return tmp;
}
ll ma(int x,int y)
{
        ll tmp=0;
        tmp+=add(x,y);
        for (int i=1; i<=8; ++i)
        {
                int dx=x+cx[i];
                int dy=y+cy[i];
                if (!check(dx,dy)) continue;
                tmp+=add(dx,dy);
        }
        return tmp;
}
void ans()
{
        ++tt;
        ll sum=0;
        sum+=hau(x[1],y[1]);
        sum+=xe(x[2],y[2]);
        sum+=tuong(x[3],y[3]);
        sum+=ma(x[4],y[4]);
        res=max(res,sum);
}
void tinh(int k)
{
        for (int i=1; i<=8; ++i)
                for (int j=1; j<=8; j++)
                        if (!dd[i][j])
                        {
                                dd[i][j]=1;
                                x[k]=i;
                                y[k]=j;
                                if (k==4) ans();
                                else tinh(k+1);
                                dd[i][j]=0;
                        }
}
int main()
{
        freopen("BONUS13.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>k;
        cx[1]=-2;
        cy[1]=1;
        cx[2]=-1;
        cy[2]=2;
        cx[3]=1;
        cy[3]=2;
        cx[4]=2;
        cy[4]=1;
        cx[5]=2;
        cy[5]=-1;
        cx[6]=1;
        cy[6]=-2;
        cx[7]=-1;
        cy[7]=-2;
        cx[8]=-2;
        cy[8]=-1;
        for (int i=1; i<=k; ++i)
        {
                int u,v,c;
                cin>>u>>v>>c;
                f[u][v]=c;
        }
        tinh(1);
        cout<<res;
        return 0;
}
