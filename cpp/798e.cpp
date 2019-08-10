#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
typedef pair<int,int> II;
int n,a[maxn],res[maxn],dd[maxn],pre[maxn],trc[maxn],l,r,cnt,dem;
priority_queue<int> q;
void dfs(int u,int check)
{
    if (!u) return;
    if (!check)
    {
        res[u]=r;
        r--;
        //dfs(trc[u],1);
    }
    else
    {
        cnt++;
        q.push(-u);
        dfs(trc[u],check);
    }
}
int main()
{
    freopen("798e.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    l=1,r=n;
    for (int i=1; i<=n; i++)
    {
        a[i]=i;
        cin>>a[i];
    }
    for (int i=1; i<=n; i++)
        if (a[i]!=-1)
        {
            pre[i]=a[i];
            trc[a[i]]=i;
        }
    for (int i=1; i<=n; i++)
        if (a[i]==-1)
            dfs(i,0);
    for (int i=1; i<=n; i++)
        if (a[i]==-1)
        {
            cnt=0;
            dfs(trc[i],1);
            for (int j=1;j<=cnt;j++)
            {
                int u=-q.top();
                q.pop();
                res[u]=l+j-1;
            }
            l+=cnt;
        }
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    return 0;
}
