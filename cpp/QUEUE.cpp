#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int n;
long long res;
struct data
{
        int x,y;
};
data a[maxn];
int X,Y;
bool cmp1(data a,data b)
{
        return a.x<b.x;
}
bool cmp2(data a,data b)
{
        return a.y<b.y;
}
bool cmp(data a,data b)
{
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
void sub2()
{
        sort(a+1,a+n+1,cmp1);
        X=a[(n+1)/2].x;
        sort(a+1,a+n+1,cmp2);
        Y=a[(n+1)/2].y;
        for (int i=1;i*i<=n;++i)
        {
                if (n%i) continue;
                int j=n/i;
                //go(i,j);
        }
}
bool nt(int x)
{
        for (int i=2;i*i<=x;++i)
        if (x%i==0) return 0;
        return 1;
}
int dis(data a,data b)
{
        return abs(a.x-b.x)+abs(a.y-b.y);
}
void sub1()
{
        res=1e18;
        sort(a+1,a+n+1,cmp1);
        X=a[(n+1)/2].x;
        sort(a+1,a+n+1,cmp2);
        Y=a[(n+1)/2].y;
        sort(a+1,a+n+1,cmp1);
        int tX=X-n/2;
        long long tmp=0;
        for (int i=1;i<=n;++i)
        {
                tmp+=dis(a[i],{tX,Y});
                tX++;
        }
        res=min(res,tmp);
        tmp=0;
        sort(a+1,a+n+1,cmp2);
        int tY=Y-n/2;
        for (int i=1;i<=n;++i)
        {
                tmp+=dis(a[i],{X,tY});
                tY++;
        }
        res=min(res,tmp);
        cout<<res;
}
int main()
{
        freopen("QUEUE.inp","r",stdin);
        freopen("QUEUE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i].x>>a[i].y;
        if (nt(n)) sub1();
}
