#include<bits/stdc++.h>
#define maxn 10
#define fs first
#define sc second
#define mod  111539786
using namespace std;
typedef pair<int,int> II;
int last[maxn],a[maxn],n,cnt;
int f[35][35][35][35][35],dd[50005],dxl[50005];
vector<int> e[maxn][35];
void inint(int x,int id)
{
    queue<II> q;
    while(!q.empty()) q.pop();
    q.push(II(x,1));
    while(!q.empty())
    {
        II m=q.front();
        q.pop();
        if (m.fs==0) continue;
        if (dxl[m.sc]) continue;
        dxl[m.sc]=1;
        if (dd[m.fs>>1]==0) dd[m.fs>>1]=++cnt;
        q.push(II(m.fs>>1,dd[m.fs>>1]));
        e[id][m.sc].push_back(dd[m.fs>>1]);
        if (m.fs%2==1)
        {
            if (dd[m.fs-1]==0) dd[m.fs-1]=++cnt;
            q.push(II(m.fs-1,dd[m.fs-1]));
            e[id][m.sc].push_back(dd[m.fs-1]);
        }
    }
}
int dfs(int a[maxn],int n)
{
    if (f[a[1]][a[2]][a[3]][a[4]][a[5]]!=0) return f[a[1]][a[2]][a[3]][a[4]][a[5]];
    int ok=0;
    for (int i=1; i<=n; i++)
        if (a[i]!=last[i])
        {
            ok=1;
            f[a[1]][a[2]][a[3]][a[4]][a[5]]=1;
            break;
        }
    if (!ok) return 1;
    int ans=0;
    for (int i=1; i<n; i++)
    {
        if (a[i]!=last[i]&&a[i+1]!=last[i+1])
        {
            int b[maxn];
            b[1]=a[1];
            b[2]=a[2];
            b[3]=a[3];
            b[4]=a[4];
            b[5]=a[5];
            b[i]=e[i][a[i]][0];
            b[i+1]=e[i+1][a[i+1]][0];
            ans=(ans+dfs(b,n))%mod;
            if ((int)e[i][a[i]].size()==1||(int)e[i+1][a[i+1]].size()==1) continue;
            b[1]=a[1];
            b[2]=a[2];
            b[3]=a[3];
            b[4]=a[4];
            b[5]=a[5];
            b[i]=e[i][a[i]][1];
            b[i+1]=e[i+1][a[i+1]][1];
            ans=(ans+dfs(b,n))%mod;
        }
    }
    if (a[1]!=last[1]&&a[n]!=last[n])
    {
        int b[maxn];
        b[1]=a[1];
        b[2]=a[2];
        b[3]=a[3];
        b[4]=a[4];
        b[5]=a[5];
        b[1]=e[1][a[1]][0];
        b[n]=e[n][a[n]][0];
        ans=(ans+dfs(b,n))%mod;
        if (e[1][a[1]].size()==2&&e[n][a[n]].size()==2)
        {
            {
                b[1]=a[1];
                b[2]=a[2];
                b[3]=a[3];
                b[4]=a[4];
                b[5]=a[5];
                b[1]=e[1][a[1]][1];
                b[n]=e[n][a[n]][1];
                ans=(ans+dfs(b,n))%mod;
            }
        }
    }
    f[a[1]][a[2]][a[3]][a[4]][a[5]]=ans;
    return ans;
}
int main()
{
    freopen("bocsoi.inp","r",stdin);
    //freopen("bocsoi.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        cnt=1;
        memset(dd,0,sizeof(dd));
        memset(dxl,0,sizeof(dxl));
        inint(a[i],i);
        last[i]=dd[0];
        a[i]=1;
    }
    dfs(a,n);
    cout<<f[a[1]][a[2]][a[3]][a[4]][a[5]];
    return 0;
}
