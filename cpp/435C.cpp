#include<bits/stdc++.h>
using namespace std;
int x,sum,n;
int main()
{
        //freopen("435C.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>x;
        if (n==1)
        {
                cout<<"YES\n";
                cout<<x;
                return 0;
        }
        if (n==2)
        {
                if (x==0) cout<<"NO";
                else cout<<"YES\n"<<"0 "<<x;
                return 0;
        }
        cout<<"YES\n";
        for (int i=1;i<=n-3;++i)
                cout<<i<<" ",sum^=i;
        int a=(1<<18);
        int b=(1<<19);
        int res=x;
        res^=a;
        res^=b;
        res^=sum;
        cout<<a<<" "<<b<<" "<<res;
        return 0;
}
