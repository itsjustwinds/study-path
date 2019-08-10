#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int a[maxn],n,m,f[maxn],dem,sum,ok,res[maxn],dd[maxn];
void dfs(int l)
{
        if (ok) return;
        if (m-l+1<sum) return;
        if (l==m+1)
        {
                memset(f,0,sizeof(f));
                for(int i=1;i<=m;++i)
                if (res[i])
                {
                        for (int j=i-a[res[i]]+1;j<=i;++j)
                                f[j]=res[i];
                }
                for (int i=1;i<=m;++i)
                        cout<<f[i]<<" ";
                cout<<"\n";
                ++dem;
                if (dem==1000)
                {
                        ok=1;
                }
                return;
        }
        if (l!=1)dfs(l+1);
        for (int i=1;i<=n;++i)
        if (!dd[i])
        {
                dd[i]=1;
                res[l+a[i]-1]=i;
                sum-=a[i];
                dfs(l+a[i]);
                if (ok) return;
                dd[i]=0;
                res[l+a[i]-1]=0;
                sum+=a[i];
        }
}
int main()
{
        freopen("HOUSES.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>m>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                sum+=a[i];
        }
        dfs(1);
}
