#include <bits/stdc++.h>
using namespace std;
string a,b;
int n;
int main()
{
    freopen("776a.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    cin>>n;
    cout<<a<<" "<<b<<"\n";
    for (int i=1; i<=n; i++)
    {
        string a1,a2,a3,a4,t;
        cin>>a1>>a2;
        if (a1==a)
        {
            cout<<b<<" "<<a2<<"\n";
            a3=b;
            a4=a2;
        }
        if (a1==b)
        {
            cout<<a<<" "<<a2<<"\n";
            a3=a;
            a4=a2;
        }
        if (a2==a)
        {
            cout<<b<<" "<<a1<<"\n";
            a3=b;
            a4=a1;
        }
        if (a2==b)
        {
            cout<<a<<" "<<a1<<"\n";
            a3=a;
            a4=a1;
        }
        a=a3;
        b=a4;
    }
    return 0;
}
