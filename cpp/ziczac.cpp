#include <bits/stdc++.h>
using namespace std;
int x,y,n;
int main()
{
    //freopen("ziczac.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y;
    cin>>n;
    x=x+n/2;
    y=y+n/2;
    if (n%2==1)
    {
        x++;
        y++;
    }
    x-=n/2;
    cout<<x<<" "<<y;
    return 0;
}
