#include <bits/stdc++.h>
using namespace std;
int n;
bool ngto(int n)
{
    if (n<2) return 0;
    for (int i=2; i<=int(sqrt(n)); i++)
        if (n%i==0) return 0;
    return 1;
}
int ssum(int n)
{
    int tmp=0;
    while (n!=0)
    {
        tmp+=n%10;
        n=n/10;
    }
    return tmp;
}
int sum(int n)
{
    int tmp=0;
    for (int i=2; i<=int(sqrt(n)); i++)
        if (ngto(i)==1)
        {
            while (n%i==0)
            {
                tmp+=i;
                n=n/i;
            }
            if (n==1) break;
        }
    return tmp;
}
bool check(int n)
{
    if (sum(n)==ssum(n)) return 1;
    return 0;
}
int main()
{
    //freopen("sdb.inp","r",stdin);
    //freopen("sdb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (check(n)==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
