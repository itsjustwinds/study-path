#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
vector<int > us[maxn];
long long res;
int n,a[maxn],dd[maxn],d[maxn];
bool cmp(int a,int b)
{
        return a>b;
}
int main()
{
        freopen("SMS.inp","r",stdin);
        scanf("%d",&n);
        int maxx=0;
        for (int i=1; i<=n; ++i)
        {
                scanf("%d",&a[i]);
                maxx=max(maxx,a[i]);
        }
        sort(a+1,a+n+1,cmp);
        int cnt=0;
        for (int i=1;i<=n;++i)
        if (a[i]!=d[cnt]) d[++cnt]=a[i];
        for (int i=1; i*i<=maxx; ++i)
        {
                for (int j=1; j<=cnt; ++j)
                        if (d[j]%i==0)
                        {
                                us[d[j]].push_back(i);
                                if (i*i!=d[j])us[a[j]].push_back(d[j]/i);
                        }
        }
        for (int i=1; i<=n; ++i)
        {
                sort(us[a[i]].begin(),us[a[i]].end(),cmp);
                int ok=0;
                for (int j=0; j<us[a[i]].size(); ++j)
                {
                        int u=us[a[i]][j];
                        if (!ok&&dd[u])
                        {
                                ok=1;
                                res+=u;
                        }
                        dd[u]=1;
                }
        }
        printf("%lld",res);
        return 0;
}
