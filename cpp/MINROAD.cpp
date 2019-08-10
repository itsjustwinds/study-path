#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
struct data
{
            int x,y;
};
data a[maxn],sum[maxn];
int n,res,x,y;
bool cmp(const data &a,const data &b)
{
            return a.x<b.x;
}
int main()
{
            freopen("MINROAD.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>x>>y;
            for (int i=1;i<=n;++i)
                        cin>>a[i].x>>a[i].y;
            sort(a+1,a+n+1,cmp);
            sum[n+1].x=-1000000000;
            sum[n+1].y=-1000000000;
            for (int i=1;i<=n;++i)
            {
                        sum[i]=sum[i-1];
                        if (a[i].y==1) sum[i].x++;
                        else sum[i].y++;
            }
            int l=0;
            res=1111111111;
            for (int r=1;r<=n;++r)
            {
                        while(sum[r].x-sum[l+1].x>=x&&sum[r].y-sum[l+1].y>=y)++l;
                        if (sum[r].x-sum[l].x>=x&&sum[r].y-sum[l].y>=y)res=min(res,a[r].x-a[l+1].x);
            }
           if (res!=1111111111) cout<<res;
           else cout<<-1;
            return 0;
}
