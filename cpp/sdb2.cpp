#include <bits/stdc++.h>
using namespace std;
int n;
bool KT(int n)
{
    int t1=0;
    int t2=0;
    int a=n;
    int i=2;
    while (n != 1)
    {
        while ((n % i)==0)
        {
            n=n/i;
            t1=t1+i;
        }
        i=i+1;
    }
    while (a != 0)
    {
        t2=t2+(a % 10);
        a=a/10;
    }
    if (t1==t2) return 1;
    else return 0;
}
int main()
{
    //freopen("SODB.inp","r",stdin);
    //freopen("SODB.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=n; i<=10000; i++) if (KT(i)==1)
        {
            cout<<i<<" ";
        }
    return 0;
}
