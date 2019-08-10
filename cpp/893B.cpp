#include<bits/stdc++.h>
using namespace std;
int n,dd[1000000];
int main()
{
        //freopen("893B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        int k=1;
        while(1)
        {
                int x=((1<<k)-1)*(1<<(k-1));
                if (x>n) break;
                dd[x]=1;
                k++;
        }
        int res=1;
        for (int i=1;i*i<=n;++i)
        if (n%i==0)
        {
                if (dd[i]) res=max(res,i);
                if (dd[n/i]) res=max(res,n/i);
        }
        cout<<res;
        return 0;
}
