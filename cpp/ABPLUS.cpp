#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
ll x[maxn],n,dda[maxn],ddb[maxn],a[maxn],b[maxn],na,nb,ZERO;
ll res;
int main()
{
        freopen("ABPLUS.inp","r",stdin);
        freopen("ABPLUS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; ++i)
                cin>>x[i];
        sort(x+1,x+n+1);
        for (int i=1; i<=n; ++i)
        {
                if (x[i]==0)++ZERO;
                if (x[i]>0)
                {
                        if (x[i]!=a[na]) a[++na]=x[i];
                        dda[x[i]]++;
                }
                if (x[i]<0)
                {
                        if (-x[i]!=b[nb]) b[++nb]=-x[i];
                        ddb[-x[i]]++;
                }
        }
        for (int i=1; i<=na; ++i)
        {
                for (int j=i; j<=na; ++j)
                {
                        if (i==j&&dda[a[i]]<=1) continue;
                        int t=a[i]+a[j];
                        if (dda[t]==0) continue;
                        if (i==j) res+=dda[a[i]]*(dda[a[i]]-1)*dda[t];
                        else res+=dda[a[i]]*dda[a[j]]*dda[t]*2;
                }
        }
        for (int i=1; i<=nb; ++i)
        {
                for (int j=i; j<=nb; ++j)
                {
                        if (i==j&&ddb[b[i]]<=1) continue;
                        int t=b[i]+b[j];
                        if (ddb[t]==0) continue;
                        if (i==j) res+=ddb[b[i]]*(ddb[b[i]]-1)*ddb[t];
                        else res+=ddb[b[i]]*ddb[b[j]]*ddb[t]*2;
                }
        }
        for (int i=1;i<=na;++i)
                for (int j=1;j<=nb;++j)
        {
                int t=a[i]-b[j];
                if (t==0) res+=dda[a[i]]*ddb[b[j]]*ZERO*2;
                if (t>0) res+=dda[a[i]]*ddb[b[j]]*dda[t]*2;
                if (t<0) res+=dda[a[i]]*ddb[b[j]]*ddb[-t]*2;
        }
        if (ZERO)
        {
                if (ZERO>2) res+=ZERO*(ZERO-1)*(ZERO-2);
                for (int i=1;i<=na;++i)
                res+=ZERO*(dda[a[i]]-1)*dda[a[i]];
                for (int i=1;i<=nb;++i)
                res+=ZERO*(ddb[b[i]]-1)*ddb[b[i]];
        }
        cout<<res;
}
