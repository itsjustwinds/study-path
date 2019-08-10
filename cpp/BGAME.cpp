#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int f[20][maxn],n,cal[maxn],s,dd[maxn];
struct data
{
    int x,y;
};
bool cmpx(data a,data b)
{
    return a.x<b.x;
}
bool cmpy(data a,data b)
{
    return a.y<b.y;
}
data a[30];
void light(int &mask,int i)
{
    mask=mask|(1<<(i-1));
}
int tinh(vector<data > a)
{
    if (a.size()<2) return 0;
    data X;
    sort(a.begin(),a.end(),cmpx);
    X.x=a[a.size()/2].x;
    sort(a.begin(),a.end(),cmpy);
    X.y=a[a.size()/2].y;
    int res=0;
    for (int i=0;i<a.size();++i)
        res+=abs(a[i].x-X.x)+abs(a[i].y-X.y);
    return res;
}
void dfs(int i)
{
    if (i==n+1)
    {
        int mask=0;
        vector<data > e;
        e.clear();
        for (int i=1;i<=n;++i)
        if (dd[i])
        {
            light(mask,i);
            e.push_back(a[i]);
        }
        cal[mask]=tinh(e);
        return;
    }
    dfs(i+1);
    dd[i]=1;
    dfs(i+1);
    dd[i]=0;
}
int main()
{
    freopen("BGAME.inp","r",stdin);
    freopen("BGAME.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y;
    dfs(1);
    int M=(1<<n)-1;
    for (int i=0;i<=M;++i)
        for (int j=0;j<=s;++j)
        f[j][i]=1e9;
    f[0][0]=0;
    for (int j=1;j<=s;++j)
        for (int mask1=0;mask1<=M;mask1++)
    {
        if (f[j-1][mask1]==1e9) continue;
        for (int mask2=0;mask2<=M;++mask2)
        {
            if (mask1&mask2!=0) continue;
            f[j][mask1|mask2]=min(f[j][mask1|mask2],f[j-1][mask1]+cal[mask2]);
        }
    }
    cout<<f[s][M];
    return 0;
}
