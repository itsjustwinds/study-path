#include <bits/stdc++.h>
using namespace std;
int a,b;
int DAO(int n)
{
    int m=n;
    int tmp=0;
    while (m!=0)
    {
        tmp=tmp*10+( m %10);
        m=m/10;
    }
    return tmp;
}
int UCLN(int c,int d)
{
    while (c!=d) if (c>d) c=c-d;
        else d=d-c;
    return c;
}
int main()
{
    freopen("sothanthien.inp","r",stdin);
    //freopen("sothanthien.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    int dem=0;
    for (int i=a; i<=b; i++) if (UCLN(DAO(i),i)==1) dem++;
    cout<<dem;
    return 0;
}
