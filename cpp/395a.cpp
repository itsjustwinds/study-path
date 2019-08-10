#include <bits/stdc++.h>
using namespace std;
int n,m,z;
int ucln(int a,int b)
{
    if(a%b==0) return b;
    return(ucln(b,a%b));
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m>>z;
    int res;
    res=z/(n*m/ucln(n,m));
    cout<<res;
    return 0;
}
