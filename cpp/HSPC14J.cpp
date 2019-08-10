#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,dd[maxn];
int main()
{
        freopen("HSPC14J.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        while(cin>>n>>m)
        {
                int k=0;
                int ok=0;
                for (int i=2;i<=n;++i)
                        dd[i]=0;
                for (int i=2;i<=n;++i)
                if (!dd[i])
                {
                        for (int j=i;j<=n;j+=i)
                        {
                                if (!dd[j]) ++k;
                                if (k==m)
                                {
                                        ok=1;
                                        cout<<j<<"\n";
                                        break;
                                }
                                dd[j]=1;
                        }
                        if (ok) break;
                }
        }
}
