#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
struct data
{
    int x,y;
};
data a[maxn];
bool cmp(data a,data b)
{
    return a.x<b.x;
}
int main()
{
    //freopen("900A.inp","r",stdin);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    if (a[2].x>=0)
    {
        cout<<"Yes";
        return 0;
    }
    if (a[n-1].x<=0)
    {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}
