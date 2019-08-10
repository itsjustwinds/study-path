#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int dd[maxn],a,b;
int main()
{
        freopen("PNUMBER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>a>>b;
        for (int i=2;i*i<maxn;++i)
        if (!dd[i])
        {
                for (int j=i*i;j<maxn;j+=i)
                        dd[j]=1;
        }
        for (int i=max(2,a);i<=b;++i)
        if (!dd[i]) cout<<i<<"\n";
}
