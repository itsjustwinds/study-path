#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,k,f[maxn],f2[maxn],maxx;
int main()
{
    //freopen("816b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>n>>k>>test;
    for (int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        f[u]++;
        f[v+1]--;
        maxx=max(maxx,v);
    }
    int tmp=0;
    for (int i=1;i<=maxx;i++)
        {
            tmp+=f[i];
            if (tmp>=k) f2[i]=f2[i-1]+1;
            else f2[i]=f2[i-1];
        }
    for (int i=maxx+1;i<=maxn;i++)
        f2[i]=f2[i-1];
    while(test--)
    {
        int u,v;
        cin>>u>>v;
        cout<<f2[v]-f2[u-1]<<"\n";
    }
    return 0;
}
