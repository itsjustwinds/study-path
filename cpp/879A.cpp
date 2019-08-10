#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int s[maxn],d[maxn],n,res;
int main()
{
        //freopen("879A.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>s[i]>>d[i];
        for (int i=1;i<=n;++i)
        {
                while(s[i]<=res)
                        s[i]+=d[i];
                res=max(res,s[i]);
        }
        cout<<res;
}
