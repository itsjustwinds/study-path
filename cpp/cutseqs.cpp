#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll m,f[maxn],sum;
int a[maxn],n,now,ok;
int trc[maxn];
int main()
{
            freopen("CUTSEQS.inp","r",stdin);
            scanf("%d %lld",&n,&m);
            for (int i=1;i<=n;++i)
            {
                       scanf("%d",&a[i]);
                        if (a[i]>m) ok=1;
            }
            if (ok)
            {
                        cout<<-1;
                        return 0;
            }
            a[0]=1111111111;
            for (int i=1;i<=n;++i)
            {
                        trc[i]=i;
                       while(a[i]>=a[trc[i]-1]) trc[i]=trc[trc[i]-1];
            }
            now=1;
            for (int i=1;i<=n;++i)
                        f[i]=111111111111111111LL;
            for (int i=1;i<=n;++i)
            {
                        int maxx=0;
                        sum+=a[i];
                        while(sum>m) sum-=a[now++];
                        for (int j=i;j>=now;)
                        {
                                     maxx=a[j];
                                    int tmp=max(trc[j],now)-1;
                                    f[i]=min(f[i],f[tmp]+maxx);
                                    j=trc[j]-1;
                        }
            }
            printf("%lld",f[n]);
}
