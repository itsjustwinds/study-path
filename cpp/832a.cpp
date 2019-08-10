#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n,k;
int main()
{
            freopen("832a.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>k;
            ll tmp=n/k;
            if (tmp%2) cout<<"YES";
            else cout<<"NO";
            return 0;
}
