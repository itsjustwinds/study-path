#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll res;
int col[maxn],row[maxn];
struct data
{
        int x,y;
};
data a[maxn];
int n;
bool cmp(data a,data b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
int main()
{
        freopen("VOSRTRI.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].x>>a[i].y;
                row[a[i].x]++;
                col[a[i].y]++;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                int tmp1=row[a[i].x]-1;
                int tmp2=col[a[i].y]-1;
                res+=1ll*tmp1*tmp2;
        }
        cout<<res;
}
