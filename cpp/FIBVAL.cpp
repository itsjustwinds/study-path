#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int u,v,f[maxn];
int res;
void solve()
{
        int len=v-u+1;
        if (len>=32)
        {
                res=(len/16)*16;
                return;
        }
        u%=16;
        if (u==0) u=16;
        v=u+len-1;
        for (int i=u+1;i<=v;++i)
        if (f[i]==f[i-1])
        {
                res=2;
                return;
        }
        res=-1;
}
int main()
{
        freopen("FIBVAL.inp","r",stdin);
        freopen("FIBVAL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        f[1]=1;f[2]=2;
        for (int i=3;i<maxn;++i)
                f[i]=(f[i-1]+f[i-2])%7;
        cin>>test;
        while(test--)
        {
                cin>>u>>v;
                solve();
                cout<<res<<"\n";
        }
}
