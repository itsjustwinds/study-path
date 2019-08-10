#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,dd[5000000];
int main()
{
    //freopen("787a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    cin>>c>>d;
    for (int i=0;i<=1000;i++)
        dd[b+i*a]++;
    for (int i=0;i<=1000;i++)
        if (dd[d+i*c]!=0)
        {
            cout<<d+i*c;
            return 0;
        }
    cout<<-1;
    return 0;
}
