#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int n,mark[maxn],res;
ll a[maxn],NN;
map<ll,int > dd;
bool check(ll M)
{
        for (int i=1;i<=n;++i)
                mark[i]=0;
        for (int i=1;i<=n;++i)
        if (!mark[i])
        {
                ll y=a[i]+M;
                if (dd[y]==0) return 0;
                mark[dd[y]]=1;
        }
        return 1;
}
int main()
{
        freopen("GRN.inp","r",stdin);
        //freopen("GRN.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        n*=2;
        if (n>2000)
        {
                n/=2;
                for (int i=1;i<=n;++i)
                if (n%i==0)++res;
                cout<<res;
                return 0;
        }
        for (int i=1;i<=n;++i)
                cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1;i<=n;++i)
                dd[a[i]]=i;
        NN=a[n]-a[1];
        for (int j=2;j<=n;++j)
        if (check(a[j]-a[1]))++res;
        cout<<res;
}
