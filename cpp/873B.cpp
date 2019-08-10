#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int sum,dd[2*maxn],n;
int res;
int main()
{
        //freopen("873B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                char x;
                cin>>x;
                if (x=='1') ++sum;
                else --sum;
                if (sum==0) res=i;
                else
                {
                        if (dd[sum+maxn])res=max(res,i-dd[sum+maxn]);
                        if (!dd[sum+maxn]) dd[sum+maxn]=i;
                }
        }
        cout<<res;
        return 0;
}
