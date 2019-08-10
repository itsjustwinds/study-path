//PN
#include <bits/stdc++.h>

using namespace std;
typedef pair<long long,int> LI;
    int T,n,k;
    LI a[4000];
    vector<LI> g[60];
    int deg[60];
    char s[60];
void tao(long long mask,int len)
{
    if(len>50) return;
    int dem=0;
    if(len)
    {
        int sl=0;
        for(int i=0; i<len; ++i)
        {
            long long p=0;
            for(int j=i; j<len; ++j)
            {
                if(mask&(1LL<<j)) p+=(1LL<<(j-i));
                a[++sl]=LI(p,j-i+1);
            }
        }
        sort(a+1,a+sl+1);
        dem=1;
        for(int i=2; i<=sl; ++i) dem+=(a[i]!=a[i-1]);
        if(dem>50) return;
    }
    if(len){
        deg[len]++;
        g[len].push_back(LI(mask,dem));
    }
    tao(mask+(1LL<<len),len+1);
    tao(mask,len+1);
}
int main()
{
    freopen("luckfill.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    tao(0,0);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        cin>>s;
        long long m0=0,m1=0;
        for(int i=0; i<n; ++i)
        {
            if(s[i]=='?') m0+=(1LL<<i);
            else if(s[i]=='4') m1+=(1LL<<i);
        }
        int res=0;
        for(int i=0; i<deg[n]; ++i)
        {
            if(g[n][i].second>k) continue;
            long long t=g[n][i].first;
            t-=(t&m0);
            if(t==m1) ++res;
        }
        cout<<res<<"\n";
    }
}

