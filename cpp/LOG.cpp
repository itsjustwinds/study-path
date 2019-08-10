#include<bits/stdc++.h>
using namespace std;
int n,k,b;
double res;
int dib(int n,int b)
{
    return (static_cast<int>(floor(log(n)/log(b)))+1);
}
int main()
{
    freopen("log.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>b;
    if (n==0)
    {
        cout<<-1;
        return 0;
    }
    if (n==1&&k>1)
    {
        cout<<-1;
        return 0;
    }
    res=(k-1)*dib(b,n);
    if (res==(int)res) cout<<(int)res;
    else cout<<-1;
    return 0;
}
