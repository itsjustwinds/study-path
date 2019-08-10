#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int a[maxn],f[maxn],n,mod;
struct data
{
        int u,val;
};
struct cmp
{
        bool operator ()(data a,data b)
        {
                return a.val>b.val;
        }
};
void dijkstra()
{
        for (int i=1;i<=mod;++i)
                f[i]=1e9;
        priority_queue<data,vector<data>,cmp > q;
        while(!q.empty()) q.pop();
        f[0]=0;
        q.push({0,0});
        while(!q.empty())
        {
                int u=q.top().u;
                int val=q.top().val;
                q.pop();
                if (val!=f[u]) continue;
                for (int i=1;i<n;++i)
                {
                        int v=(u+a[i])%mod;
                        if (f[u]+1<f[v])
                        {
                                f[v]=f[u]+1;
                                q.push({v,f[v]});
                        }
                }
        }
}
int main()
{
        freopen("SUMS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        mod=a[n];
        dijkstra();
        int test;
        cin>>test;
        while(test--)
        {
                int x;
                cin>>x;
                x%=mod;
                if (f[x]==1e9)
                {
                        cout<<"NIE\n";
                }
                else cout<<"TAK\n";
        }
        return 0;
}
