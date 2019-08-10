#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int d,n,ok;
int main()
{
        freopen("HR22a.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                if (x%2!=0) d++;
                if (x%2==0) ok=1;
        }
        if (ok)
        {
                if (d%2==1) cout<<1;
                else cout<<0;
                return 0;
        }
        if (d>=2)
        {
                if (d%2==0) cout<<0;
                else cout<<1;
                return 0;
        }
        cout<<-1;
        return 0;

}
