#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
#define oo 10000000
using namespace std;
typedef pair<int,int> II;
int n,res,dd[maxn];
II a[maxn];
bool cmp(const II &a,const II &b)
{
    if (a.fs!=b.fs) return a.fs<b.fs;
    return a.sc<b.sc;
}
vector<int> e[maxn];
int find1(int l,int r,int x)
{
    if (l>r) return oo;
        int m=(l+r)/2;
        if (a[m].fs==x) return min(m,find1(l,m-1,x));
        if (a[m].fs<x) return find1(m+1,r,x);
        if (a[m].fs>x) return find1(l,m-1,x);
}
int find2(int l,int r,int x)
{
    if (l>r) return -oo;
    int m=(l+r)/2;
    if (a[m].fs==x) return max(m,find2(m+1,r,x));
    if (a[m].fs<x) return find2(m+1,r,x);
    if (a[m].fs>x) return find2(l,m-1,x);
}
void dfs(int i,int u,int d)
{
    if ((int)e[u].size()==0)
    {
        res=max(res,d);
        return;
    }
    dd[u]=1;
    for (int j=0;j<(int)e[u].size();j++)
    {
        int v=e[u][j];
        if (dd[v]==1) continue;
        dfs(i+1,v,d+1);
    }
    dd[u]=0;
}
int main()
{
    freopen("dominoes.inp","r",stdin);
    freopen("dominoes.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].fs>>a[i].sc;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        int x=find1(1,n,a[i].sc);
        int y=find2(1,n,a[i].sc);
        if (x==oo||y==-oo) continue;
        if (i>=x&&i<=y)
        {
            for (int j=x;j<=i-1;j++)
                e[i].push_back(j);
            for (int j=i+1;j<=y;j++)
                e[i].push_back(j);
        }
        else
        for (int j=x;j<=y;j++)
            e[i].push_back(j);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            dd[j]=0;
        dfs(2,i,1);
    }
    cout<<res;
    return 0;
}
