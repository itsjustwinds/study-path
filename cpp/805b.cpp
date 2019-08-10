#include<bits/stdc++.h>
using namespace std;
int n,t1,t2;
int main()
{
    //freopen("805b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n==1)
    {
        cout<<"a";
        return 0;
    }
    t1=1;
    t2=2;
    cout<<"ab";
    for (int i=3;i<=n;i++)
    {
        if (t1==1)
        {
            t1=t2;
            t2=2;
            cout<<"b";
            continue;
        }
        if (t1==2)
        {
            t1=t2;
            t2=1;
            cout<<"a";
            continue;
        }
    }
    return 0;
}
