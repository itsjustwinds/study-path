#include<bits/stdc++.h>
#define fs first
#define sc second
#define oo 1e18+7
#define task "visitfj"
using namespace std;
const int dx[] = {0,0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
const int dy[] = {0,3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
int a[105][105],n,t;
long long d[1000000],res;
typedef pair<long long,int> II;
void dijks()
{
    priority_queue<II> q;
    d[0]=0;
    res=oo;
    q.push(II(0,0));
    while(!q.empty())
    {
        II tmp=q.top();
        int u=tmp.sc;
        int du=-tmp.fs;
        int x=u/n;
        int y=u%n;
        q.pop();
        if (du!=d[u]) continue;
        int dis=(n-x-1)+(n-y-1);
        if (dis<3)
        {
            res=min(res,(long long)du+dis*t);
            continue;
        }
        for (int i=1; i<=16; i++)
        {
            int r=x+dx[i];
            int c=y+dy[i];
            int k=a[r][c];
            int v= r * n + c;
            if (r<0||r>n-1||c<0||c>n-1)
                continue;
            if (d[u]+3*t+k<d[v])
            {
                d[v]=d[u]+3*t+k;
                q.push(II(-d[v],v));
            }
        }
    }
    cout<<res;
}
int main()
{
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            cin>>a[i][j];
            d[i*n+j]=oo;
        }
    dijks();
    return 0;
}

