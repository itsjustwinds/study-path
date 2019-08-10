#include<bits/stdc++.h>
#define maxn 10005
#define ll long long
using namespace std;
int dd[maxn][maxn],a[10000005];
ll d[maxn],dem;
ll s,n,mod;
int main()
{
        freopen("FBCFIBO.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>mod>>s;
        int s1=1%mod,s2=2%mod;
        a[1]=s1;
        a[2]=s2;
        dd[s1][s2]=1;
        d[s1]++;
        d[s2]++;
        dem=2;
        while(1)
        {
                int s3=(s1+s2)%mod;
                s1=s2;
                s2=s3;
                d[s2]++;
                ++dem;
                a[dem]=s2;
                if (dd[s1][s2])
                {
                        break;
                }
                dd[s1][s2]=1;
        }
        ll k=n/dem;
        for (int i=0;i<mod;++i)
        d[i]*=k;
        if (1==mod)
        {
                d[0]--;
                d[1]++;
        }
        if (mod==2)
        {
                d[0]--;
                d[2]++;
        }
        for (int i=1;i<=n%dem;++i)
                d[a[i]]++;
        for (int i=0;i<=mod;++i)
        if (s<=d[i])
        {
                cout<<i;
                return 0;
        }
        else s-=d[i];
        return 0;
}
