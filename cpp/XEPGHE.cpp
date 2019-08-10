#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct data
{
        int x,y;
};
data a[100005];
int n,bit[maxn][maxn],res;
bool cmp(const data &a,const data &b)
{
        return a.x+a.y<=b.x+b.y;
}
int gety(int x,int y)
{
        int res=0;
        while(y)
        {
                int tmp=bit[x][y];
                res=max(res,tmp);
                y-=y&(-y);
        }
        return res;
}
int get(int x,int y)
{
        int res=0;
        while(x)
        {
                int tmp=gety(x,y);
                res=max(res,tmp);
                x-=x&(-x);
        }
        return res;
}
void updatey(int x,int y,int val)
{
        while(y<=maxn)
        {
                bit[x][y]=max(bit[x][y],val);
                y+=y&(-y);
        }
}
void update(int x,int y,int val)
{
        while(x<=maxn)
        {
                updatey(x,y,val);
                x+=x&(-x);
        }
}
int main()
{
        freopen("XEPGHE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].y;
                //if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                int tmp=get(a[i].x,a[i].y);
                update(a[i].x,a[i].y,tmp+1);
                res=max(res,tmp+1);
        }
        cout<<res;
        return 0;
}
