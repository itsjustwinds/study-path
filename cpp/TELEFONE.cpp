#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n,d,a[maxn],dd[maxn],dem,res;
int main()
{
        freopen("TELEFONE.inp","r",stdin);
        freopen("TELEFONE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>d;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i];
                if (a[i]) dd[++dem]=i;
        }
        for (int i=1;i<dem;++i)
        {
                res+=(dd[i+1]-dd[i])/d;
        }
        cout<<res;
        return 0;
}
